// Gestion Navigation Bouton Bas ///////////////////
void NavBtbas()
{
  if (Menu > 0)
  {
    if (Menu > 10)
    {
      Menu = 1;
    }
    else
    {
      Menu++;
    }
  }
  if (MenuMdm > 0)
  {
    if (MenuMdm > 4)
    {
      MenuMdm = 3;
    }
    else
    {
      MenuMdm++;
    }
  }
  if (MenuPara > 0)
  {
    if (MenuPara > 10)
    {
      MenuPara = 1;
    }
    else
    {
      MenuPara++;
    }
  }
  if (MenuMdmOuv > 0)
  {
    if (MenuMdmOuv > 5)
    {
      MenuMdmOuv = 2;
    }
    else
    {
      MenuMdmOuv++;
    }
  }
  if (MenuMdmFerm > 0)
  {
    if (MenuMdmFerm > 5)
    {
      MenuMdmFerm = 2;
    }
    else
    {
      MenuMdmFerm++;
    }
  }
  if (MenuParaProg > 0)
  {
    if (MenuParaProg > 4)
    {
      MenuParaProg = 3;
    }
    else
    {
      MenuParaProg++;
    }
  }
  if (MenuParaLDR > 0)
  {
    if (MenuParaLDR > 10)
    {
      MenuParaLDR = 1;
    }
    else
    {
      MenuParaLDR++;
    }
  }
  if (MenuSyst > 0)
  {
    if (MenuSyst > 4)
    {
      MenuSyst = 2;
    }
    else
    {
      MenuSyst++;
    }
  }
  if (MenuSystVeille > 0)
  {
    if (MenuSystVeille > 4)
    {
      MenuSystVeille = 2;
    }
    else
    {
      MenuSystVeille++;
    }
  }

  if (MenuParaSecu > 0)
  {
    if (MenuParaSecu > 4)
    {
      MenuParaSecu = 2;
    }
    else
    {
      MenuParaSecu++;
    }
  }

  if (SystVeilleetat == 3)
  {
    Etatveille = !Etatveille;
  }
  if (SystVeilleTpsactiv == 3)
  {
    if (V_TpsAvveille < 4)
    {
      V_TpsAvveille = 180;
    }
    else
    {
      V_TpsAvveille--;
    }
  }
  if (ParaSecumoteuretat == 3)
  {
    Etatsecumoteur = !Etatsecumoteur;
  }
  if (ParaSecumoteurTpsactiv == 3)
  {
    if (V_TpsSecuMoteur < 1)
    {
      V_TpsSecuMoteur = 30;
    }
    else
    {
      V_TpsSecuMoteur--;
    }
  }

  if (ParaProgHouv == 3)
  {
    if (V_HeureOuv < 1)
    {
      V_HeureOuv = 23;
    }
    else
    {
      V_HeureOuv--;
    }
  }
  if (ParaProgHouv == 5)
  {
    if (V_MinOuv < 1)
    {
      V_MinOuv = 59;
    }
    else
    {
      V_MinOuv--;
    }
  }
  if (ParaProgHferm == 3)
  {
    if (V_HeureFerm < 1)
    {
      V_HeureFerm = 23;
    }
    else
    {
      V_HeureFerm--;
    }
  }
  if (ParaProgHferm == 5)
  {
    if (V_MinFerm < 1)
    {
      V_MinFerm = 59;
    }
    else
    {
      V_MinFerm--;
    }
  }
  if (ParaProgHouv2 == 3)
{
    if (V_HeureOuv2 < 1)
    {
        V_HeureOuv2 = 23;
    }
    else
    {
        V_HeureOuv2--;
    }
}
if (ParaProgHouv2 == 5)
{
    if (V_MinOuv2 < 1)
    {
        V_MinOuv2 = 59;
    }
    else
    {
        V_MinOuv2--;
    }
}
if (ParaProgHferm2 == 3)
{
    if (V_HeureFerm2 < 1)
    {
        V_HeureFerm2 = 23;
    }
    else
    {
        V_HeureFerm2--;
    }
}
if (ParaProgHferm2 == 5)
{
    if (V_MinFerm2 < 1)
    {
        V_MinFerm2 = 59;
    }
    else
    {
        V_MinFerm2--;
    }
}
  if (ParaLDRouv == 3)
  {
    if (V_LDRouv < 1)
    {
      V_LDRouv = 999;
    }
    else
    {
      V_LDRouv--;
    }
  }
  if (ParaLDRferm == 3)
  {
    if (V_LDRferm < 1)
    {
      V_LDRferm = 999;
    }
    else
    {
      V_LDRferm--;
    }
  }
  if (ParaLDRhysteresis == 3)
  {
    if (V_Hysteresis < 1)
    {
      V_Hysteresis = 99;
    }
    else
    {
      V_Hysteresis--;
    }
  }
  if (SystReglheure == 3)
  {
    if (V_Tsystheure < 1)
    {
      V_Tsystheure = 23;
    }
    else
    {
      V_Tsystheure--;
    }
  }
  if (SystReglheure == 5)
  {
    if (V_Tsystminute < 1)
    {
      V_Tsystminute = 59;
    }
    else
    {
      V_Tsystminute--;
    }
  }
  if (SystReglheure == 7)
  {
    if (V_Tsystseconde < 1)
    {
      V_Tsystseconde = 59;
    }
    else
    {
      V_Tsystseconde--;
    }
  }
  if (MenuParaProgPlage1 > 0)
  {
    if (MenuParaProgPlage1 > 4)
    {
      MenuParaProgPlage1 = 3;
    }
    else
    {
      MenuParaProgPlage1++;
    }
  }
  if (MenuParaProgPlage2 > 0)
  {
    if (MenuParaProgPlage2 > 4)
    {
      MenuParaProgPlage2 = 3;
    }
    else
    {
      MenuParaProgPlage2++;
    }
  }
}

// Gestion Navigation Bouton BAS rapide  ////////////
void NavBtbasrapide()
{
  if ((timerarduino - previousTimer6) > Timer6ON)
  {
    if (ParaLDRouv == 3)
    {
      if (V_LDRouv < 11)
      {
        V_LDRouv = 999;
      }
      else
      {
        V_LDRouv = V_LDRouv - 10;
      }
    }
    if (ParaLDRferm == 3)
    {
      if (V_LDRferm < 11)
      {
        V_LDRferm = 999;
      }
      else
      {
        V_LDRferm = V_LDRferm - 10;
      }
    }
    if (ParaLDRhysteresis == 3)
    {
      if (V_Hysteresis < 11)
      {
        V_Hysteresis = 999;
      }
      else
      {
        V_Hysteresis = V_Hysteresis - 10;
      }
    }
    if (SystVeilleTpsactiv == 3)
    {
      if (V_TpsAvveille < 14)
      {
        V_TpsAvveille = 180;
      }
      else
      {
        V_TpsAvveille = V_TpsAvveille - 10;
      }
    }
    previousTimer6 = timerarduino;
  }
}
