#include <stdlib.h>
#include <time.h>
#include <Servo.h>

Servo dispenser;

void aStep1(int s1);
void aStep2(int s2);
void aStep3(int s3);

void doStep1(bool dir, int nSteps, int del);
void doStep2(bool dir, int nSteps, int del);
void doStep3(bool dir, int nSteps, int del);

void rollReels();
void spinReels();
void calcRes();

int stepPin1[4] = {38, 39, 40, 41};
int stepPin2[4] = {44, 45, 46, 47};
int stepPin3[4] = {50, 51, 52, 53};

int pos[3] = {0, 0, 0};
int randomPos[3] = {0, 0, 0};

int reward = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    randomSeed(analogRead(0));
    
    pinMode(stepPin1[0], OUTPUT);
    pinMode(stepPin1[1], OUTPUT);
    pinMode(stepPin1[2], OUTPUT);
    pinMode(stepPin1[3], OUTPUT);

    pinMode(stepPin2[0], OUTPUT);
    pinMode(stepPin2[1], OUTPUT);
    pinMode(stepPin2[2], OUTPUT);
    pinMode(stepPin2[3], OUTPUT);

    pinMode(stepPin3[0], OUTPUT);
    pinMode(stepPin3[1], OUTPUT);
    pinMode(stepPin3[2], OUTPUT);
    pinMode(stepPin3[3], OUTPUT);
}



void loop() {
    // put your main code here, to run repeatedly:
    rollReels();
    spinReels();
    calcRes();
}

void aStep1(int s1) {
    switch(s1) {
        case 0:
            digitalWrite(stepPin1[0], LOW);
            digitalWrite(stepPin1[1], HIGH);
            digitalWrite(stepPin1[2], HIGH);
            digitalWrite(stepPin1[3], LOW);
            break;

        case 1:
            digitalWrite(stepPin1[0], LOW);
            digitalWrite(stepPin1[1], HIGH);
            digitalWrite(stepPin1[2], LOW);
            digitalWrite(stepPin1[3], HIGH);
            break;

        case 2:
            digitalWrite(stepPin1[0], HIGH);
            digitalWrite(stepPin1[1], LOW);
            digitalWrite(stepPin1[2], LOW);
            digitalWrite(stepPin1[3], HIGH);
            break;

        case 3:
            digitalWrite(stepPin1[0], HIGH);
            digitalWrite(stepPin1[1], LOW);
            digitalWrite(stepPin1[2], HIGH);
            digitalWrite(stepPin1[3], LOW);
            break;

        default:
            break;
    }
}

void aStep2(int s2) {
    switch(s2) {
        case 0:
            digitalWrite(stepPin2[0], LOW);
            digitalWrite(stepPin2[1], HIGH);
            digitalWrite(stepPin2[2], HIGH);
            digitalWrite(stepPin2[3], LOW);
            break;

        case 1:
            digitalWrite(stepPin2[0], LOW);
            digitalWrite(stepPin2[1], HIGH);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);
            break;

        case 2:
            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);
            break;

        case 3:
            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], HIGH);
            digitalWrite(stepPin2[3], LOW);
            break;

        default:
            break;
    }
}
void aStep3(int s3) {
    switch(s3) {
        case 0:
            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
            break;

        case 1:
            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 2:
            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 3:
            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
            break;

        default:
            break;
    }
}

void doSteps1(bool dir, int nSteps, int del){
  for( int i = 0; i < nSteps; i++ ){
    aStep1((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void doSteps2(bool dir, int nSteps, int del){
  for( int i = 0; i < nSteps; i++ ){
    aStep2((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void doSteps3(bool dir, int nSteps, int del){
  for( int i = 0; i < nSteps; i++ ){
    aStep3((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void rollReels() {
    int i;

    for (i=0; i<3; i++) {
        randomPos[i] = rand() % 10;
        Serial.println(randomPos[i]);
    }
    Serial.println();
    delay(1000);
}

void spinReels() {
    doSteps1(0, 200, 2);
    doSteps2(0, 200, 2);
    doSteps3(0, 200, 2);
    delay(100);
}

void calcRes() {
    int i;
    
    for (i=0; i<3; i++) {
        pos[i] = (pos[i] + randomPos[i]) % 10;
        Serial.println(pos[i]);
    }
    Serial.println();
    delay(100);

    //게임 결과 if문 -> reward = 0, 1, 2
    // A B C D G 7 A B C D
    // 0 1 2 3 4 5 6 7 8 9
    // if (pos[0] == pos[1] == pos[2] == 5) {  //jackpot
    //  reward = 0;
    // } else if (pos[0] == pos[1] == pos[2] == 4) {  //again
    //  reward = 2;
    // } else if () {

    // } else {
        
    // }
}
