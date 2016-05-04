void tunings(){

  kp = map(analogRead(pot1), 0.0, 1023.0, 0.0, 6.0); //reading from potentiometer
  ki = map(analogRead(pot2), 0.0, 1023.0, 0.0, 10.0); //reading from potentiometer
  kd = map(analogRead(pot3), 0.0, 1023.0, 0.0, 6.0); //reading from potentiometer
  ki = ki/10000; //decreasing value for I value for PID control
  kd = kd/10; //gradient for D in PID
 
  
}
