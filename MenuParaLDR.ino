void LMenuParaLDR() {
  //Menu parametres LDR /////////////////////////////
  switch (MenuParaLDR) {
    case 0:
      break;
    case 1:
      lcd.clear(); MenuParaLDR++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("------- LDR --------");
      lcd.setCursor(0, 1); lcd.print("Valeur ouverture");
      lcd.setCursor(0, 2); lcd.print("Valeur fermeture");
      lcd.setCursor(0, 3); lcd.print("Hysteresis");
      MenuParaLDR++;
      break;
    case 3:
      lcd.setCursor(19, 3); lcd.print(" ");
      lcd.setCursor(19, 1); lcd.print("<");
      lcd.setCursor(19, 2); lcd.print(" ");
      break;
    case 4:
      lcd.setCursor(19, 1); lcd.print(" ");
      lcd.setCursor(19, 2); lcd.print("<");
      lcd.setCursor(19, 3); lcd.print(" ");
      break;
    case 5:
      lcd.setCursor(19, 2); lcd.print(" ");
      lcd.setCursor(19, 3); lcd.print("<");
      lcd.setCursor(19, 1); lcd.print(" ");
      break;
    case 6:
      lcd.clear();
      MenuParaLDR = 8;
      break;
    case 7:
      lcd.setCursor(0, 0); lcd.print("------- LDR --------");
      lcd.setCursor(0, 1); lcd.print("Valeur ouverture");
      lcd.setCursor(0, 2); lcd.print("Valeur fermeture");
      lcd.setCursor(0, 3); lcd.print("Hysteresis");
      MenuParaLDR = 5;
      break;
    case 8:
      lcd.clear();
      MenuParaLDR++;
      break;
    case 9:
      lcd.setCursor(0, 0); lcd.print("------- LDR --------");
      lcd.setCursor(0, 1); lcd.print("Retour");
      MenuParaLDR = 11;
      break;
    case 10:
      MenuParaLDR = 7;
      break;
    case 11:
      lcd.setCursor(19, 3); lcd.print(" ");
      lcd.setCursor(19, 1); lcd.print("<");
      lcd.setCursor(19, 2); lcd.print(" ");
      break;
    default:
      break;
  }
}
