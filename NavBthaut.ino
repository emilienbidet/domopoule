// Gestion Navigation Bouton HAUT ///////////////////
void NavBthaut()
{
  if (Menu > 0)
  {
    if (Menu == 3)
    {
      Menu = 8;
    }
    else
    {
      Menu--;
    }
  }
  if (MenuMdm > 0)
  {
    if (MenuMdm == 3)
    {
      MenuMdm = 5;
    }
    else
    {
      MenuMdm--;
    }
  }
  if (MenuMdmOuv > 0)
  {
    if (MenuMdmOuv == 3)
    {
      MenuMdmOuv = 8;
    }
    else
    {
      MenuMdmOuv--;
    }
  }
  if (MenuMdmFerm > 0)
  {
    if (MenuMdmFerm == 3)
    {
      MenuMdmFerm = 8;
    }
    else
    {
      MenuMdmFerm--;
    }
  }
  if (MenuPara > 0)
  {
    if (MenuPara == 3)
    {
      MenuPara = 8;
    }
    else
    {
      MenuPara--;
    }
  }

  if (MenuParaProg > 0)
  {
    if (MenuParaProg == 3)
    {
      MenuParaProg = 5;
    }
    else
    {
      MenuParaProg--;
    }
  }
  if (MenuParaLDR > 0)
  {
    if (MenuParaLDR == 3)
    {
      MenuParaLDR = 8;
    }
    else
    {
      MenuParaLDR--;
    }
  }
  if (MenuSyst > 0)
  {
    if (MenuSyst == 3)
    {
      MenuSyst = 5;
    }
    else
    {
      MenuSyst--;
    }
  }
  if (MenuSystVeille > 0)
  {
    if (MenuSystVeille == 3)
    {
      MenuSystVeille = 5;
    }
    else
    {
      MenuSystVeille--;
    }
  }
  if (MenuParaSecu > 0)
  {
    if (MenuParaSecu == 3)
    {
      MenuParaSecu = 5;
    }
    else
    {
      MenuParaSecu--;
    }
  }
  if (SystVeilleetat == 3)
  {
    Etatveille = !Etatveille;
  }
  if (SystVeilleTpsactiv == 3)
  {
    if (V_TpsAvveille > 179)
    {
      V_TpsAvveille = 3;
    }
    else
    {
      V_TpsAvveille++;
    }
  }
  if (ParaSecumoteurTpsactiv == 3)
  {
    if (V_TpsSecuMoteur > 29)
    {
      V_TpsSecuMoteur = 1;
    }
    else
    {
      V_TpsSecuMoteur++;
    }
  }
  if (ParaSecumoteuretat == 3)
  {
    Etatsecumoteur = !Etatsecumoteur;
  }
  if (ParaProgHouv == 3)
  {
    if (V_HeureOuv > 22)
    {
      V_HeureOuv = 0;
    }
    else
    {
      V_HeureOuv++;
    }
  }
  if (ParaProgHouv == 5)
  {
    if (V_MinOuv > 58)
    {
      V_MinOuv = 0;
    }
    else
    {
      V_MinOuv++;
    }
  }
  if (ParaProgHferm == 3)
  {
    if (V_HeureFerm > 22)
    {
      V_HeureFerm = 0;
    }
    else
    {
      V_HeureFerm++;
    }
  }
  if (ParaProgHferm == 5)
  {
    if (V_MinFerm > 58)
    {
      V_MinFerm = 0;
    }
    else
    {
      V_MinFerm++;
    }
  }
  if (ParaProgHouv2 == 3)
{
    if (V_HeureOuv2 > 22)
    {
        V_HeureOuv2 = 0;
    }
    else
    {
        V_HeureOuv2++;
    }
}
if (ParaProgHouv2 == 5)
{
    if (V_MinOuv2 > 58)
    {
        V_MinOuv2 = 0;
    }
    else
    {
        V_MinOuv2++;
    }
}
if (ParaProgHferm2 == 3)
{
    if (V_HeureFerm2 > 22)
    {
        V_HeureFerm2 = 0;
    }
    else
    {
        V_HeureFerm2++;
    }
}
if (ParaProgHferm2 == 5)
{
    if (V_MinFerm2 > 58)
    {
        V_MinFerm2 = 0;
    }
    else
    {
        V_MinFerm2++;
    }
}
  if (ParaLDRouv == 3)
  {
    if (V_LDRouv > 998)
    {
      V_LDRouv = 0;
    }
    else
    {
      V_LDRouv++;
    }
  }
  if (ParaLDRferm == 3)
  {
    if (V_LDRferm > 998)
    {
      V_LDRferm = 0;
    }
    else
    {
      V_LDRferm++;
    }
  }
  if (ParaLDRhysteresis == 3)
  {
    if (V_Hysteresis > 98)
    {
      V_Hysteresis = 0;
    }
    else
    {
      V_Hysteresis++;
    }
  }
  if (SystReglheure == 3)
  {
    if (V_Tsystheure > 22)
    {
      V_Tsystheure = 0;
    }
    else
    {
      V_Tsystheure++;
    }
  }
  if (SystReglheure == 5)
  {
    if (V_Tsystminute > 58)
    {
      V_Tsystminute = 0;
    }
    else
    {
      V_Tsystminute++;
    }
  }
  if (SystReglheure == 7)
  {
    if (V_Tsystseconde > 58)
    {
      V_Tsystseconde = 0;
    }
    else
    {
      V_Tsystseconde++;
    }
  }
  if (MenuParaProgPlage1 > 0)
  {
    if (MenuParaProgPlage1 == 3)
    {
      MenuParaProgPlage1 = 5;
    }
    else
    {
      MenuParaProgPlage1--;
    }
  }
  if (MenuParaProgPlage2 > 0)
  {
    if (MenuParaProgPlage2 == 3)
    {
      MenuParaProgPlage2 = 5;
    }
    else
    {
      MenuParaProgPlage2--;
    }
  }
}

// Gestion Navigation Bouton HAUT rapide ////////////
void NavBthautrapide()
{
  if ((timerarduino - previousTimer6) > Timer6ON)
  {
    if (ParaLDRouv == 3)
    {
      if (V_LDRouv > 988)
      {
        V_LDRouv = 0;
      }
      else
      {
        V_LDRouv = V_LDRouv + 10;
      }
    }
    if (ParaLDRferm == 3)
    {
      if (V_LDRferm > 988)
      {
        V_LDRferm = 0;
      }
      else
      {
        V_LDRferm = V_LDRferm + 10;
      }
    }
    if (ParaLDRhysteresis == 3)
    {
      if (V_Hysteresis > 988)
      {
        V_Hysteresis = 0;
      }
      else
      {
        V_Hysteresis = V_Hysteresis + 10;
      }
    }
    if (SystVeilleTpsactiv == 3)
    {
      if (V_TpsAvveille > 169)
      {
        V_TpsAvveille = 3;
      }
      else
      {
        V_TpsAvveille = V_TpsAvveille + 10;
      }
    }
    previousTimer6 = timerarduino;
  }
}
