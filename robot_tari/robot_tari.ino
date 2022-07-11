// SDA A4
// SCL A5
#include "HCPCA9685.h"
#define  I2CAdd 0x40

HCPCA9685 HCPCA9685(I2CAdd);
int i = 0;

void gerak_lama(int servo, int tujuan){
  if(i > tujuan){
    HCPCA9685.Servo(servo, i);
    i = i + 1;
    delay(100);
  }else if(i < tujuan){
    HCPCA9685.Servo(servo, i);
    i = i - 1;
    delay(100);
  }else{
    HCPCA9685.Servo(servo, tujuan);
  }
  print(i);
}
void setup()
{ 
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE); 
  HCPCA9685.Sleep(false);
  
  HCPCA9685.Servo(4, 180);
  HCPCA9685.Servo(5, 180);
  HCPCA9685.Servo(6, 180);
  HCPCA9685.Servo(7, 180);
  HCPCA9685.Servo(8, 180);
  HCPCA9685.Servo(9, 180);
  HCPCA9685.Servo(10, 180);
  HCPCA9685.Servo(11, 180);
  HCPCA9685.Servo(12, 0);
  HCPCA9685.Servo(13, 0);
  HCPCA9685.Servo(14, 0);
  HCPCA9685.Servo(15, 0);
  delay(10);
  gerak_lama(16, 90);
  }
 
 
void loop()
{
  int potensio1 = analogRead(A0);
  int potensio2 = analogRead(A1);
  int potensio3 = analogRead(A2);
  int potensio4 = analogRead(A3);
  
  int pot1 = map(potensio1, 0, 1023, 0, 360);
  int pot2 = map(potensio2, 0, 1023, 0, 360);
  int pot3 = map(potensio3, 0, 1023, 0, 360);
  int pot4 = map(potensio4, 0, 1023, 0, 360);
  
  HCPCA9685.Servo(0, pot1);
  HCPCA9685.Servo(1, pot2);
  HCPCA9685.Servo(2, pot3);
  HCPCA9685.Servo(3, pot4);
  
  
  Serial.println("potensio 1 : " + String(pot1) + "|| potensio 2 : " + String(pot2) + "|| potensio 3 : " + String(pot3) + "|| potensio 4 : " + String(pot4));
  delay(100);
  }


void kaki_kanan_belakang(){
  HCPCA9685.Servo(0, 289);
  HCPCA9685.Servo(1, 111);
}

void kaki_berdiri(){
  
}
