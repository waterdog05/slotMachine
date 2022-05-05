#include <stdlib.h>
#include <time.h>
#include <Servo.h>

Servo dispenser;

void aStep1(int s1);  //one step for stepper motor
void aStep2(int s2);
void aStep3(int s3);

void rstStep1(int s1);  //one step for reset
void rstStep2(int s2);
void rstStep3(int s3);

void doStep1(bool dir, int nSteps, int del);  //spin motor
void doStep2(bool dir, int nSteps, int del);
void doStep3(bool dir, int nSteps, int del);

void rstDoStep1(bool dir, int nSteps, int del);  //reset motor
void rstDoStep2(bool dir, int nSteps, int del);
void rstDoStep3(bool dir, int nSteps, int del);

void rollReels();  //create random position
void spinReels();  //spin reels
void calcRes();  //calculate result
void printRes();  //led + candy
void quit();  //before turning off

int servoPin = 5;

const int srtBtn = 10;  //start button
const int quitBtn = 11;  //quit button
int srtBtnVal;
int quitBtnVal;

int stepPin1[4] = {38, 39, 40, 41};
int stepPin2[4] = {44, 45, 46, 47};
int stepPin3[4] = {50, 51, 52, 53};

int pos[3] = {0, 0, 0};  //reels position
int randomPos[3] = {0, 0, 0};  //create random position

int reward = 4;  //4(lose) as default

void setup() {
    // put your setup code here, to run once:
//    Serial.begin(9600);
    randomSeed(analogRead(0));
    
    dispenser.attach(servoPin);

    pinMode(srtBtn, INPUT_PULLUP);  //HIGH as default
    pinMode(quitBtn, INPUT_PULLUP);
    
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
//    strip.begin();
//    strip.setPixelColor(소자 번호, R, G, B);  마지막 디자인때 수정
    
    srtBtnVal = digitalRead(srtBtn);
    quitBtnVal = digitalRead(quitBtn);
//    delay(100);

//    Serial.print("start : ");
//    Serial.println(srtBtnVal);
//    Serial.print("reset : ");
//    Serial.println(rstBtnVal);
//    Serial.println();
//    delay(100);

    if (srtBtnVal == LOW) {
        rollReels();
        spinReels();
        calcRes();
        printRes();
        
        reward = 4;
    } else if (quitBtnVal == LOW) {
        quit();  //종료 전 반드시 누르기. 안하면 고장남...
    }
}

void aStep1(int s1) {  //3 motors move
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

void aStep2(int s2) {  //2 motors move
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

void aStep3(int s3) {  //1 motor move
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

void rstStep1(int s1) {  //1 motor move for reset
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

void rstStep2(int s2) {  //1 motor move for reset
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

void rstStep3(int s3) {  //1 motor move for reset
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

void doSteps1(bool dir, int nSteps, int del){  //for spin
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

void rstDoSteps1(bool dir, int nSteps, int del){  //for reset
  for( int i = 0; i < nSteps; i++ ){
    rstStep1((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void rstDoSteps2(bool dir, int nSteps, int del){
  for( int i = 0; i < nSteps; i++ ){
    rstStep2((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void rstDoSteps3(bool dir, int nSteps, int del){
  for( int i = 0; i < nSteps; i++ ){
    rstStep3((dir?(nSteps-i-1):i)%4);
    delay(del);
  }
}

void rollReels() {
    int i;

    for (i=0; i<3; i++) {
        randomPos[i] = rand() % 10;
//        Serial.println(randomPos[i]);
    }
//    Serial.println();
//    delay(100);
}

void spinReels() {
    doSteps1(0, 1000, 2);  //spin 5 time
//    delay(100);
    doSteps1(0, 20 * randomPos[0], 2);  //spin random 0
//    delay(100);
    doSteps2(0, 1000, 2);  //spin 5 time
//    delay(100);
    doSteps2(0, 20 * randomPos[1], 2);  //spin random 1
//    delay(100);
    doSteps3(0, 1000, 2);  //spin 5 time
//    delay(100);
    doSteps3(0, 20 * randomPos[2], 2);  //spin random 2
//    delay(100);    
    delay(100);  //adjust later
}

void calcRes() {
    int i;
    
    for (i=0; i<3; i++) {
        pos[i] = (pos[i] + randomPos[i]) % 10;
//        Serial.println(pos[i]);
    }
//    Serial.println();
//    delay(100);

//    게임 결과 if문 -> reward = 0, 1, 2, 3
//    A B C D G 7 A B C D
//    0 1 2 3 4 5 6 7 8 9

    if (pos[0]==pos[1]==pos[2]==5) {  //7-jackpot  0.1%
        reward = 0;
    } else if (pos[0]==pos[1]==pos[2]==4) {  //G - roll again  0.1%
        reward = 1;
    } else if ((pos[0]==0||pos[0]==6) && (pos[1]==0||pos[1]==6) && (pos[2]==0||pos[2]==6)) {  //A  4.7%
        reward = 2;
    } else if ((pos[0]==1||pos[0]==7) && (pos[1]==1||pos[1]==7) && (pos[2]==1||pos[2]==7)) {  //B  4.7%
        reward = 2;
    } else if ((pos[0]==2||pos[0]==8) && (pos[1]==2||pos[1]==8) && (pos[2]==2||pos[2]==8)) {  //C  4.7%
        reward = 2;
    } else if ((pos[0]==3||pos[0]==9) && (pos[1]==3||pos[1]==9) && (pos[2]==3||pos[2]==9)) {  //D  4.7%
        reward = 2;
    } else {
        reward = 3;  //lose  81%
    }
}

void printRes() {
    switch(reward) {
        case 0:  //win
            dispenser.write(40);
            delay(800);
            dispenser.write(140);
            delay(800);
            delay(100);  //adjust later
            break;
            
        case 1:  //again
            //다시 돌려야 하는데 어케 하냐? 테스트 해보고 안되면 걍 바꿔
            srtBtnVal = LOW;
            break;
            
        case 2:  //3 same
            dispenser.write(40);
            delay(400);
            dispenser.write(140);
            delay(400);
            break;
            
        default:  //lose
            break;
    }
}

void quit() {    
    int i;

//    for (i=0; i<3; i++) {
//        pos[i] = (pos[i] + randomPos[i]) % 10;
//    }

    rstDoSteps1(1, 20 * pos[0], 2);
    rstDoSteps2(1, 20 * pos[1], 2);
    rstDoSteps3(1, 20 * pos[2], 2);

    for (i=0; i<3; i++) {
        randomPos[i] = 0;
        pos[i] = 0;

//        Serial.print("random : ");
//        Serial.println(randomPos[i]);
//        Serial.print("pos : ");
//        Serial.println(pos[i]);
//        Serial.println();
    }
    
    reward = 4;
}
