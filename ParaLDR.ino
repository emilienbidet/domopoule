void LParaLDRouv() {
  //Menu parametrage LDR ouverture///////////////////
  switch (ParaLDRouv) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaLDRouv++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("-- LDR ouverture ---");
      ParaLDRouv++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat || Saisierapide) {
          sprintf(msg, "%-3d", V_LDRouv);
          lcd.setCursor(8, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(8, 2); lcd.print("   ");
        }
      }
      break;
    default:
      break;
  }
}

void LParaLDRferm() {
  //Menu parametrage LDR fermeture //////////////////
  switch (ParaLDRferm) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaLDRferm++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("-- LDR fermeture ---");
      ParaLDRferm++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino; Timer1Etat = !Timer1Etat;
        if (Timer1Etat || Saisierapide) {
          sprintf(msg, "%-3d", V_LDRferm);
          lcd.setCursor(8, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(8, 2); lcd.print("   ");
        }
      }
      break;
    default:
      break;
  }
}

void LParaLDRhysteresis() {
  //Menu parametrage LDR Hysteresis /////////////////
  switch (ParaLDRhysteresis) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaLDRhysteresis++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print ("-- LDR hysteresis --");
      lcd.setCursor(11, 2); lcd.print ("min");
      ParaLDRhysteresis++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat || Saisierapide) {
          sprintf(msg, "%3d", V_Hysteresis);
          lcd.setCursor(7, 2); lcd.print(msg); 
        }
        else {
          lcd.setCursor(7, 2); lcd.print("   ");
        }
      }
      break;
    default:
      break;
  }
}
