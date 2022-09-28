void PrintMenu(void) {
  Serial.println("a = Address Scan\t--------- Scans for all connected I2C devices on pose bus and prints results.");
  Serial.println("b = Module Detect\t--------- Detects Adafruit ADC Modules at specified addresses.");
  Serial.println("c = LED Test\t\t--------- Blinks arm-top LED's until user input is entered.");
  Serial.println("d = Continuous Arm Read\t--------- Gives continuous readings for the 4 potentiometers on an arm.");
  Serial.println("e = Full Pose Print\t--------- Gives current readings for all potentiometers on all arms");
  Serial.println("\nz = Print Menu");
  return;
}
