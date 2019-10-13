#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
MPU6050 mpu6050(Wire);
int accX;
int angleX;
int gyroAngleX;
int accAngleX;

long timer = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  
  //mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
accAngleX=mpu6050.getAccAngleX();
    Serial.println("accAngleX : ");
    Serial.println(mpu6050.getAccAngleX());
    delay(1000);
  
if(accAngleX<-5|accAngleX>-3)
  {
    Serial.print("sms sent ");
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917389881849\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Your Neighbour needs your help...");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
 
  
}
