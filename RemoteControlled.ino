#include<IRremote.hpp>

int STBY = 9;
int AIN1 = 6;
int AIN2 = 5;
int BIN1 = 10;
int BIN2 = 11;
int IRpin = 2;
int resetTime = 500;

String action = "";

void reset(bool timeReset = false) {
  action = "reset";
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
  // if (timeReset) timeStart = millis();
}

void forward() {
  reset();
  delay(resetTime);
  action = "forward";
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void backward() {
  reset();
  delay(resetTime);
  action = "backward";
  //Serial.println(action);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void left() {
  reset();
  delay(resetTime);
  action = "left";
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void right() {
  reset();
  delay(resetTime);
  action = "right";
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}


void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    // if (IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00) action = "stop";
    // else if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) action = "forward";
    // else if (IrReceiver.decodedIRData.decodedRawData == 0xAD52FF00) action = "backward";
    // else if (IrReceiver.decodedIRData.decodedRawData == 0xF708FF00) action = "left";
    // else if (IrReceiver.decodedIRData.decodedRawData == 0xA55AFF00) action = "right";
    if (IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00) reset();
    else if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) forward();
    else if (IrReceiver.decodedIRData.decodedRawData == 0xAD52FF00) backward();
    else if (IrReceiver.decodedIRData.decodedRawData == 0xF708FF00) left();
    else if (IrReceiver.decodedIRData.decodedRawData == 0xA55AFF00) right();
    Serial.println(action);
    IrReceiver.resume();
  }
}
