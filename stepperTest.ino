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
void printRes();

int servoPin = 5;
int Led1 = 6;
int Led2 = 7;

const int srtBtn = 10;  //start button
const int rstBtn = 11;  //reset button
int srtBtnVal;
int rstBtnVal;

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
    dispenser.attach(servoPin);

    pinMode(Led1, OUTPUT);
    pinMode(Led2, OUTPUT);
    
    pinMode(srtBtn, INPUT_PULLUP);
    pinMode(rstBtn, INPUT_PULLUP);
    
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
    srtBtnVal = digitalRead(srtBtn);
    rstBtnVal = digitalRead(rstBtn);

    Serial.print("start : ");
    Serial.println(srtBtnVal);
    Serial.print("reset : ");
    Serial.println(rstBtnVal);
    Serial.println();
    delay(100);

    if (srtBtnVal == LOW) {
        rollReels();
        spinReels();
        calcRes();
        printRes();
    } else if (rstBtnVal == LOW) {
//        reset();
    }
        
}

void aStep1(int s1) {
    switch(s1) {
        case 0:
            digitalWrite(stepPin1[0], LOW);
            digitalWrite(stepPin1[1], HIGH);
            digitalWrite(stepPin1[2], HIGH);
            digitalWrite(stepPin1[3], LOW);

            digitalWrite(stepPin2[0], LOW);
            digitalWrite(stepPin2[1], HIGH);
            digitalWrite(stepPin2[2], HIGH);
            digitalWrite(stepPin2[3], LOW);

            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
            break;

        case 1:
            digitalWrite(stepPin1[0], LOW);
            digitalWrite(stepPin1[1], HIGH);
            digitalWrite(stepPin1[2], LOW);
            digitalWrite(stepPin1[3], HIGH);

            digitalWrite(stepPin2[0], LOW);
            digitalWrite(stepPin2[1], HIGH);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);

            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 2:
            digitalWrite(stepPin1[0], HIGH);
            digitalWrite(stepPin1[1], LOW);
            digitalWrite(stepPin1[2], LOW);
            digitalWrite(stepPin1[3], HIGH);

            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);

            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 3:
            digitalWrite(stepPin1[0], HIGH);
            digitalWrite(stepPin1[1], LOW);
            digitalWrite(stepPin1[2], HIGH);
            digitalWrite(stepPin1[3], LOW);

            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], HIGH);
            digitalWrite(stepPin2[3], LOW);

            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
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

            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
            break;

        case 1:
            digitalWrite(stepPin2[0], LOW);
            digitalWrite(stepPin2[1], HIGH);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);

            digitalWrite(stepPin3[0], LOW);
            digitalWrite(stepPin3[1], HIGH);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 2:
            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], LOW);
            digitalWrite(stepPin2[3], HIGH);

            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], LOW);
            digitalWrite(stepPin3[3], HIGH);
            break;

        case 3:
            digitalWrite(stepPin2[0], HIGH);
            digitalWrite(stepPin2[1], LOW);
            digitalWrite(stepPin2[2], HIGH);
            digitalWrite(stepPin2[3], LOW);

            digitalWrite(stepPin3[0], HIGH);
            digitalWrite(stepPin3[1], LOW);
            digitalWrite(stepPin3[2], HIGH);
            digitalWrite(stepPin3[3], LOW);
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
    delay(100);
}

void spinReels() {
    doSteps1(0, 600, 2);
//    delay(100);
    doSteps1(0, 20 * randomPos[0], 2);
//    delay(100);
    doSteps2(0, 600, 2);
//    delay(100);
    doSteps2(0, 20 * randomPos[1], 2);
//    delay(100);
    doSteps3(0, 600, 2);
//    delay(100);
    doSteps3(0, 20 * randomPos[2], 2);
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

    //게임 결과 if문 -> reward = 0, 1, 2, 3
    // A B C D G 7 A B C D
    // 0 1 2 3 4 5 6 7 8 9
    if (pos[0]==pos[1]==pos[2]==5) {  //jackpot
        reward = 0;
    } else if (pos[0]==pos[1]==pos[2]==4) {  //again
        reward = 2;
    } else if ((pos[0]==0||pos[0]==6) && (pos[1]==0||pos[1]==6) && (pos[2]==0||pos[2]==6)) {
        reward = 1;
    } else if ((pos[0]==1||pos[0]==7) && (pos[1]==1||pos[1]==7) && (pos[2]==1||pos[2]==7)) {
        reward = 1;
    } else if ((pos[0]==2||pos[0]==8) && (pos[1]==2||pos[1]==8) && (pos[2]==2||pos[2]==8)) {
        reward = 1;
    } else if ((pos[0]==3||pos[0]==9) && (pos[1]==3||pos[1]==9) && (pos[2]==3||pos[2]==9)) {
        reward = 1;
    } else {
        reward = 3;  //lose
    }
}

void printRes() {
//    switch(reward) {
//        case 0:
//            dispenser.write(40);
//            delay(500);
//            dispenser.write(140);
//            delay(500);
//            break;
//            
//        case 1:
//            dispenser.write(40);
//            delay(100);
//            dispenser.write(140);
//            delay(100);
//            break;
//            
//        case 2:
//        //다시 돌려야 하는데 어케 하냐
//            break;
//            
//        default:
//            break;
//    }
//    reward = 0;
}














