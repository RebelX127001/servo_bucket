#include <Servo.h>; //impor
int led = 13;
int trig = 11;
int echo = 12;
int sPin = 8;
long duration;
float ft, cm;
Servo servoC;
void setup() {
  Serial.begin (9600);
  pinMode (led, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  servoC.attach (sPin);

  servoC.write (0);
  delayMicroseconds (10);
}

void loop() {
  digitalWrite (trig, LOW); //clean sheet
  delay (100);
  digitalWrite (trig, HIGH);
  delay (100);
  digitalWrite (trig, LOW);

  duration = pulseIn (echo, HIGH);

  cm = (duration/2)/29.1;
  ft = cm/30.48;
  Serial.println (cm);
  Serial.println (ft);
  if (ft <= 0.30 ){
      Serial.println ("Yah, Dispense soap or water!!!");
      digitalWrite (led, HIGH);
      servoC.write (180);
      delay (5000);
      servoC.write(0);
      digitalWrite (led, LOW);
    }
    else{
      Serial.println ("Not in range!!!");
    }
  delay (1000);

}
