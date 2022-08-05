#include <Adafruit_NeoPixel.h>
#define PIN 7
#define NUMPIXELS 20  //change later

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int del = 30;

int srtBtn = 5;  //start btn
int srtBtnVal;

int resBtn0 = 9;  //jackpot
int resBtn1 = 10;  //again
int resBtn2 = 11;  //win
int resBtn3 = 12;  //lose

int resBtn0Val;
int resBtn1Val;
int resBtn2Val;
int resBtn3Val;

void setup() {
    // put your setup code here, to run once:
    pixels.begin();
}

void loop() {
    // put your main code here, to run repeatedly:
    
    for (int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
        pixels.show();
        delay(del);
    }
    
}
