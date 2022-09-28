void test_LED() {
  while (Serial.available() == 0){
    //Turn on Green Light
    arm1_pose.analogWrite(255);
    arm2_pose.analogWrite(255);
    arm3_pose.analogWrite(255);
    arm4_pose.analogWrite(255);
    arm5_pose.analogWrite(255);
    delay(100);
    
    // Turn off Green Light
    arm1_pose.analogWrite(0);
    arm2_pose.analogWrite(0);
    arm3_pose.analogWrite(0);
    arm4_pose.analogWrite(0);
    arm5_pose.analogWrite(0);
    delay(100);
  }
  Serial.read();
  Serial.read(); // Clears input
  return;
}
