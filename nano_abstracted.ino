#define LED1 9
#define LED2 10
#define Button1 2
#define Button2 3

bool L1_state = false;
bool L2_state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Button1)) {
    L1_state = !L1_state;
  }

  if (digitalRead(Button2)) {
    L2_state = !L2_state;
  }

  digitalWrite(LED1, L1_state);
  digitalWrite(LED2, L2_state);
}
