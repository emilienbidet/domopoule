
// DS1302 //////////////////////////////////////////
#include <DS1302.h>
DS1302 rtc(7, 6, 5);
Time t;
DS1302_RAM ramBuffer;

// L298N ///////////////////////////////////////////

// le numéro de la broche ou est branché la sortie IN1 du L298N
const int IN1 = 10;
// le numéro de la broche ou est branché la sortie IN2 du L298N
const int IN2 = 11;

// LCD I2C /////////////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Gestion des entrées /////////////////////////////
const int Bthaut = A1;   // Pin du Bouton fleche haut
const int Btbas = A2;    // Pin du Bouton fleche bas
const int Btselect = A3; // Pin du Bouton select
const int LDR = A0;      // Pin du LDR
const int fdchaut = 3;   // Pin du fin de course haut
const int fdcbas = 4;    // Pin du fin de course bas

// Gestion des timers //////////////////////////////
unsigned long timerarduino;
unsigned long previousTime = 0;
unsigned long previousTimer1 = 0;
int Timer1ClSaisie = 500; // Tps clignotement pendant saisie
bool Timer1Etat;
unsigned long previousTimer2 = 0;
unsigned long Timer2ON = 60000; // Utiliser pour decompte pour hysterisis
unsigned long previousTimer3 = 0;
int Timer3ON = 1000;              // Utiliser pour decompte pour hysterisis
unsigned long previousTimer4 = 0; // Utiliser pour la mise en veille
unsigned long previousTimer5 = 0;
int Timer5ON = 2000; // Utiliser pour la saisie rapide
unsigned long previousTimer6 = 0;
int Timer6ON = 500; // Utiliser pour bt marche manuel
int TpsAvouverture;
int TpsAvfermeture;
unsigned long TpsAvouverturesec;
unsigned long TpsAvfermeturesec;

unsigned long TimerDefautporte;
byte Defautporte;

// Variable Menu ///////////////////////////////////
byte Accueil = 1;        // Ecran Accueil
byte Menu;               // Menu Principal
byte MenuMdm;            // Menu Mode de Marche
byte MenuPara;           // Menu parametres
byte MenuParaProg;       // Menu parametres programmateur
byte ParaProgHouv;       // Menu parametrage Progr Heure ouverture
byte ParaProgHferm;      // Menu parametrage Progr Heure fermeture
byte MenuParaLDR;        // Menu parametres LDR
byte ParaLDRouv;         // Menu parametrage LDR ouverture
byte ParaLDRferm;        // Menu parametrage LDR fermeture
byte ParaLDRhysteresis;  // Menu parametrage LDR Hysteresis
byte MenuSyst;           // Menu systeme
byte MenuSystVeille;     // Menu systeme veille
byte SystVeilleetat;     // Menu systeme veille etat
byte SystVeilleTpsactiv; // Menu systeme veille tps activation
byte SystReglheure;      // Menu systeme Reglage Heure
byte MenuParaSecu;
byte MenuMdmOuv;
byte MenuMdmFerm;
byte ParaSecumoteurTpsactiv;
byte ParaSecumoteuretat;
byte MenuParaProgPlage1; // Menu parametres programmateur plage horaire 1
byte MenuParaProgPlage2; // Menu parametres programmateur plage horaire 2

// Variables programme/////////////////////////////
byte Tsec;
boolean EtatBtselect;
boolean EtatBthaut;
boolean EtatBtbas;
byte Etattrappe = 0;
byte DemEtattrappe = 1;
boolean MouvTrappe;
boolean Saisierapide;
boolean Etatsecumoteur;
boolean Pause;             // Permet de mettre en pause certain affichage temps que moteur activer
byte ModedemarcheOuv = 1;  // Defini mode de marche (1 = Progr, 2 = LDR, 3 = OFF)
byte ModedemarcheFerm = 1; // Defini mode de marche (1 = Progr, 2 = LDR, 3 = OFF)
byte V_MinOuv = 0;         // Stock valeur Minute pour Progr Minute ouverture
byte V_HeureOuv = 8;       // Stock valeur Heure pour Progr Heure ouverture
byte V_MinFerm = 0;        // Stock valeur Minute pour Progr Minute fermeture
byte V_HeureFerm = 9;      // Stock valeur Heure pour Progr Heure fermeture
byte V_MinOuv2 = 0;        // Stock valeur Minute pour Progr Minute ouverture 2
byte V_HeureOuv2 = 16;     // Stock valeur Heure pour Progr Heure ouverture 2
byte V_MinFerm2 = 0;       // Stock valeur Minute pour Progr Minute fermeture 2
byte V_HeureFerm2 = 17;    // Stock valeur Heure pour Progr Heure fermeture 2
int V_LDRouv = 800;        // Stock valeur LDR pour ouverture
int V_LDRferm = 700;       // Stock valeur LDR pour fermeture
int V_Hysteresis = 20;     // Stock valeur LDR pour Hysterisis
int V_Tsystheure;          // Stock la valeur dans systeme Reglage heure avant SAV
int V_Tsystminute;         // Stock la valeur dans systeme Reglage minute avant SAV
int V_Tsystseconde;        // Stock la valeur dans systeme Reglage seconde avant SAV
int Veille = 0;            // Ecran mise en veille
int V_TpsSecuMoteur;
boolean Etatveille = 0; // Stock etat de la veille (actif ou inactif)
int V_TpsAvveille = 5;  // Stock la valeur tps avant mise en veille en sec
int valeurLDR;

byte customChar1[] = {B00000, B00000, B00001, B00001, B00001, B10110, B11000, B10000};
byte customChar2[] = {B00000, B11000, B00100, B10100, B00110, B01000, B00100, B00100};
byte customChar3[] = {B01000, B00111, B00001, B00011, B00000, B00000, B00000, B00000};
byte customChar4[] = {B01000, B10000, B10000, B11000, B00000, B00000, B00000, B00000};

char msg[20];

unsigned long prevtimerarduino;
unsigned long timerarduino2;

void setup()
{
  Serial.begin(9600);
  // DS1302 //////////////////////////////////////////
  rtc.halt(false);
  // Réglez l'horloge en mode exécution et désactivez la protection en écriture
  rtc.writeProtect(true);
  rtc.setDOW(FRIDAY);       // Set Day-of-Week to FRIDAY
  rtc.setTime(9, 18, 0);    // Set the time to 12:00:00 (24hr format)
  rtc.setDate(23, 9, 2023); // Set the date to August 6th, 2010
  // LCD I2C /////////////////////////////////////////
  lcd.init();
  lcd.backlight();
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  // Declaration des entrées /////////////////////////
  pinMode(Bthaut, INPUT_PULLUP);
  pinMode(Btbas, INPUT_PULLUP);
  pinMode(Btselect, INPUT_PULLUP);
  pinMode(fdchaut, INPUT_PULLUP);
  pinMode(fdcbas, INPUT_PULLUP);

  // L298N ///////////////////////////////////////////
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Lecture et Récupération des valeurs de réglages dans RAM DS1302
  ramBuffer = rtc.readBuffer();
  Serial.println("Lecture de la RAM : ");
  for (int i = 0; i < 31; i++)
  {
    Serial.print(" ");
    Serial.print(ramBuffer.cell[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  LoadSav();
  // Intro ///////////////////////////////////////////
  Intro();
}

void loop()
{
  prevtimerarduino = timerarduino2;
  prevtimerarduino = millis() - prevtimerarduino;
  Serial.print("Tps de cycle :");
  Serial.print(prevtimerarduino);
  Serial.println("   ");
  timerarduino2 = millis();

  valeurLDR = analogRead(LDR);
  timerarduino = millis();
  LMenu();
  LAccueil();
  LMenuMdm();
  LMenuMdmOuv();
  LMenuMdmFerm();
  LMenuPara();
  LMenuParaLDR();
  LMenuParaProg();
  LMenuSyst();
  LMenuSystVeille();
  LParaLDRferm();
  LParaLDRhysteresis();
  ;
  LParaLDRouv();
  LParaProgHferm();
  LSystVeilleetat();
  LSystVeilleTpsactiv();
  LSystReglheure();
  LParaProgHouv();
  LMenuParaSecu();
  LParaSecumoteurTpsactiv();
  LParaSecumoteuretat();
  LMenuParaProgPlage1();
  LMenuParaProgPlage2();
  LParaProgHouv2();
  LParaProgHferm2();

  // Gestion des boutons /////////////////////////////
  if (digitalRead(Bthaut) == LOW && EtatBthaut == 0)
  {
    EtatBthaut = 1;
    if (Accueil == 0)
    {
      NavBthaut();
    }
  }
  if (digitalRead(Btbas) == LOW && EtatBtbas == 0)
  {
    EtatBtbas = 1;
    if (Accueil == 0)
    {
      NavBtbas();
    }
  }
  if (digitalRead(Btselect) == LOW && EtatBtselect == 0)
  {
    EtatBtselect = 1;
    navmenuboutonselect();
  }
  if (digitalRead(Bthaut) == LOW && EtatBthaut == 1)
  {
    if ((timerarduino - previousTimer5) > Timer5ON)
    {
      NavBthautrapide();
      Saisierapide = 1;
    }
  }
  if (digitalRead(Btbas) == LOW && EtatBtbas == 1)
  {
    if ((timerarduino - previousTimer5) > Timer5ON)
    {
      NavBtbasrapide();
      Saisierapide = 1;
    }
  }
  if (digitalRead(Bthaut) == HIGH && digitalRead(Btbas) == HIGH)
  {
    previousTimer5 = timerarduino;
    Saisierapide = 0;
  }
  if (digitalRead(Bthaut) == HIGH)
  {
    EtatBthaut = 0;
  }
  if (digitalRead(Btbas) == HIGH)
  {
    EtatBtbas = 0;
  }
  if (digitalRead(Btselect) == HIGH)
  {
    EtatBtselect = 0;
  }
  if (EtatBthaut == 1 && Accueil > 0 && digitalRead(fdchaut) == HIGH && Saisierapide == 1)
  {
    TimerDefautporte = timerarduino;
    Defautporte = 0;
    DemEtattrappe = 1;
    MouvTrappe = 1;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
  }
  if (EtatBtbas == 1 && Accueil > 0 && digitalRead(fdcbas) == HIGH && Saisierapide == 1)
  {
    TimerDefautporte = timerarduino;
    Defautporte = 0;
    DemEtattrappe = 1;
    MouvTrappe = 1;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
  }
  if ((EtatBtbas == 0 && EtatBthaut == 0) || (EtatBtbas == 1 && digitalRead(fdcbas) == LOW) || (EtatBthaut == 1 && digitalRead(fdchaut) == LOW))
  {
    MouvTrappe = 0;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
  }

  if (digitalRead(fdchaut) == LOW)
  {
    Etattrappe = 2;
  }
  if (digitalRead(fdcbas) == LOW)
  {
    Etattrappe = 0;
  }
  if (digitalRead(fdcbas) == HIGH && digitalRead(fdchaut) == HIGH)
  {
    Etattrappe = 1;
  }
  // Porte vers haut
  if ((DemEtattrappe == 2 && Etattrappe == 0 && Defautporte == 0) || (DemEtattrappe == 2 && Etattrappe == 1 && Defautporte == 0))
  {
    MouvTrappe = 1;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
  }

  if ((DemEtattrappe == 0 && Etattrappe == 2 && Defautporte == 0) || (DemEtattrappe == 0 && Etattrappe == 1 && Defautporte == 0))
  {
    MouvTrappe = 1;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
  }

  if (Defautporte == 1 || Defautporte == 2)
  {
    MouvTrappe = 0;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
  }
  Serial.print("DemEtattrappe :");
  Serial.print(DemEtattrappe);
  Serial.print("    ");
  Serial.print("Etattrappe :");
  Serial.print(Etattrappe);
  Serial.print("    ");
  Serial.print("MouvTrappe: ");
  Serial.print(MouvTrappe);
  Serial.print("    ");
  Serial.print("TpsAvouv: ");
  Serial.print(TpsAvouverture);
  Serial.print("    ");
  Serial.print("TpsAvouvsec: ");
  Serial.print(TpsAvouverturesec);
  Serial.print("    ");

  // Gestion defaut porte

  if (MouvTrappe == 0 || (MouvTrappe == 1 && EtatBtbas == 1) || (MouvTrappe == 1 && EtatBthaut == 1) && Etatsecumoteur == 0)
  {
    TimerDefautporte = timerarduino;
  }
  else
  {
    if ((timerarduino - TimerDefautporte) > (V_TpsSecuMoteur * 1000))
    {
      TimerDefautporte = timerarduino;
      if (DemEtattrappe == 2)
      {
        Defautporte = 1;
      }
      if (DemEtattrappe == 0)
      {
        Defautporte = 2;
      }
    }
  }
  Serial.print("Defautporte");
  Serial.print(Defautporte);
  Serial.print("    ");
}

// Chargement de la RAM DS1302 /////////////////////
void LoadSav()
{
  if (ramBuffer.cell[0] == 90)
  {
    V_HeureOuv = ramBuffer.cell[2];
    V_MinOuv = ramBuffer.cell[3];
    V_HeureFerm = ramBuffer.cell[4];
    V_MinFerm = ramBuffer.cell[5];
    byte V_1LDRouv = ramBuffer.cell[6];
    byte V_2LDRouv = ramBuffer.cell[7];
    byte V_1LDRferm = ramBuffer.cell[8];
    byte V_2LDRferm = ramBuffer.cell[9];
    byte V_1Hysteresis = ramBuffer.cell[10];
    byte V_2Hysteresis = ramBuffer.cell[11];
    Etattrappe = ramBuffer.cell[12];
    Etatveille = ramBuffer.cell[13];
    byte V_1V_TpsAvveille = ramBuffer.cell[14];
    byte V_2V_TpsAvveille = ramBuffer.cell[15];
    ModedemarcheOuv = ramBuffer.cell[16];
    ModedemarcheFerm = ramBuffer.cell[17];
    Etatsecumoteur = ramBuffer.cell[18];
    byte V_1V_TpsSecuMoteur = ramBuffer.cell[19];
    byte V_2V_TpsSecuMoteur = ramBuffer.cell[20];
    V_HeureOuv2 = ramBuffer.cell[21];
    V_MinOuv2 = ramBuffer.cell[22];
    V_HeureFerm2 = ramBuffer.cell[23];
    V_MinFerm2 = ramBuffer.cell[24];
    V_TpsSecuMoteur = word(V_2V_TpsSecuMoteur, V_1V_TpsSecuMoteur);
    V_LDRouv = word(V_2LDRouv, V_1LDRouv);
    V_LDRferm = word(V_2LDRferm, V_1LDRferm);
    V_Hysteresis = word(V_2Hysteresis, V_1Hysteresis);
    V_TpsAvveille = word(V_2V_TpsAvveille, V_1V_TpsAvveille);
  }
  else
  {
    V_HeureOuv = 0;
    V_MinOuv = 0;
    V_HeureFerm = 0;
    V_MinFerm = 0;
    byte V_1LDRouv = 0;
    byte V_2LDRouv = 0;
    byte V_1LDRferm = 0;
    byte V_2LDRferm = 0;
    byte V_1Hysteresis = 1;
    byte V_2Hysteresis = 1;
    Etattrappe = 0;
    Etatveille = 0;
    byte V_1V_TpsAvveille = 1;
    byte V_2V_TpsAvveille = 1;
    ModedemarcheOuv = 3;
    ModedemarcheFerm = 3;
    Etatsecumoteur = 0;
    byte V_1V_TpsSecuMoteur = 10;
    byte V_2V_TpsSecuMoteur = 10;
  }
}

void Intro()
{
  lcd.home();
  lcd.setCursor(1, 0);
  lcd.write(1);
  lcd.setCursor(2, 0);
  lcd.write(2);
  lcd.setCursor(1, 1);
  lcd.write(3);
  lcd.setCursor(2, 1);
  lcd.write(4);
  lcd.setCursor(6, 0);
  lcd.print("DomoPoule");
  lcd.setCursor(5, 1);
  lcd.print("Version.6");
  lcd.setCursor(0, 3);
  lcd.print("  www.robdomo.com   ");
  delay(2000);
}

// Sauvegarde sur RAM DS1302 ///////////////////////
void Sav()
{
  rtc.writeProtect(false);
  byte v_1LDRouverture = lowByte(V_LDRouv);
  byte v_2LDRouverture = highByte(V_LDRouv);
  byte v_1LDRfermeture = lowByte(V_LDRferm);
  byte v_2LDRfermeture = highByte(V_LDRferm);
  byte v_1LDRhysteresis = lowByte(V_Hysteresis);
  byte v_2LDRhysteresis = highByte(V_Hysteresis);
  byte v_1V_TpsAvveille = lowByte(V_TpsAvveille);
  byte v_2V_TpsAvveille = highByte(V_TpsAvveille);
  byte v_1V_TpsSecuMoteur = lowByte(V_TpsSecuMoteur);
  byte v_2V_TpsSecuMoteur = highByte(V_TpsSecuMoteur);
  ramBuffer.cell[0] = 90;
  ramBuffer.cell[2] = V_HeureOuv;
  ramBuffer.cell[3] = V_MinOuv;
  ramBuffer.cell[4] = V_HeureFerm;
  ramBuffer.cell[5] = V_MinFerm;
  ramBuffer.cell[6] = v_1LDRouverture;
  ramBuffer.cell[7] = v_2LDRouverture;
  ramBuffer.cell[8] = v_1LDRfermeture;
  ramBuffer.cell[9] = v_2LDRfermeture;
  ramBuffer.cell[10] = v_1LDRhysteresis;
  ramBuffer.cell[11] = v_2LDRhysteresis;
  ramBuffer.cell[12] = Etattrappe;
  ramBuffer.cell[13] = Etatveille;
  ramBuffer.cell[14] = v_1V_TpsAvveille;
  ramBuffer.cell[15] = v_2V_TpsAvveille;
  ramBuffer.cell[16] = ModedemarcheOuv;
  ramBuffer.cell[17] = ModedemarcheFerm;
  ramBuffer.cell[18] = Etatsecumoteur;
  ramBuffer.cell[19] = v_1V_TpsSecuMoteur;
  ramBuffer.cell[20] = v_2V_TpsSecuMoteur;
  ramBuffer.cell[21] = V_HeureOuv2;
  ramBuffer.cell[22] = V_MinOuv2;
  ramBuffer.cell[23] = V_HeureFerm2;
  ramBuffer.cell[24] = V_MinFerm2;

  rtc.writeBuffer(ramBuffer);
  ramBuffer = rtc.readBuffer();
  rtc.writeProtect(true);
  Serial.println("Sauvegarde sur RAM");
  for (int i = 0; i < 31; i++)
  {
    Serial.print(" ");
    Serial.print(ramBuffer.cell[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
}

// Sauvegarde Heures sur DS1302 ////////////////////
void SavHeure()
{
  rtc.writeProtect(false);
  rtc.setTime(V_Tsystheure, V_Tsystminute, V_Tsystseconde);
  delay(50);
  rtc.writeProtect(true);
}

// Gestion Mise en veille Ecran/////////////////////
void EcrVeille()
{
  if (((timerarduino - previousTimer4) > (V_TpsAvveille * 1000)) && Accueil == 3 && Etatveille == 1)
  {
    lcd.noBacklight();
    Veille = 1;
  }
  if (EtatBtselect == 1 || EtatBthaut == 1 || EtatBtbas == 1 || Accueil != 3)
  {
    lcd.backlight();
    previousTimer4 = timerarduino;
    Veille = 0;
  }
}
