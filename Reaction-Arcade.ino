#include <Servo.h>

int keyPin = 2;
int resetPin = 3;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

bool buttonPressed = false;
bool resetPinPressed = false;

void setup() {
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(7);
  myservo4.attach(11);
  myservo5.attach(12);

  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  myservo5.write(0);

  pinMode(keyPin, INPUT_PULLUP);
  pinMode (resetPin, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

void shuffleArray(int *array, int size) {
  for (int i = size - 1; i > 0; i--) {
    int j = random(0, i + 1);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void loop() {
  if (digitalRead(keyPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    delay(5000);

    randomSeed(analogRead(A0));

    int randomOrder[] = {1, 2, 3, 4, 5};
    shuffleArray(randomOrder, 5);

    for (int i = 0; i < 5; i++) {
      int servoNum = randomOrder[i];
      if (servoNum == 1) {
        myservo1.write(180);
        delay(5000);
      } else if (servoNum == 2) {
        myservo2.write(180);
        delay(5000);
      } else if (servoNum == 3) {
        myservo3.write(180);
        delay(5000);
      } else if (servoNum == 4) {
        myservo4.write(180);
        delay(5000);
      } else {
        myservo5.write(180);
        delay(5000);
      }
      
    }
    buttonPressed = false;
  }
  if (digitalRead(resetPin) == LOW && !resetPinPressed) {
    resetPinPressed = true;
    delay(500); // Button debouncing delay

    myservo1.write(0);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(0);
    myservo5.write(0);
  } else if (digitalRead(resetPin) == HIGH) {
    resetPinPressed = false; // Reset the reset button state
  }

}
