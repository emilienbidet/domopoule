void LParaProgHferm() {
  //Menu parametrage Progr Heure fermeture///////////
  switch (ParaProgHferm) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaProgHferm++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("- Heure fermeture --");
      sprintf(msg, ":%02d", V_MinFerm);
      lcd.setCursor(9, 2); lcd.print(msg);
      ParaProgHferm++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_HeureFerm);
          lcd.setCursor(7, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(7, 2); lcd.print("  ");
        }
      }
      break;
    case 4:
      sprintf(msg, "%02d", V_HeureFerm);
      lcd.setCursor(7, 2); lcd.print(msg);
      ParaProgHferm++;
      break;
    case 5:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_MinFerm);
          lcd.setCursor(10, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(10, 2); lcd.print("  ");
        }
      }
      break;
    case 6:
      break;
    default:
      break;
  }
}

void LParaProgHouv() {
  //Menu parametrage Progr Heure ouverture///////////
  switch (ParaProgHouv) {
    case 0:
      break;
    case 1:
      lcd.clear(); ParaProgHouv++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("- Heure ouverture --");
      sprintf(msg, ":%02d", V_MinOuv);
      lcd.setCursor(9, 2); lcd.print(msg);
      ParaProgHouv++;
      break;
    case 3:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_HeureOuv);
          lcd.setCursor(7, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(7, 2); lcd.print("  ");
        }
      }
      break;
    case 4:
      sprintf(msg, "%02d", V_HeureOuv);
      lcd.setCursor(7, 2); lcd.print(msg);
      previousTimer1 = timerarduino;
      ParaProgHouv++;
      break;
    case 5:
      if ((timerarduino - previousTimer1) > Timer1ClSaisie) {
        previousTimer1 = timerarduino;
        Timer1Etat = !Timer1Etat;
        if (Timer1Etat) {
          sprintf(msg, "%02d", V_MinOuv);
          lcd.setCursor(10, 2); lcd.print(msg);
        }
        else {
          lcd.setCursor(10, 2); lcd.print("  ");
        }
      }
      break;
    default:
      break;
  }
}
