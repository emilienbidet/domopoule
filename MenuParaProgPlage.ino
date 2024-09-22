void LMenuParaProgPlage1()
{
    // Menu Plage horaire 1////////////////////
    switch (MenuParaProgPlage1)
    {
    case 0:
        break;
    case 1:
        lcd.clear();
        MenuParaProgPlage1++;
        break;
    case 2:
        lcd.setCursor(0, 0);
        lcd.print("- Plage horaire 1 --");
        lcd.setCursor(0, 1);
        lcd.print("Heure ouverture");
        lcd.setCursor(0, 2);
        lcd.print("Heure fermeture");
        lcd.setCursor(0, 3);
        lcd.print("Retour");
        MenuParaProgPlage1++;
        break;
    case 3:
        lcd.setCursor(19, 3);
        lcd.print(" ");
        lcd.setCursor(19, 1);
        lcd.print("<");
        lcd.setCursor(19, 2);
        lcd.print(" ");
        break;
    case 4:
        lcd.setCursor(19, 1);
        lcd.print(" ");
        lcd.setCursor(19, 2);
        lcd.print("<");
        lcd.setCursor(19, 3);
        lcd.print(" ");
        break;
    case 5:
        lcd.setCursor(19, 2);
        lcd.print(" ");
        lcd.setCursor(19, 3);
        lcd.print("<");
        lcd.setCursor(19, 1);
        lcd.print(" ");
        break;
    default:
        break;
    }
}

void LMenuParaProgPlage2()
{
    // Menu Plage horaire 2////////////////////
    switch (MenuParaProgPlage2)
    {
    case 0:
        break;
    case 1:
        lcd.clear();
        MenuParaProgPlage2++;
        break;
    case 2:
        lcd.setCursor(0, 0);
        lcd.print("- Plage horaire 2 --");
        lcd.setCursor(0, 1);
        lcd.print("Heure ouverture");
        lcd.setCursor(0, 2);
        lcd.print("Heure fermeture");
        lcd.setCursor(0, 3);
        lcd.print("Retour");
        MenuParaProgPlage2++;
        break;
    case 3:
        lcd.setCursor(19, 3);
        lcd.print(" ");
        lcd.setCursor(19, 1);
        lcd.print("<");
        lcd.setCursor(19, 2);
        lcd.print(" ");
        break;
    case 4:
        lcd.setCursor(19, 1);
        lcd.print(" ");
        lcd.setCursor(19, 2);
        lcd.print("<");
        lcd.setCursor(19, 3);
        lcd.print(" ");
        break;
    case 5:
        lcd.setCursor(19, 2);
        lcd.print(" ");
        lcd.setCursor(19, 3);
        lcd.print("<");
        lcd.setCursor(19, 1);
        lcd.print(" ");
        break;
    default:
        break;
    }
}