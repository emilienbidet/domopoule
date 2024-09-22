//Affichage de l'heure ////////////////////////////
void AffHeure() {
  t = rtc.getTime();
  if (Tsec != t.sec) {
    sprintf(msg, "%02d:%02d:%02d",t.hour,t.min,t.sec);
    lcd.setCursor(0, 0); lcd.print(msg);
    Tsec = t.sec;
  }
}
