#include <Servo.h>     
Servo myservo;          
int SPEED = 70;
int servoPin = 9;
int trig = 8;
int echo = 7;
int in1 = 6;
int in2 = 5;
int in3 = 11 ;
int in4 = 3;

 
void setup ()
{ 
    myservo.attach(servoPin); 
    pinMode(trig,OUTPUT);     
    pinMode(echo,INPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT); 
}
void loop ()
{
    
    int distance;
    int l;
    int r;
    tien();
    myservo.write(90);
    distance = read_distance();
    while (distance >=15){
      distance = read_distance();
    }
    if (distance < 15){
      dung();
      myservo.write(150);
      l = read_distance();
      delay(500);
      myservo.write(30);
      r = read_distance();
      delay(500);
      myservo.write(90);
      if (l>r){
        turn_left();
        
      }
      else {
        turn_right();
      }
    } 
}
int read_distance (){
    unsigned long duration;
    int a;
    
    digitalWrite(trig,0);
    delayMicroseconds(2);
    digitalWrite(trig,1);
    delayMicroseconds(5);
    digitalWrite(trig,0); 
    
    duration = pulseIn(echo,HIGH);  
    a = int(duration/2/29.412);
    return(a);
}

void motor_1_Tien() { 
  analogWrite(in1, SPEED);
  digitalWrite(in2, LOW);
}
 
void motor_1_Lui() {
  digitalWrite(in1, LOW);
  analogWrite(in2, SPEED);
}
void motor_2_Lui() {

  analogWrite(in3, SPEED);
  digitalWrite(in4, LOW);
}
 
void motor_2_Tien() {
  digitalWrite(in3, LOW);
  analogWrite(in4, SPEED);
}
void tien(){
  motor_1_Tien();
  motor_2_Tien();
}

void turn_left(){
  digitalWrite(in1, LOW);
  analogWrite(in2, 200);
  digitalWrite(in3, LOW);
  analogWrite(in4, 200);
  delay(1000);
}
void turn_right(){
  analogWrite(in1, 200);
  digitalWrite(in2, LOW);
  analogWrite(in3, 200);
  digitalWrite(in4, LOW);
  delay(1000);  
}
void dung(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
