#include <Servo.h> 
 Servo myservo;

int data   = 0;
int estado = 0;
int pos    = 0;

int sensor1 = 0;
int sensor2 = 0;

int SalidasDigitales[] ={ 8,9,10,11,12};
const int pinServo = 6;

void setup() {
   // Inicializa la comunicacion serial.
  Serial.begin(9600);    
  //myservo.attach(pinServo);
  delay(1000);
  for(int i =0; i < 5; i++){
    pinMode(SalidasDigitales[i],OUTPUT);
  }
}

void loop() {
  /*
 for(int i = 0; i < 5; i++){
  digitalWrite(SalidasDigitales[i],HIGH);
  delay(100);
 }
  for(int i = 0; i < 5; i++){
  digitalWrite(SalidasDigitales[i],LOW);
  delay(100);
 }*/
 
 
  while (Serial.available()){
  
    data = Serial.parseInt();
   
   //Serial.println(data);
   
   switch(data){
   case 1:  digitalWrite( SalidasDigitales[0], HIGH);
            Serial.println("Salida 1-ON");
            break;
   case 2:  digitalWrite( SalidasDigitales[0], LOW);
            Serial.println("Salida 1-OFF"); 
            break;
   case 3:  digitalWrite( SalidasDigitales[1], HIGH);
            Serial.println("Salida 2-ON");
            break;
   case 4:  digitalWrite( SalidasDigitales[1], LOW);
            Serial.println("Salida 2-OFF");
            break;
   case 5:  digitalWrite( SalidasDigitales[2], HIGH);
            Serial.println("Salida 3-ON");
            break;
   case 6:  digitalWrite( SalidasDigitales[2], LOW); 
            Serial.println("Salida 3-OFF");
            break;
   case 7:  digitalWrite( SalidasDigitales[3], HIGH);
            Serial.println("Salida 4-OFF");
            break;
   case 8:  digitalWrite( SalidasDigitales[3], LOW);
            Serial.println("Salida 4-OFF");
            break;
   case 9:  digitalWrite( SalidasDigitales[4], HIGH);
            Serial.println("Salida 5-ON");
            break;
   case 10: digitalWrite( SalidasDigitales[4], LOW);
            Serial.println("Salida 5-OFF");
            break;/*
   case 11:  sensor1 = analogRead(A0);
            Serial.println("Entrada-Analogica1");
            Serial.println(sensor1);
            break;
   case 12:  sensor2 = analogRead(A1);
            Serial.println("Entrada-Analogica2");
            break;         
   case 13: Serial.println("Hello Server..!"); break;
           */
   default:
            for(int i= 0;i < 5; i++){
              digitalWrite(SalidasDigitales[i],LOW);
            } 
           break;
   } 
    
  }
}
