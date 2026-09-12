// 7-segment display pins
// a, b, c, d, e, f, g
int seg[] = {2, 3, 4, 5, 6, 7, 8};



// Numbers 0-7
// 1 = ON, 0 = OFF
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



void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }
}



void loop() {
  // Display 0 to 7
  for (int num = 9; num >= 0; num--) {



    for (int i = 0; i < 7; i++) {
      digitalWrite(seg[i], numbers[num][i]);
    }
delay(1000);  // 1 second
  }
}