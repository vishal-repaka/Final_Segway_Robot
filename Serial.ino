void serialWrite()
{
   Serial.print("Ang: ");
  Serial.print(input);
  Serial.print(" TimeChange: ");
  Serial.print(lastTime);
  Serial.print(" Output: ");
  Serial.print(output);
  Serial.print(" Kp:");
  Serial.print(kp);
  Serial.print(" Ki:");
  Serial.print(ki);
  Serial.print(" Kd:");
  Serial.print(kd);
  Serial.println();
  delay(10); 
  
}
