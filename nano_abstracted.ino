#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define LED1 9
#define LED2 10
#define Button1 2
#define Button2 3
#define piezo 8
#define neoPixel 4
#define JoystickX A6
#define JoystickY A7

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long timer = 0;
int state = 1;
bool debounce = false;
unsigned long timeDelay = 5000;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(JoystickX, INPUT);
  pinMode(JoystickY, INPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  display.setTextColor(1);
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0, 0);

  display.println("time elapsed (ms, s)");
  display.println(millis());

  if (millis() - timer > timeDelay) {
    timer = millis();
    if (debounce == true) {
      debounce = !debounce;
    }
  }

  if (!debounce) {
    if (digitalRead(Button1)) {
      state = 1;
      debounce = !debounce;
    } else if (digitalRead(Button2)) {
      state = 0;
      debounce = !debounce;
    }
  } else if (debounce) {
    display.println("");
    display.print("debounce on");
  }

  if (state == 1) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else if (state == 0) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }

  display.display();
}
