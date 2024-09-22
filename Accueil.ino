void LAccueil() {
  //Ecran Accueil ///////////////////////////////////
  switch (Accueil) {
    case 0:
      break;
    case 1:
      lcd.clear();
      Accueil++;
      break;
    case 2:
      lcd.setCursor(0, 1);
      lcd.print("Trappe :");
      //(1 = Progr, 2 = LDR, 3 = OFF)
      if (ModedemarcheOuv == 1 && ModedemarcheFerm == 1) {
        AFFheureouvProg();
        AFFheurefermProg();
      } else if (ModedemarcheOuv == 1 && ModedemarcheFerm == 2) {
        AFFheureouvProg();
        AffVLDRferm();
      } else if (ModedemarcheOuv == 2 && ModedemarcheFerm == 1) {
        AffVLDRouv();
        AFFheurefermProg();
      } else if (ModedemarcheOuv == 2 && ModedemarcheFerm == 2) {
        AffVLDRouv();
        AffVLDRferm();
      } else if (ModedemarcheOuv == 1 && ModedemarcheFerm == 3) {
        AFFheureouvProg();
        AffOFFferm();
      } else if (ModedemarcheOuv == 3 && ModedemarcheFerm == 1) {
        AffOFFouv();
        AFFheurefermProg();
      } else if (ModedemarcheOuv == 2 && ModedemarcheFerm == 3) {
        AffVLDRouv();
        AffOFFferm();
      } else if (ModedemarcheOuv == 3 && ModedemarcheFerm == 2) {
        AffOFFouv();
        AffVLDRferm();
      } else if (ModedemarcheOuv == 3 && ModedemarcheFerm == 3) {
        AffOFFouv();
        AffOFFferm();
      }
      Accueil++;
      break;
    case 3:
      if (ModedemarcheOuv == 2 || ModedemarcheFerm == 2) {
        AffValeurLDR(valeurLDR);
        GestionTrappeLDR();
      }
      GestionTrappeProg();
      AffInfoTrappe();
      EcrVeille();
      AffHeure();
      break;
    default:
      break;
  }
}
void AFFheureouvProg() {
  lcd.setCursor(0, 2);
  lcd.print("Ouv: Prog");
  sprintf(msg, "%02d:%02d", V_HeureOuv, V_MinOuv);
  lcd.setCursor(2, 3);
  lcd.print(msg);
}

void AFFheurefermProg() {
  lcd.setCursor(10, 2);
  lcd.print("Ferm: Prog");
  sprintf(msg, "%02d:%02d", V_HeureFerm, V_MinFerm);
  lcd.setCursor(12, 3);
  lcd.print(msg);
}

void AffVLDRouv() {
  lcd.setCursor(0, 2);
  lcd.print("Ouv: LDR");
  sprintf(msg, ">%-3d", V_LDRouv);
  lcd.setCursor(2, 3);
  lcd.print(msg);
}

void AffVLDRferm() {
  lcd.setCursor(10, 2);
  lcd.print("Ferm: LDR");
  sprintf(msg, "<%-3d", V_LDRferm);
  lcd.setCursor(12, 3);
  lcd.print(msg);
}

void AffOFFouv() {
  lcd.setCursor(0, 2);
  lcd.print("Ouv: OFF");
}

void AffOFFferm() {
  lcd.setCursor(10, 2);
  lcd.print("Ferm: OFF");
}

//Affichage Valeur LDR ////////////////////////////
int AffValeurLDR(int valeurLDR) {
  sprintf(msg, "LDR:%4d", valeurLDR);
  lcd.setCursor(12, 0);
  lcd.print(msg);
}

void AffInfoTrappe() {
  if (TpsAvouverture > 1) {
    sprintf(msg, " %2d""m AvOuv.", TpsAvouverture);
    lcd.setCursor(9, 1); lcd.print(msg);
  }
  if (TpsAvouverturesec < 60 && TpsAvouverturesec != 0) {
    sprintf(msg, " %2d""s AvOuv.", TpsAvouverturesec);
    lcd.setCursor(9, 1); lcd.print(msg);
  }
  if (TpsAvfermeture > 1) {
    sprintf(msg, " %2d""m AvFer.", TpsAvfermeture);
    lcd.setCursor(9, 1); lcd.print(msg);
  }
  if (TpsAvfermeturesec < 60 && TpsAvfermeturesec != 0) {
    sprintf(msg, " %2d""s AvFer.", TpsAvfermeturesec);
    lcd.setCursor(9, 1); lcd.print(msg);
  }
  if (TpsAvouverture == 0 && TpsAvouverturesec == 0 && TpsAvfermeture == 0 && TpsAvfermeturesec == 0 && Etattrappe == 1 && Defautporte == 0) {
    lcd.setCursor(9, 1);
    lcd.print("            ");
  }
  if (Etattrappe == 2 && digitalRead(fdchaut) == LOW && TpsAvfermeture == 0 && TpsAvfermeturesec == 0 && MouvTrappe == 0 && Defautporte == 0) {
    lcd.setCursor(9, 1);
    lcd.print("  Ouverte  ");
  }
  if (Etattrappe == 0 && digitalRead(fdcbas) == LOW && TpsAvouverture == 0 && TpsAvouverturesec == 0 && MouvTrappe == 0 && Defautporte == 0) {
    lcd.setCursor(9, 1);
    lcd.print("  Fermer   ");
  }
  if(Defautporte == 1){
    lcd.setCursor(9, 1);
    lcd.print("Defaut Ouv.");
  }
  if(Defautporte == 2){
    lcd.setCursor(9, 1);
    lcd.print("Defaut Fer.");
  }
}
