//Gestion de la Trappe par le LDR /////////////////
void GestionTrappeLDR() {
  timerarduino = millis();
  int valeurLDR = analogRead(LDR);
  if (valeurLDR > V_LDRouv && (Etattrappe == 0 || Etattrappe == 1) && ModedemarcheOuv == 2 && MouvTrappe == 0 && Defautporte == 0) {
    if (TpsAvouverture == 0 && TpsAvouverturesec == 0) {
      TpsAvouverture = V_Hysteresis;
      previousTimer2 = timerarduino;
      TpsAvouverturesec = V_Hysteresis * 60;
      previousTimer3 = timerarduino;
    } else {
      if ((timerarduino - previousTimer2) > Timer2ON) {
        previousTimer2 = timerarduino;
        TpsAvouverture--;
      }
      if ((timerarduino - previousTimer3) > Timer3ON) {
        previousTimer3 = timerarduino;
        TpsAvouverturesec--;
      }
    }
    if (TpsAvouverturesec == 0) {
      DemEtattrappe = 2;
    }
  } else {
    TpsAvouverture = 0;
    TpsAvouverturesec = 0;
  }

  if (valeurLDR < V_LDRferm && (Etattrappe == 2 || Etattrappe == 1)  && ModedemarcheFerm == 2 && MouvTrappe == 0 && Defautporte == 0) {
    if (TpsAvfermeture == 0 && TpsAvfermeturesec == 0) {
      TpsAvfermeture = V_Hysteresis; previousTimer2 = timerarduino;
      TpsAvfermeturesec = V_Hysteresis * 60; previousTimer3 = timerarduino;
    }
    else {
      if ((timerarduino - previousTimer2) > Timer2ON) {
        previousTimer2 = timerarduino; TpsAvfermeture--;
      }
      if ((timerarduino - previousTimer3) > Timer3ON) {
        previousTimer3 = timerarduino; TpsAvfermeturesec--;
      }
    }
    if (TpsAvfermeturesec == 0 ) {
      DemEtattrappe = 0;
    }
  }
  else {
    TpsAvfermeture = 0;
    TpsAvfermeturesec = 0;
  }
}

//Gestion de la Trappe par Programmateur //////////
void GestionTrappeProg() {
  t = rtc.getTime();
  if (t.hour == V_HeureOuv && t.min == V_MinOuv && (t.sec > 0 && t.sec < 10) && ModedemarcheOuv == 1 && (Etattrappe == 0 || Etattrappe == 1) && MouvTrappe == 0  && Defautporte == 0) {
    DemEtattrappe = 2;
  }
  if (t.hour == V_HeureFerm && t.min == V_MinFerm && (t.sec > 0 && t.sec < 10) && ModedemarcheFerm == 1 && (Etattrappe == 2 || Etattrappe == 1) && MouvTrappe == 0  && Defautporte == 0) {
    DemEtattrappe = 0;
  }
}
