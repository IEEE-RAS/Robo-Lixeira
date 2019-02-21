#include <Ultrasonic.h>

//pinos do ultrasonico detectar obstaculos
#define TRIGGER_PIN 44
#define ECHO_PIN 42
//pinos do ultrassonico detectar bola
#define TRIGGER_PINL 46
#define ECHO_PINL 48

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); //obstaculos
Ultrasonic ultrasonicL(TRIGGER_PINL , ECHO_PINL); //lixeira

//motorA
int IN1 = 30;
int IN2 = 32;
//motorB
int IN3 = 34;
int IN4 = 36;

void setup() {
  // put your setup code here, to run once:
  //motorA
  pinMode(IN1, OUTPUT);
  pinMode(IN2 , OUTPUT);
  //motorB
  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {

  //deteccao obstaculos
  float cmMsec;// distancia para objetos
  long microsec = ultrasonic.timing(); // time
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // receber a distancia que esta o sensor para o obstaculo
  Serial.print(cmMsec);
  delay(50);
  //deteccao da bola
  float cmMsecL;
  long microsecL = ultrasonicL.timing();
  cmMsecL = ultrasonicL.convert(microsecL, Ultrasonic::CM);
  delay(50);
  Serial.println(cmMsecL); 
  //motorA (horario)
  digitalWrite(IN1 , HIGH);
  digitalWrite(IN2 , LOW);
  //motorB (horario)
  digitalWrite(IN3 , LOW);
  digitalWrite(IN4 , HIGH);
  if(cmMsec <= 30){
    //motorA
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , HIGH);
    //motorB
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
  }
  if(cmMsecL <= 10){
    //motorA
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , HIGH);
    //motorB
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , HIGH);
    delay(3000);
  }
}
