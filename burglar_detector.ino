#define led 7
#define LDR A0
#include <Servo.h>
Servo myservo;
boolean stop_alarm=false;
boolean current= false;
int pos;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(LDR,INPUT);
  myservo.attach(9);
  Serial.begin(9600);
  // put your setup code here, to run once:

}
// loop to show that the intruder has entered
boolean alarm_loop(){
  if(stop_alarm==false){
    for(pos=90;pos>=0;pos--){
      myservo.write(pos);
      delay(15);
    }
  Serial.println("there is an intruder");
  }
  stop_alarm=true;
  return stop_alarm;
}
// loop to show that there is no intruder
boolean no_alarm_loop(){
  if(current==false){
    Serial.println("no intruder right now\n");
  }
  pos=0;
  current=true;
  return current;
}

void loop() {
  int n= analogRead(LDR);
  if(n<100){
    digitalWrite(led,HIGH);
    stop_alarm=alarm_loop();
  }
  else
  {
    current=no_alarm_loop();
  }
  }
  // put your main code here, to run repeatedly
