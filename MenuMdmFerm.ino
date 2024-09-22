void LMenuMdmFerm() {
  //Menu mode de marche//////////////////////////////
  switch (MenuMdmFerm) {
    case 0:
      break;
    case 1:
      lcd.clear(); MenuMdmFerm++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("-- Mode fermeture --");
      lcd.setCursor(0, 1); lcd.print("Programmateur");
      lcd.setCursor(0, 2); lcd.print("LDR");
      lcd.setCursor(0, 3); lcd.print("OFF");
      MenuMdmFerm++;
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
      MenuMdmFerm = 8;
      break;
    case 7:
      lcd.setCursor(0, 0); lcd.print("-- Mode fermeture --");
      lcd.setCursor(0, 1); lcd.print("Programmateur");
      lcd.setCursor(0, 2); lcd.print("LDR");
      lcd.setCursor(0, 3); lcd.print("Manuel");
      MenuMdmFerm = 5;
      break;
    case 8:
      lcd.clear();
      MenuMdmFerm++;
      break;
    case 9:
      lcd.setCursor(0, 0); lcd.print("-- Mode fermeture --");
      lcd.setCursor(0, 1); lcd.print("Retour");
      MenuMdmFerm = 11;
      break;
    case 10:
      MenuMdmFerm = 7;
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
