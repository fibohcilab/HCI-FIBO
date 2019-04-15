#include <Servo.h>  

Servo myservo1; 
Servo myservo2;
Servo myservo3;
int pot = A0;  
int val;
int val1;
int val2;
int val3;
const int flex1 = A1;
const int flex2 = A2;
const int flex3 = A5;
const float VCC = 4.98; 
const float R_DIV = 10000.0;
const float STRAIGHT_RESISTANCE = 13700.0; 
const float BEND_RESISTANCE = 90000.0; 

void setup() {
  myservo1.attach(8); 
  myservo2.attach(9); 
  myservo3.attach(10);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A5, INPUT);
  }   
 
void loop() {  
  val = analogRead(pot);            
  val1 = map(val, 0, 1023, 79 ,150);        
  val2 = map(val, 0, 1023, 73, 150);
  val3 = map(val, 0, 1023, 90, 30);
  myservo1.write(val1); 
  myservo2.write(val2);
  myservo3.write(val3);
  delay(15);
  int flexADC1 = analogRead(flex1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  int flexADC2 = analogRead(flex2);
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  int flexADC3 = analogRead(flex3);
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 180.00);
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 180.00);
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 180.00);   
 
  
  if((angle1 >= 9 && angle1 <= 12 && angle2 >= 4 && angle2 <= 6 && angle3 >= 5 && angle3 <= 7))
  {
    Serial.println("Sphere");
     Serial.print("Bend1: " + String(angle1) + " degrees");
  Serial.print('\t');
  Serial.print("Bend2: " + String(angle2) + " degrees");
  Serial.print('\t');
  Serial.print("Bend3: " + String(angle3) + " degrees");
  Serial.print('\t');
  Serial.print('\n');
  delay(1000);
    }
   if((angle1 >= 24 && angle1 <= 26 && angle2 >= 15 && angle2 <= 17 && angle3 >= 19 && angle3 <= 20))
  {
    Serial.println("Diameter 6.0 cm");
     Serial.print("Bend1: " + String(angle1) + " degrees");
  Serial.print('\t');
  Serial.print("Bend2: " + String(angle2) + " degrees");
  Serial.print('\t');
  Serial.print("Bend3: " + String(angle3) + " degrees");
  Serial.print('\t');
  Serial.print('\n');
  delay(1000);
    }
    if((angle1 >= 22 && angle1 <= 23 && angle2 >= 13 && angle2 <= 14 && angle3 >= 16 && angle3 <= 18))
  {
    Serial.println("Diameter 8.0 cm");
     Serial.print("Bend1: " + String(angle1) + " degrees");
  Serial.print('\t');
  Serial.print("Bend2: " + String(angle2) + " degrees");
  Serial.print('\t');
  Serial.print("Bend3: " + String(angle3) + " degrees");
  Serial.print('\t');
  Serial.print('\n');
  delay(1000);
    }
}
