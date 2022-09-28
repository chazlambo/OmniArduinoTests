void full_pose_print() {
  Serial.println("Arm # \t Horz. \t Wrist \t Base \t Vert.");
  poseprintfun(arm1_pose, 0);
  poseprintfun(arm2_pose, 1);
  poseprintfun(arm3_pose, 2);
  poseprintfun(arm4_pose, 3);
  poseprintfun(arm5_pose, 4);

}

void poseprintfun(Adafruit_PCF8591 &pcf, int arm) {
  if (!pcf.begin(ADC_ADDRESS[arm])) {
    Serial.println("ARM ADC NOT FOUND");
    return;
  }
  Serial.print("Arm ");
  Serial.print(arm+1);
  pcf.analogWrite(255);
  delay(50);
  Serial.print("\t  ");
  Serial.print(pcf.analogRead(0));
  Serial.print("\t  ");
  Serial.print(pcf.analogRead(1));
  Serial.print("\t  ");
  Serial.print(pcf.analogRead(2));
  Serial.print("\t  ");
  Serial.println(pcf.analogRead(3));
  pcf.analogWrite(0);
  delay(50);
}
