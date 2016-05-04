#include <Wire.h> 
#include <Servo.h>

Servo myservo, myservo2;
byte servoPin = 9;
byte servoPin2 = 10;
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;

int lastTime; //keep track of time intervals

float x = 0;

float setValue = 90; // 90 = level on robot

float input,output;
float errSum, lastErr;
float kp, ki, kd, KP, KI, KD;

void setup() { 
  Serial.begin(19200); 
  Wire.begin(); 
  Wire.beginTransmission(0x68);//mpu 6050 i2c address 
  Wire.write(0x6b);        // select register 0x6b for power management  
  Wire.write(0x00);  // value to write to register 0x6b to wake the MPU6050 
  Wire.endTransmission(true); // release the I2C-bus 
  myservo.attach(servoPin);
  myservo2.attach(servoPin2);
} 


void loop() { 
 
  updateAccel(); //getting new X value
  
  ErrorFind(); //calculating error and output to servos
  
  servoOut(); // function to output values to servos
  
  serialWrite();
}


