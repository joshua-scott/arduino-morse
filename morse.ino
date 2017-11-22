/* 

ARDUINO MORSE CODE SENDER/RECEIVER
TASK REQUIREMENTS:

- Pick any four numbers from the Morse Code table.
- Implement a system that is able to transmit the Morse code of those numbers that you just picked up in random order.
- Arduino should send them to a led, which should blink according to Morse code.
- There should also be a light sensitive sensor in your device so, that the sent code can be caught and shown in a seven segment display.
- Your device should work so, that it randomly is transmitting the Morse code of one of those four numbers that you selected in the beginning. The sensor should recognize the code and after that Arduino should show the sent number in a display.

*/

#include <Arduino.h>

/* ----- MACROS/GLOBALS ----- */

#define A 2
#define B 8
#define C 6
#define D 5
#define E 4
#define F 3
#define G 7
#define LED 11
#define SENSOR A0

const int all[7] = {A, B, C, D, E, F, G};

/* ----- END MACROS/GLOBALS ----- */

/* ----- SETUP ----- */

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  // Display outputs
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  // Other outputs/inputs
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
}

/* ----- END SETUP ----- */

/* ----- DISPLAY ----- */

void TurnOnLED(int led){
  digitalWrite(led, LOW);
}

void TurnOffAllLED(){
  for (int i = 0; i < sizeof(all); i++){
    digitalWrite(all[i], HIGH);
  }
}

void DisplayDigit(int digit) {
  TurnOffAllLED();
  Serial.println(digit);
  switch (digit) {
    case 0:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(C);
      TurnOnLED(D);
      TurnOnLED(E);
      TurnOnLED(F);
      break;
    case 1:
      TurnOnLED(B);
      TurnOnLED(C);
      break;
    case 2:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(G);
      TurnOnLED(E);
      TurnOnLED(D);
      break;
    case 3:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(G);
      TurnOnLED(C);
      TurnOnLED(D);
      break;
    case 4:
      TurnOnLED(F);
      TurnOnLED(G);
      TurnOnLED(B);
      TurnOnLED(C);
      break;
    case 5:
      TurnOnLED(A);
      TurnOnLED(F);
      TurnOnLED(G);
      TurnOnLED(C);
      TurnOnLED(D);
      break;
    case 6:
      TurnOnLED(A);
      TurnOnLED(C);
      TurnOnLED(D);
      TurnOnLED(E);
      TurnOnLED(F);
      TurnOnLED(G);
      break;
    case 7:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(C);
      break;
    case 8:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(C);
      TurnOnLED(D);
      TurnOnLED(E);
      TurnOnLED(F);
      TurnOnLED(G);
      break;
    case 9:
      TurnOnLED(A);
      TurnOnLED(B);
      TurnOnLED(C);
      TurnOnLED(D);
      TurnOnLED(F);
      TurnOnLED(G);
      break;
    default:
      Serial.println("DisplayDigit needs an int 0-9");
      break;
  }
}

/* ----- END DISPLAY ----- */

/* ----- MORSE NUMBERS ----- */

char* getMorse(int number) {
  char* morse = "     \0";
  
  switch (number){
    case 0:
      morse[0] = '-';
      morse[1] = '-';
      morse[2] = '-';
      morse[3] = '-';
      morse[4] = '-';
      break;
    case 1:
      morse[0] = '.';
      morse[1] = '-';
      morse[2] = '-';
      morse[3] = '-';
      morse[4] = '-';
      break;
    case 2:
      morse[0] = '.';
      morse[1] = '.';
      morse[2] = '-';
      morse[3] = '-';
      morse[4] = '-';
      break;
    case 3:
      morse[0] = '.';
      morse[1] = '.';
      morse[2] = '.';
      morse[3] = '-';
      morse[4] = '-';
      break;
    case 4:
      morse[0] = '.';
      morse[1] = '.';
      morse[2] = '.';
      morse[3] = '.';
      morse[4] = '-';
      break;
    case 5:
      morse[0] = '.';
      morse[1] = '.';
      morse[2] = '.';
      morse[3] = '.';
      morse[4] = '.';
      break;
    case 6:
      morse[0] = '-';
      morse[1] = '.';
      morse[2] = '.';
      morse[3] = '.';
      morse[4] = '.';
      break;
    case 7:
      morse[0] = '-';
      morse[1] = '-';
      morse[2] = '.';
      morse[3] = '.';
      morse[4] = '.';
      break;
    case 8:
      morse[0] = '-';
      morse[1] = '-';
      morse[2] = '-';
      morse[3] = '.';
      morse[4] = '.';
      break;
    case 9:
      morse[0] = '-';
      morse[1] = '-';
      morse[2] = '-';
      morse[3] = '-';
      morse[4] = '.';
      break;
    default:
      Serial.println("getMorse needs an int 0-9");
      break;
  }
    return morse;
}

int decodeMorse(char* inputMorse) {
  int result;
  if ((String)inputMorse == "-----") { 
    result = 0;
  }
  else if ((String)inputMorse == ".----") { 
    result = 1;
  }
  else if ((String)inputMorse == "..---") { 
    result = 2;
  }
  else if ((String)inputMorse == "...--") { 
    result = 3;
  }
  else if ((String)inputMorse == "....-") { 
    result = 4;
  }
  else if ((String)inputMorse == ".....") { 
    result = 5;
  }
  else if ((String)inputMorse == "-....") { 
    result = 6;
  }
  else if ((String)inputMorse == "--...") { 
    result = 7;
  }
  else if ((String)inputMorse == "---..") { 
    result = 8;
  }
  else if ((String)inputMorse == "----.") { 
    result = 9;
  }
  DisplayDigit(result);

  return result;
}
/* ----- END MORSE NUMBERS ----- */

void blinkDot() {
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
}

void blinkDash() {
  digitalWrite(LED, HIGH);
  delay(900);
  digitalWrite(LED, LOW);
  delay(300);
}

void space() {
  delay(900);
}

void blinkDotOrDash(int number, int morseIndex) {
  char currentMorse = getMorse(number)[morseIndex];
  currentMorse == '.' ? blinkDot() : blinkDash();
}

void morseSequence() {
  // Get four random digits
  int digits[4];
  for (int i = 0; i < 4; i++) {
    digits[i] = random(10);
  }
  Serial.println("Random digits are: ");
  Serial.println(digits[0]);
  Serial.println(digits[1]);
  Serial.println(digits[2]);
  Serial.println(digits[3]);

  char* receivedMorse = "     \0";

  // Send and intercept each of the four random digits
  for (int i = 0; i < 4; i++) {
    // Send and intercept each DOT or DASH within the digit
    for (int j = 0; j < 5; j++) {
      int ambientLight = analogRead(SENSOR);
      int startTime = millis();

      blinkDotOrDash(digits[i], j);
      delay(10);

      while (analogRead(SENSOR) > ambientLight + 5) {
        // the led is now lit...
      }

      int lightOnFor = millis() - startTime;

      if (lightOnFor > 700) {
        Serial.println("That's a DASH!");
        receivedMorse[j] = '-';
      } else {
        Serial.println("That's a DOT!");
        receivedMorse[j] = '.';
      }      
    }

    int decodedNumber = decodeMorse(receivedMorse);
    Serial.print("OK, we think the number is...");
    Serial.println(decodedNumber);
  }
}

/* ----- LOOP ----- */

void loop() {
  TurnOffAllLED();
  morseSequence();

  while(1) {
    Serial.println("End of program");
    TurnOffAllLED();
    delay(5000);
  }
}

/* ----- END LOOP ----- */
