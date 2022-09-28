// Detects on user specified I2C bus and prints results to Serial Monitor.
// Uses Adafruit library

void i2c_detect() {
  char buschar;
  Serial.println("\nInput desired I2C Bus:");
  Serial.println("\t1 - Pose");
  Serial.println("\t2 - Temperature");

  while (Serial.available() < 2); {
  }
  buschar = Serial.read(); // Read input
  Serial.read();                // Buffer newline

  int busSwitch = buschar - '0';

  if (!(busSwitch == 1 || busSwitch == 2)) {
    Serial.println("\n\nERROR:");
    Serial.println("Input must be either 1 or 2.\n");
    return;
  }

  detectfun(busSwitch);
  return;
}


void detectfun(int bus_switch) {

  if (bus_switch == 1) { // For Position Bus
    detect(arm1_pose, ADC_ADDRESS[0]);
    detect(arm2_pose, ADC_ADDRESS[1]);
    detect(arm3_pose, ADC_ADDRESS[2]);
    detect(arm4_pose, ADC_ADDRESS[3]);
    detect(arm5_pose, ADC_ADDRESS[4]);
  }

  else if (bus_switch == 2) { // For Temperature Bus
    Serial.println("CANT USE THIS WHILE ON ARDUINO UNO");   //DELETE FOR DUE
    //UNCOMMENT FOR DUE    detect(arm1_temp, ADC_ADDRESS[0]);
    //UNCOMMENT FOR DUE    detect(arm1_temp, ADC_ADDRESS[1]);
    //UNCOMMENT FOR DUE    detect(arm1_temp, ADC_ADDRESS[2]);
    //UNCOMMENT FOR DUE    detect(arm1_temp, ADC_ADDRESS[3]);
    //UNCOMMENT FOR DUE    detect(arm1_temp, ADC_ADDRESS[4]);
  }
  else {
    Serial.println("ERROR:");
    Serial.println("detectfun function is being called with an invalid input");
    Serial.println("Valid inputs are: 0 (for pose bus) and 1 (for temp bus)");
  }

  return;
}

void detect(Adafruit_PCF8591 pcf, int address) {
  if (!pcf.begin(address)) {
    Serial.print("0x");
    Serial.print(address, HEX);
    Serial.println(" not found!");
    return;
  }
  Serial.print("0x");
  Serial.print(address, HEX);
  Serial.println(" found!");
  return;
}
