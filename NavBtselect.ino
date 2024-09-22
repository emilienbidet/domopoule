// Gestion Navigation Bouton Select ////////////////
void navmenuboutonselect()
{
  if (Accueil > 0 && Veille == 0)
  {
    Accueil = 0;
    Menu = 1;
  }
  if (Menu == 3)
  {
    Menu = 0;
    MenuMdm = 1;
  }
  if (Menu == 4)
  {
    Menu = 0;
    MenuPara = 1;
  }
  if (Menu == 5)
  {
    MenuSyst = 1;
    Menu = 0;
  }
  if (Menu == 11)
  {
    Accueil = 1;
    Menu = 0;
  }
  if (MenuMdm == 3)
  {
    MenuMdm = 0;
    MenuMdmOuv = 1;
  }
  if (MenuMdm == 4)
  {
    MenuMdm = 0;
    MenuMdmFerm = 1;
  }
  if (MenuMdm == 5)
  {
    MenuMdm = 0;
    Menu = 1;
    Sav();
  }
  if (MenuMdmOuv == 3)
  {
    MenuMdmOuv = 0;
    MenuMdm = 1;
    ModedemarcheOuv = 1;
  }
  if (MenuMdmOuv == 4)
  {
    MenuMdmOuv = 0;
    MenuMdm = 1;
    ModedemarcheOuv = 2;
  }
  if (MenuMdmOuv == 5)
  {
    MenuMdmOuv = 0;
    MenuMdm = 1;
    ModedemarcheOuv = 3;
  }
  if (MenuMdmOuv == 11)
  {
    MenuMdmOuv = 0;
    MenuMdm = 1;
  }
  if (MenuMdmFerm == 3)
  {
    MenuMdmFerm = 0;
    MenuMdm = 1;
    ModedemarcheFerm = 1;
  }
  if (MenuMdmFerm == 4)
  {
    MenuMdmFerm = 0;
    MenuMdm = 1;
    ModedemarcheFerm = 2;
  }
  if (MenuMdmFerm == 5)
  {
    MenuMdmFerm = 0;
    MenuMdm = 1;
    ModedemarcheFerm = 3;
  }
  if (MenuMdmFerm == 11)
  {
    MenuMdmFerm = 0;
    MenuMdm = 1;
    ;
  }
  if (MenuPara == 11)
  {
    MenuPara = 0;
    Menu = 1;
  }
  if (MenuPara == 3)
  {
    MenuPara = 0;
    MenuParaProg = 1;
  }
  if (MenuPara == 4)
  {
    MenuPara = 0;
    MenuParaLDR = 1;
  }
  if (MenuPara == 5)
  {
    MenuPara = 0;
    MenuParaSecu = 1;
  }
  if (MenuParaLDR == 11)
  {
    MenuParaLDR = 0;
    MenuPara = 1;
  }
  if (MenuSyst == 3)
  {
    MenuSyst = 0;
    SystReglheure = 1;
  }
  if (MenuSyst == 4)
  {
    MenuSyst = 0;
    MenuSystVeille = 1;
  }
  if (MenuSyst == 5)
  {
    MenuSyst = 0;
    Menu = 1;
  }
  if (MenuSystVeille == 3)
  {
    MenuSystVeille = 0;
    SystVeilleetat = 1;
  }
  if (MenuSystVeille == 4)
  {
    MenuSystVeille = 0;
    SystVeilleTpsactiv = 1;
  }
  if (MenuSystVeille == 5)
  {
    MenuSystVeille = 0;
    MenuSyst = 1;
  }
  if (SystVeilleetat == 3)
  {
    SystVeilleetat = 0;
    MenuSystVeille = 1;
    Sav();
  }
  if (SystVeilleTpsactiv == 3)
  {
    SystVeilleTpsactiv = 0;
    MenuSystVeille = 1;
    Sav();
  }
  if (ParaSecumoteuretat == 3)
  {
    ParaSecumoteuretat = 0;
    MenuParaSecu = 1;
    Sav();
  }
  if (ParaSecumoteurTpsactiv == 3)
  {
    ParaSecumoteurTpsactiv = 0;
    MenuParaSecu = 1;
    Sav();
  }
  if (MenuParaProg == 3)
  {
    MenuParaProg = 0;
    MenuParaProgPlage1 = 1;
  }
  if (MenuParaProg == 4)
  {
    MenuParaProg = 0;
    MenuParaProgPlage2 = 1;
  }
  if (MenuParaProg == 5)
  {
    MenuParaProg = 0;
    MenuPara = 1;
  }
  if (MenuParaProgPlage1 == 3)
  {
    MenuParaProgPlage1 = 0;
    ParaProgHouv = 1;
  }
  if (MenuParaProgPlage1 == 4)
  {
    MenuParaProgPlage1 = 0;
    ParaProgHferm = 1;
  }
  if (MenuParaProgPlage1 == 5)
  {
    MenuParaProgPlage1 = 0;
    MenuParaProg = 1;
  }
  if (MenuParaProgPlage2 == 3)
  {
    MenuParaProgPlage2 = 0;
    ParaProgHouv2 = 1;
  }
  if (MenuParaProgPlage2 == 4)
  {
    MenuParaProgPlage2 = 0;
    ParaProgHferm2 = 1;
  }
  if (MenuParaProgPlage2 == 5)
  {
    MenuParaProgPlage2 = 0;
    MenuParaProg = 1;
  }
  if (ParaProgHouv == 3)
  {
    ParaProgHouv = 4;
  }
  if (ParaProgHouv == 5)
  {
    MenuParaProg = 1;
    ParaProgHouv = 0;
    Sav();
  }
  if (ParaProgHferm == 3)
  {
    ParaProgHferm = 4;
  }
  if (ParaProgHferm == 5)
  {
    MenuParaProg = 1;
    ParaProgHferm = 0;
    Sav();
  }
  if (MenuParaLDR == 3)
  {
    MenuParaLDR = 0;
    ParaLDRouv = 1;
  }
  if (MenuParaLDR == 4)
  {
    MenuParaLDR = 0;
    ParaLDRferm = 1;
  }
  if (MenuParaLDR == 5)
  {
    MenuParaLDR = 0;
    ParaLDRhysteresis = 1;
  }
  if (ParaLDRouv == 3)
  {
    MenuParaLDR = 1;
    ParaLDRouv = 0;
    Sav();
  }
  if (ParaLDRferm == 3)
  {
    MenuParaLDR = 1;
    ParaLDRferm = 0;
    Sav();
  }
  if (ParaLDRhysteresis == 3)
  {
    MenuParaLDR = 1;
    ParaLDRhysteresis = 0;
    Sav();
  }
  if (MenuParaSecu == 3)
  {
    ParaSecumoteuretat = 1;
    MenuParaSecu = 0;
  }
  if (MenuParaSecu == 4)
  {
    ParaSecumoteurTpsactiv = 1;
    MenuParaSecu = 0;
  }
  if (MenuParaSecu == 5)
  {
    MenuPara = 1;
    MenuParaSecu = 0;
  }
  if (SystReglheure == 3)
  {
    SystReglheure = 4;
  }
  if (SystReglheure == 5)
  {
    SystReglheure = 6;
  }
  if (SystReglheure == 7)
  {
    SavHeure();
    SystReglheure = 0;
    MenuSyst = 1;
  }
}
