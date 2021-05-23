#include <RadioLib.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

#define NodeID 'B'

Adafruit_SSD1306 display(128, 64, &Wire, 16);
SX1276 radio = new Module(18, 26, 14, 35);
volatile bool receivedFlag = false;
volatile bool enableInterrupt = true;

void setFlag(void) {
  if(!enableInterrupt) {
    return;
  }else
  receivedFlag = true;
}

void setup() {  
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(20);
  digitalWrite(16, HIGH);
  Wire.begin(4, 15);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  if (radio.begin() == ERR_NONE) {
    display.print("Inicializando...");
  } else {
    display.print("ERROR");
    while (true);
  }  
  display.display();
  radio.setFrequency(915.0);
  radio.setBandwidth(500.0);
  radio.startReceive();
  radio.setDio0Action(setFlag);
}
