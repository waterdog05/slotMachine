#include <Adafruit_NeoPixel.h>
#define PIN 7
#define NUMPIXELS 20  //change later

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int del = 30;

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
