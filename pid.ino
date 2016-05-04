void ErrorFind()
{
   
   int now = millis();
   float timeChange = now - lastTime; //time to caluculate intergral and derivative controls
   
   
   input = circleCheck(x, 90); // 90 to balance / setpoint
   
   input = constrain(input, -200, 200);
   
  
   float error = setValue - input; // calculating error value
   errSum += error * timeChange ; // intergral control error sum
   float gradient = (error - lastErr) / timeChange; // derivative control error gradient 
  
   tunings(); //  read values from potentiometers
   
   KP = (kp * error); // final error value for Porpotional Control 
   KI = (ki * errSum);// final error value for Intergral Control
   KD = (kd * gradient);  // final error value for Derivative Control
   
   output = KP + KI + KD; // output to servos 
  
  
   lastErr = error; //for next derivative control
   lastTime = now; // for next time change
}
