void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    int randomNum[] = {0, 0, 0};
    for (int i=0; i<3; i++) {
        randomNum[i] = getTrueRotateRandomByte() % 10;
        Serial.println(randomNum[i]);
    }
    Serial.println();
    delay(1000);
}
