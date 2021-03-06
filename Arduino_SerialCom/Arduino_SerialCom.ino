#include <Servo.h> 
 Servo myservo;

int data   = 0;
int estado = 0;
int pos    = 0;

int sensor1 = 0;
int sensor2 = 0;

const int salida1=8;
const int salida2=9;
const int salida3=10;
const int salida4=11;
const int salida5=12;
const int pinServo = 6;

void setup() {
   // Inicializa la comunicacion serial.
  Serial.begin(9600);    
  myservo.attach(pinServo);
  ServoCenter();
}

void loop() {
  
   myservo.write(pos);
 
  while (Serial.available()){
  
    data = Serial.parseInt();
   
   //Serial.println(data);
   
   switch(data){
   case 1:  digitalWrite(salida1,HIGH);
            Serial.println("Salida 1-ON");
            break;
   case 2:  digitalWrite(salida1,LOW);
            Serial.println("Salida 1-OFF"); 
            break;
   case 3:  digitalWrite(salida2,HIGH);
            Serial.println("Salida 2-ON");
            break;
   case 4:  digitalWrite(salida2,LOW);
            Serial.println("Salida 2-OFF");
            break;
   case 5:  digitalWrite(salida3,HIGH);
            Serial.println("Salida 3-ON");
            break;
   case 6:  digitalWrite(salida3,LOW); 
            Serial.println("Salida 3-OFF");
            break;
   case 7:  digitalWrite(salida4,HIGH);
            Serial.println("Salida 4-OFF");
            break;
   case 8:  digitalWrite(salida4,LOW);
            Serial.println("Salida 4-OFF");
            break;
   case 9:  digitalWrite(salida5,HIGH);
            Serial.println("Salida 5-ON");
            break;
   case 10: digitalWrite(salida5,LOW);
            Serial.println("Salida 5-OFF");
            break;
   case 11:  ServoRight();
            Serial.println("Servo-Right");
            break;
   case 12: ServoLeft();
            Serial.println("Servo-Left");
            break;
   case 13: ServoCenter();
            Serial.println("Servo-Center");
            break;
   case 14:  sensor1 = analogRead(A0);
            Serial.println("Entrada-Analogica1");
            Serial.println(sensor1);
            break;
   case 15:  sensor2 = analogRead(A1);
            Serial.println("Entrada-Analogica2");
            break;         
   case 101: Serial.println("Hello Server..!"); break;
   
   default:
            digitalWrite(salida1,LOW);
            digitalWrite(salida2,LOW);
            digitalWrite(salida3,LOW);
            digitalWrite(salida4,LOW);
            digitalWrite(salida5,LOW); 
           break;
   } 
    
  }
}

void ServoCenter(){
  pos = 90;
  myservo.write(pos);
}

void ServoRight(){
     for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
}

void ServoLeft(){
          for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
}
