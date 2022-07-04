#include <Servo.h>

Servo slider;  //candy opener

//press btn for result
Servo resultServo0;  //jackpot
Servo resultServo1;  //again
Servo resultServo2;  //
Servo resultServo3;

void randNum();  //create 3 random number
void spinReels();  //spin reels
void calcRes();  //calculate result
void printRes();  //press btn to print result

int srtBtn = 22;  //start button
int srtVal;

int sliderPin = 24;
int resultServo0Pin = 30;
int resultServo1Pin = 31;
int resultServo2Pin = 32;
int resultServo3Pin = 33;

int res;  //game result

const int stepPin1 = 2;  //stepper motor pin
const int stepPin2 = 3;
const int stepPin3 = 4;

const int dirPin1 = 5;  //rotation direction
const int dirPin2 = 6;
const int dirPin3 = 7;

int pos[3] = {0, 0, 0};  //reel position
int randomPos[3] = {0, 0, 0};  //position after spin

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    randomSeed(analogRead(0));
    
    pinMode(srtBtn, INPUT_PULLUP);
    
    slider.attach(sliderPin);
    resultServo0.attach(resultServo0Pin);
    resultServo1.attach(resultServo1Pin);
    resultServo2.attach(resultServo2Pin);
    resultServo3.attach(resultServo3Pin);
    
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);
    pinMode(stepPin3, OUTPUT);
    pinMode(dirPin3, OUTPUT);

    slider.write(90);
    resultServo0.write(90);
    resultServo1.write(90);
    resultServo2.write(90);
    resultServo3.write(90);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(dirPin1, HIGH);  //direction
    digitalWrite(dirPin2, HIGH);
    digitalWrite(dirPin3, HIGH);

    srtVal = digitalRead(srtBtn);
    Serial.println(srtVal);
    Serial.println();
    
    if (srtVal == LOW) {
        randNum();
        spinReels();
        calcRes();
        printRes();
        
        res = 4;
        slider.write(90);
        resultServo0.write(90);
        resultServo1.write(90);
        resultServo2.write(90);
        resultServo3.write(90);
    }
//    delay(1000);
}

void randNum() {
    int i;
    for (i=0; i<3; i++) {
        randomPos[i] = getTrueRotateRandomByte() % 10;
        Serial.println(randomPos[i]);
    }
    Serial.println();
    delay(500);
}

void spinReels() {
    for (int i=0; i<800; i++) {
        digitalWrite(stepPin1, HIGH);
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin1, LOW);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<20*randomPos[0]; i++) {
        digitalWrite(stepPin1, HIGH);
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin1, LOW);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<200-(20*randomPos[0]); i++) {
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<800; i++) {
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<20*randomPos[1]; i++) {
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<200-(20*randomPos[1]); i++) {
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<800; i++) {
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
//    delay(500);
    for (int i=0; i<20*randomPos[2]; i++) {
        digitalWrite(stepPin3, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin3, LOW);
        delayMicroseconds(500);
    }
}

void calcRes() {
    int i;
    
    for (i=0; i<3; i++) {
        pos[i] = (pos[i] + randomPos[i]) % 10;
        Serial.println(pos[i]);
    }

//    char sequence
//    A B C D G 7 A B C D
//    0 1 2 3 4 5 6 7 8 9
    if (pos[0]==5 && pos[1]==5 && pos[2]==5) {  //7-jackpot  0.1%
        res = 0;
    } else if (pos[0]==4 && pos[1]==4 && pos[2]==4) {  //G - roll again  0.1%
        res = 1;
    } else if ((pos[0]==0||pos[0]==6) && (pos[1]==0||pos[1]==6) && (pos[2]==0||pos[2]==6)) {  //A  4.7%
        res = 2;
    } else if ((pos[0]==1||pos[0]==7) && (pos[1]==1||pos[1]==7) && (pos[2]==1||pos[2]==7)) {  //B  4.7%
        res = 2;
    } else if ((pos[0]==2||pos[0]==8) && (pos[1]==2||pos[1]==8) && (pos[2]==2||pos[2]==8)) {  //C  4.7%
        res = 2;
    } else if ((pos[0]==3||pos[0]==9) && (pos[1]==3||pos[1]==9) && (pos[2]==3||pos[2]==9)) {  //D  4.7%
        res = 2;
    } else {
        res = 3;  //lose  81%
    }

    Serial.println(res);
    Serial.println();
}

void printRes() {
    switch(res) {
        case 0:  //win
            resultServo0.write(0);
            delay(800);
            resultServo0.write(90);
            delay(800);
            
            slider.write(20);
            delay(2000);
            slider.write(90);
            delay(2000);
            break;
            
        case 1:  //again
            //다시 돌려야 하는데 어케 하냐? 테스트 해보고 안되면 걍 바꿔
            resultServo1.write(0);
            delay(800);
            resultServo1.write(90);
            delay(800);
            
//            delay(1000);
            res = 4;
            srtVal = LOW;
            break;
            
        case 2:  //3 same
            resultServo2.write(0);
            delay(800);
            resultServo2.write(90);
            delay(800);
            
            slider.write(20);
            delay(1000);
            slider.write(90);
            delay(1000);
            break;

        case 3:  //lose
            resultServo3.write(0);
            delay(800);
            resultServo3.write(90);
            delay(800);
        
        default:  //other value
            break;
    }
}
