void LMenuMdm() {
  //Menu mode de marche//////////////////////////////
  switch (MenuMdm) {
    case 0:
      break;
    case 1:
      lcd.clear(); MenuMdm++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("-- Mode de marche --");
      lcd.setCursor(0, 1); lcd.print("Ouverture");
      lcd.setCursor(0, 2); lcd.print("Fermeture");
      lcd.setCursor(0, 3); lcd.print("Retour");
      MenuMdm++;
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
    default:
      break;
  }
}
