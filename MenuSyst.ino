void LMenuSyst() {
  //Menu Systeme ////////////////////////////////////
  switch (MenuSyst) {
    case 0:
      break;
    case 1:
      lcd.clear(); MenuSyst++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("----- Systeme ------");
      lcd.setCursor(0, 1); lcd.print("Reglage heure");
      lcd.setCursor(0, 2); lcd.print("Gest. Veille");
      lcd.setCursor(0, 3); lcd.print("Retour");
      MenuSyst++;
      break;
    case 3:
      lcd.setCursor(19, 3); lcd.print(" ");
      lcd.setCursor(19, 1); lcd.print("<");
      lcd.setCursor(19, 2); lcd.print (" ");
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
    default:
      break;
  }
}
