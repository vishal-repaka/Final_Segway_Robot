
void servoOut()
{
  
  output = int(output); // so servo only read and write integers
  int servoOutput1 = map(output, -90,90,180,0); //mapping data from error to rotate servos in direction and speed
  int servoOutput2 = map(output, -90,90,0,180); 
  myservo.write(servoOutput1); //writing to servos
  myservo2.write(servoOutput2);
 
  
  
}
