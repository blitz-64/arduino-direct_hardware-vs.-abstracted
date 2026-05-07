void setup() {
  DDRB |= (1 << DDB1) | (1 << DDB2); // Set LEDs as output
  SREG = (0 << 7); // Turn off interrupts while setting up registers
  SMCR |= 1; // Set to idle mode to wait for interrupts
  EICRA |= (1 << ISC01) | (1 << ISC00) | (1 << ISC11) | (1 << ISC10); // Set button pins' interrupts for rising edge
  EIMSK |= (1 << INT0) | (1 << INT1); // Enable interrupt for PD2 & PD3 (button pins)
  SREG = (1 << 7); // Turn on interrupts again
}

void loop() {}

// ISR
ISR(INT0_vect) {
  PORTB ^= (1 << DDB1);
}

ISR(INT1_vect) {
  PORTB ^= (1 << DDB2);
}
