// 7-segment pins
int seg[] = {2, 3, 4, 5, 6, 7, 8};

const int Buzzer = 9;
const int ButtonPin = 10;
const int LedPin = 12;

// Common Anode
int numbers[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};

int num = 9;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }

  pinMode(Buzzer, OUTPUT);
  pinMode(ButtonPin, INPUT_PULLUP);
  pinMode(LedPin, OUTPUT);

  // Show 9 initially
  for (int i = 0; i < 7; i++) {
    digitalWrite(seg[i], numbers[num][i]);
  }
}

void loop() {

  if (digitalRead(ButtonPin) == LOW) {
    
    digitalWrite(LedPin,HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(100);
    digitalWrite(LedPin,LOW);
    digitalWrite(Buzzer, LOW);
    

    num--;

    if (num < 0) {
      num = 9;
     digitalWrite(LedPin,HIGH);
    }

    for (int i = 0; i < 7; i++) {
      digitalWrite(seg[i], numbers[num][i]);
    }

    delay(300);
  }

}