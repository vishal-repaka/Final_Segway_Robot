void updateAccel() {
  Wire.beginTransmission(0x68);//mpu 6050 i2c address 
  Wire.write(0x3B);      //register address for the start of accelerometer data 
  Wire.endTransmission(false);    // hold the I2C-bus 
  Wire.requestFrom(0x68, 6, true);  //the 6 here is the number of bytes to read 
  byte i = 0; 
  byte buffer[6]; 
  float accRaw[3]; 

  while(Wire.available() && i<6) 
  { 
    buffer[i]=Wire.read(); 
    i++; 
  } 
  if ( i != 6)     {     
    Serial.println('I2C Error!');   
  }  

  accRaw[0]=(float)(buffer[0]<<8 | buffer[1]); // starting componenets in ACCELEROMETER 
  accRaw[1]=(float)(buffer[2]<<8 | buffer[3]);
  accRaw[2]=(float)(buffer[4]<<8 | buffer[5]);

  float acc[3]; 
  
  for(int j = 0;j<3;j++) {
    acc[j] = accRaw[j]*(3.3/(1024.0*0.800)); //decreasing value so easier to convert
  }

  x = atan(acc[0]/sqrt(pow(acc[1],2)+pow(acc[2],2)))*(360/(2*PI)); // converting to degrees 
}
