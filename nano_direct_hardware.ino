#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED1 9
#define LED2 10
#define Button1 2
#define Button2 3
#define piezo 8
#define neoPixel 4
#define JoystickX A6
#define JoystickY A7

volatile bool iState = LOW;

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
  
  cli(); // Turn off interrupts while setting up registers
  // EICRA: configure pins 2 & 3 for logical change, rising or falling edge activation
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  // Enable interrupt for pin 2
  EIMSK |= (1 << INT0);

  sei(); // Turn on interrupts again
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, iState);

}

// ISR
ISR(INT0_vect) {
  iState = !iState;
}