#include "SdFat.h"
#include <Keypad.h>



#define SPI_SPEED SD_SCK_MHZ(4)
#define CS_PIN 10
#define BUZZER 2



const byte ROWS = 5;
const byte COLS = 5;




char keys[ROWS][COLS] = {
  { '1', '2', '3', '4', '5' },
  { '6', '7', '8', '9', 'A' },
  { 'B', 'C', 'D', 'E', 'F' },
  { 'G', 'H', 'I', 'J', 'K' },
  { 'L', 'M', 'N', 'O', 'P' }
}; 

//the data type is "char" so when you use something like '10' it messes up the system
// you assign just ONE character to every button and trigger whatever you need, through code later on.

byte colPins[COLS] = {18,8,3,46,9};
byte rowPins[ROWS] = {45,48,47,21,20};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

SdFat sd;





void setup() {
  Serial.begin(115200);
  if (!sd.begin(CS_PIN, SPI_SPEED)) {
    if (sd.card()->errorCode()) {
      Serial.println("SD initialization failed.");
    } else if (sd.vol()->fatType() == 0) {
      Serial.println("Can't find a valid FAT16/FAT32 partition.");
    } else {
      Serial.println("Can't determine error type");
    }
    return;
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(15, INPUT);
  }

  Serial.println("Files on card:");
  Serial.println("   Size    Name");

  sd.ls(LS_R | LS_SIZE);
}




unsigned long then = millis();


// get the indexes of "key"
// index1 = multiply first index by 5
// add second index to index1 = key_number
// 'Middle C' number is 11 (12th button)
// subtract: n = (key_number - middle_c)
// new key hertz: key_Hz = 440*2^(n/12)

  //this is supposed to be "table.find()" equivalent. Check it
    bool findKeyCoordinates(char target, int &outRow, int &outCol) { //i dont get this part, check later
      for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
          if (keys[r][c] == target) {
            outRow = r;
            outCol = c;
            return true; //found key
          }
        }
      }
      return false; //didnt find key (?)
    }




void loop() {
  const long interval = 1000;

  float vol = (float)analogRead(15)/4092.0f;
  int value1 = analogRead(4);
  int value2 = analogRead(5);
  int value3 = analogRead(6);
  int value4 = analogRead(7);

  char key = keypad.getKey();
  if (key != NO_KEY) {
    int r = -1; int c = -1;
    Serial.print("Pressed key: ");
    Serial.println(key);

    if (findKeyCoordinates(key, r, c));

    int key_number = (r*5)+c;
    int n = key_number - 11;

    //u should make the knobs modify in the negative direction aswell

    int key_Hz = 440.0 * pow(2.0, (float)n/12.0);
    int Hz_mods = ((value1+value2+value3+value4)/16);
    int value = key_Hz + Hz_mods;

    tone(BUZZER,value , 20); // plays "value" Hz tone for 100ms
    Serial.print("played "); Serial.print(String(value)); Serial.println(" hz sound");
  }

  unsigned long rn = millis();
  if (rn - then >= interval) {
    then = rn;
    Serial.print("1: ");
    Serial.print(value1); Serial.print(" 2: ");
    Serial.print(value2); Serial.print(" 3: ");
    Serial.print(value3); Serial.print(" 4: ");
    Serial.println(value4); 


    // i tried to imitate Amplifier by putting 2 buzzers and labeling as R and L, but apparently
    // esp32 can't run 2 tone() commands at the same time. When you write 2 of them below each other,
    // the first one gets overridden.
    Serial.print("vol: "); Serial.println(vol);
  }
  delay(10);
}