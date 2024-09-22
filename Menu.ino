void LMenu() {
  //Menu principal///////////////////////////////////
  switch (Menu) {
    case 0:
      break;
    case 1:
      lcd.clear(); Menu++;
      break;
    case 2:
      lcd.setCursor(0, 0); lcd.print("------- Menu -------");
      lcd.setCursor(0, 1); lcd.print("Mode de marche");
      lcd.setCursor(0, 2); lcd.print("Parametres");
      lcd.setCursor(0, 3); lcd.print("Systeme");
      Menu++;
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
      lcd.setCursor(19, 1);
      lcd.print (" ");
      break;
    case 6:
      lcd.clear(); Menu = 8;
      break;
    case 7:
      lcd.setCursor(0, 0); lcd.print("------- Menu -------");
      lcd.setCursor(0, 1); lcd.print("Mode de marche");
      lcd.setCursor(0, 2); lcd.print("Parametres");
      lcd.setCursor(0, 3); lcd.print("Systeme");
      Menu = 5;
      break;
    case 8:
      lcd.clear(); Menu++;
      break;
    case 9:
      lcd.setCursor(0, 0); lcd.print("------- Menu -------");
      lcd.setCursor(0, 1); lcd.print("Retour");
      Menu = 11;
      break;
    case 10:
      Menu = 7;
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
