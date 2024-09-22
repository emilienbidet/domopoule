void LSystReglheure() {
  //Menu systeme Reglage Heure //////////////////////
  switch (SystReglheure) {
    case 0:
      break;
    case 1:
      lcd.clear();
      V_Tsystheure = t.hour; V_Tsystminute = t.min; V_Tsystseconde = t.sec;
      SystReglheure++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("-- Heure systeme ---");
      sprintf(msg, ":%02d:%02d", V_Tsystminute, V_Tsystseconde);
      lcd.setCursor(8, 2); lcd.print(msg);
      SystReglheure++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_Tsystheure);
          lcd.setCursor(6, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(6, 2); lcd.print("  ");
        }
      }
      break;
    case 4:
      sprintf(msg, "%02d", V_Tsystheure);
      lcd.setCursor(6, 2); lcd.print(msg);
      SystReglheure++;
      break;
    case 5:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_Tsystminute);
          lcd.setCursor(9, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(9, 2); lcd.print("  ");
        }
      }
      break;
    case 6:
      sprintf(msg, "%02d", V_Tsystminute);
      lcd.setCursor(9, 2); lcd.print(msg);
      SystReglheure++;
      break;
    case 7:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_Tsystseconde);
          lcd.setCursor(12, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(12, 2); lcd.print("  ");
        }
      }
      break;
    default:
      break;
  }
}
