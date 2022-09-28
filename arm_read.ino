void arm_read() {
  char buschar;
  char armchar;

  Serial.println("\nInput desired I2C Bus:");
  Serial.println("\t1 - Pose");
  Serial.println("\t2 - Temperature");

  while (Serial.available() < 2); {
  }
  buschar = Serial.read(); // Read input
  Serial.read();           // Buffer newline

  int busSwitch = buschar - '0';
  if (!(busSwitch == 1 || busSwitch == 2)) {
    Serial.println("\n\nERROR:");
    Serial.println("Input must be either 1 or 2.\n");
    arm_read();
  }

  Serial.println("\nInput desired Arm #:");
  Serial.println("\t1 - Arm 1");
  Serial.println("\t2 - Arm 2");
  Serial.println("\t3 - Arm 3");
  Serial.println("\t4 - Arm 4");
  Serial.println("\t5 - Arm 5");

  while (Serial.available() < 2); {
  }
  armchar = Serial.read();  // Read input
  Serial.read();             // Buffer newline

  int armSwitch = armchar - '0';
  if (!(armSwitch == 1 || armSwitch == 2 || armSwitch == 3 || armSwitch == 4 || armSwitch == 5)) {
    Serial.println("\n\nERROR:");
    Serial.println("Input must be either 1 or 2.\n");
    return;
  }

  Serial.println("Function starting soon.\n\nEnter any character during runtime to exit");

  readfun(busSwitch, armSwitch);
  return;
}

void readfun(int bus, int arm) {

  Serial.println();
  Serial.print("A");
  Serial.print(arm);
  Serial.print("-");
  if (bus == 1) {
    Serial.print("Pose");
  }
  else {
    Serial.print("Temp");
  }
  Serial.print("\t");
  Serial.print("Wrist");
  Serial.print("\t");
  Serial.print("Horz.");
  Serial.print("\t");
  Serial.print("Base");
  Serial.print("\t");
  Serial.println("Vert.");
  if (bus == 1) {
    switch (arm) {
      Serial.print("Reading values for arm ");
      Serial.println(arm);
      case 1:
        poseread(arm1_pose, arm);
        break;
      case 2:
        poseread(arm2_pose, arm);
        break;
      case 3:
        poseread(arm3_pose, arm);
        break;
      case 4:
        poseread(arm4_pose, arm);
        break;
      case 5:
        poseread(arm5_pose, arm);
        break;
    }// End switch
  }// end if
  else if (bus == 2) {
    Serial.println("CANT USE THIS WHILE ON ARDUINO UNO"); // DELETE FOR DUE
    // UNCOMMENT FOR DUE
    //      switch (arm) {
    //        case 1:
    //            tempread(arm1_temp);
    //            break;
    //        case 2:
    //            tempread(arm2_temp);
    //            break;
    //        case 3:
    //            tempread(arm3_temp);
    //            break;
    //        case 4:
    //            tempread(arm4_temp);
    //            break;
    //        case 5:
    //            tempread(arm5_temp);
    //            break;
    //      }// End switch
  } // end else if
  delay(100);
  Serial.read();
  Serial.read();
} // End function

void poseread(Adafruit_PCF8591 &pcf, int armnum) {
  if (!pcf.begin(ADC_ADDRESS[armnum-1])) {
    Serial.println("ARM ADC NOT FOUND");
    return;
  }
  while (Serial.available() == 0) {
    pcf.analogWrite(255);
    delay(200);
    Serial.print("\t");
    Serial.print(pcf.analogRead(0));
    Serial.print("\t");
    Serial.print(pcf.analogRead(1));
    Serial.print("\t");
    Serial.print(pcf.analogRead(2));
    Serial.print("\t");
    Serial.println(pcf.analogRead(3));
    pcf.analogWrite(0);
    delay(200);
  }
  
  return;
}
