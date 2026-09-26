#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "images.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int currentFrame = 0;
unsigned long previousMillis = 0;
const long frameInterval =60;

void setup() {
  Serial.begin(115200);
  Wire.begin(21,22);
  Wire.setClock(400000); 
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Display SSD1306 non trovato!"));
    for (;;);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= frameInterval) {
    previousMillis = currentMillis;

    
    uint8_t* buffer = display.getBuffer();

   
    memcpy_P(buffer, epd_bitmap_allArray[currentFrame], 1024);

    
    for (int page = 0; page < 8; page++) {
      int pageOffset = page * 128;
      // Colonnine a sinistra (0 .. 31)
      memset(buffer + pageOffset, 0x00, 32);
      // Colonnine a destra (96 .. 127)
      memset(buffer + pageOffset + 96, 0x00, 32);
    }

    display.display();

    currentFrame = (currentFrame + 1) % TOTAL_FRAMES;
  }
}

