void LSystVeilleTpsactiv() {
  //Menu systeme veille Tps av. activation //////////
  switch (SystVeilleTpsactiv) {
    case 0:
      break;
    case 1:
      lcd.clear(); SystVeilleTpsactiv++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print(" Tps av. Act Veille ");
      lcd.setCursor(11, 2); lcd.print("sec");
      SystVeilleTpsactiv++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat || Saisierapide) {
          sprintf(msg, "%3d", V_TpsAvveille);
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

void LSystVeilleetat() {
  //Menu systeme veille etat //////////////////
  switch (SystVeilleetat) {
    case 0:
      break;
    case 1:
      lcd.clear(); SystVeilleetat++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("--- Veille Etat ----");
      SystVeilleetat++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino; Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          if (Etatveille) {
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
