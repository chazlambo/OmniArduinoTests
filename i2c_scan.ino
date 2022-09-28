// Scans for addresses on user specified I2C bus and prints results to Serial Monitor.

void i2c_scan() {
  char buschar;
  Serial.println("\nInput desired I2C Bus:");
  Serial.println("\t1 - Position");
  Serial.println("\t2 - Temperature");

  while (Serial.available() < 2); {
  }
  buschar = Serial.read();      // Read input
  Serial.read();                // Buffer newline

  int busSwitch = buschar - '0';
  
  if (!(busSwitch == 1 || busSwitch == 2)) {
    Serial.println("\n\nERROR:");
    Serial.println("Input must be either 1 or 2.\n");
    return;
  }

  scanfun(busSwitch);

  return;
}

void scanfun(int bus_switch)
{
  byte error, address;
  int nDevices;
  Serial.println("\nScanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmission to see if
    // a device did acknowledge to the address.

    if (bus_switch == 1) { // For Position Bus
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
    }


    else if (bus_switch == 2) { // For Temperature Bus
      Serial.println("CANT USE THIS WHILE ON ARDUINO UNO");   //DELETE FOR DUE
      break;                                                  //DELETE FOR DUE
      //UNCOMMENT FOR DUE      Wire1.beginTransmission(address);
      //UNCOMMENT FOR DUE      error = Wire1.endTransmission();
    }
    else {
      Serial.println("ERROR:");
      Serial.println("i2c_scan function is being called with an invalid input");
      Serial.println("Valid inputs are: 0 (for pose bus) and 1 (for temp bus)");
      return;
    }

    if (error == 0)
    {
      Serial.print("I2C device found at address: 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Done.\n");
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }

  else {
    Serial.print(nDevices);
    Serial.println(" I2C devices were found.\n");

  }
  return;
}
