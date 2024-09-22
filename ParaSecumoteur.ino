void LParaSecumoteurTpsactiv() {
  //Menu systeme veille Tps av. activation //////////
  switch (ParaSecumoteurTpsactiv) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaSecumoteurTpsactiv++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print(" Tps av. Act Secu M.");
      lcd.setCursor(11, 2); lcd.print("sec");
      ParaSecumoteurTpsactiv++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat || Saisierapide) {
          sprintf(msg, "%3d", V_TpsSecuMoteur);
          lcd.setCursor(7, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(7, 2); lcd.print ("   ");
        }
      }
      break;
    default:
      break;
  }
}

void LParaSecumoteuretat() {
  //Menu systeme veille etat //////////////////
  switch (ParaSecumoteuretat) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaSecumoteuretat++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("--- Veille Etat ----");
      lcd.setCursor(0, 0); lcd.print("- Secu Moteur Etat -");
      ParaSecumoteuretat++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino; Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          if (Etatsecumoteur) {
            lcd.setCursor(6, 2); lcd.print(" Actif ");
          }
          else {
            lcd.setCursor(6, 2); lcd.print("Inactif");
          }
        }
        else {
          lcd.setCursor(6, 2); lcd.print("       ");
        }
      }
      break;
    default:
      break;
  }
}
