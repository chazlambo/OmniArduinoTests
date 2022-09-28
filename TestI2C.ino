/****************************
   TestI2C
   A user friendly compilation of all useful functions used for the I2C buses
   and potentiometer readings for the Omnimagnet Project.

 ** PIN TABLE **
   FOR ARDUINO DUE:
   20   - Pose SDA  (SDA0)
   21   - Pose SCL  (SCL0)
   SDA1 - Temp SDA  (SDA1)
   SCL1 - Temp SCL  (SCL1)

   VERSION: 1.0
   Date: 11/24/2021
   
 * * Written by Charlie Lambert
 ****************************/

/****************************
 ** #defines and #includes **
 ****************************/
#include <Wire.h>               // Basic I2C Wire Library for Arduino
#include <Adafruit_PCF8591.h>   // Library for the ADC Modules
#include <SimpleKalmanFilter.h> // Kalman Filter for Potentiometer Readings

#define ADC_REFERENCE_VOLTAGE 5.0 // System runs off of 5 volts.

/***********************
 ** Global Variables ***
 ***********************/
// Initialize ADC Modules
const int ADC_ADDRESS[5] = {0x48, 0x49, 0x4C, 0x4D, 0x4F};
Adafruit_PCF8591 arm1_pose = Adafruit_PCF8591();
Adafruit_PCF8591 arm2_pose = Adafruit_PCF8591();
Adafruit_PCF8591 arm3_pose = Adafruit_PCF8591();
Adafruit_PCF8591 arm4_pose = Adafruit_PCF8591();
Adafruit_PCF8591 arm5_pose = Adafruit_PCF8591();

//UNCOMMENT FOR DUE  Adafruit_PCF8591 arm1_temp = Adafruit_PCF8591();
//UNCOMMENT FOR DUE  Adafruit_PCF8591 arm2_temp = Adafruit_PCF8591();
//UNCOMMENT FOR DUE  Adafruit_PCF8591 arm3_temp = Adafruit_PCF8591();
//UNCOMMENT FOR DUE  Adafruit_PCF8591 arm4_temp = Adafruit_PCF8591();
//UNCOMMENT FOR DUE  Adafruit_PCF8591 arm5_temp = Adafruit_PCF8591();



// Initialize variables
char userInput; // Used for menu

// ADC Modules

//Kalman Filter
//  e_mea = ;
//  e_est = ;
//  q = ;
//  SimpleKalmanFilter simpleKalmanFilter(e_mea, e_est, q);

void setup(void) {
  // Initialize I2C Buses
  Wire.begin();   // Default I2C Bus for Pose (Due Pins: 20, 21)
  //UNCOMMENT FOR DUE  Wire1.begin();  // Second I2C Bus for Temp (Due Pins: SDA1, SCL1)

  // Initialize Serial Communication
  Serial.begin(115200);

  // Initialize ADC Modules
  arm1_pose.begin(ADC_ADDRESS[0]);
  arm2_pose.begin(ADC_ADDRESS[1]);
  arm3_pose.begin(ADC_ADDRESS[2]);
  arm4_pose.begin(ADC_ADDRESS[3]);
  arm5_pose.begin(ADC_ADDRESS[4]);

  // UNCOMMENT FOR DUE
  //  arm1_temp.begin(ADC_ADDRESS[0]);
  //  arm2_temp.begin(ADC_ADDRESS[1]);
  //  arm3_temp.begin(ADC_ADDRESS[2]);
  //  arm4_temp.begin(ADC_ADDRESS[3]);
  //  arm5_temp.begin(ADC_ADDRESS[4]);

  // Enable DAC For ADC Modules
  //  This is to control the LEDs on top of each arm
  //  Only for pose adc modules
  arm1_pose.enableDAC(true);
  arm2_pose.enableDAC(true);
  arm3_pose.enableDAC(true);
  arm4_pose.enableDAC(true);
  arm5_pose.enableDAC(true);


  // Print out menu for user
  for (int i = 0; i < 50; ++i) { // 'clears' screen and reprints menu
    Serial.println();
  }
  PrintMenu();

}// end setup() function


void loop(void) {
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  while (Serial.available() < 2); {
  }
  userInput = Serial.read(); //read character that user typed
  Serial.read();// reading newline character to empty buffer
  for (int i = 0; i < 50; ++i) { // 'clears' screen and reprints menu
    Serial.println();
  }
  Serial.print("User input was ");
  Serial.println(userInput);
  delay(100);

  switch (userInput) {
    case 'a':
      Serial.println("\nI2C Scanner");
      i2c_scan();
      Serial.println("Enter z to go back to menu.\n");
      break;

    case 'b':
      Serial.println("\nAdafruit PCF8591 Detector");
      i2c_detect();
      Serial.println("Enter z to go back to menu.\n");
      break;

    case 'c':
      Serial.println("\nTest LED");
      test_LED();
      Serial.println("Enter z to go back to menu.\n");
      break;

    case 'd':
      Serial.println("\nContinuous Arm Read Function:");
      arm_read();
      Serial.println("Enter z to go back to menu.\n");
      break;

    case 'e':
      Serial.println("\nFull Pose Print");
      full_pose_print();
      Serial.println("Enter z to go back to menu.\n");
      break;

    case 'z': {
        PrintMenu();
      }
      break;

    default:
      Serial.println("Invalid input.\n");
      PrintMenu();
      break;

  } // end switch
} // end loop() function
