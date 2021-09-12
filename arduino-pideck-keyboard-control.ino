/*
ARDUINO - PiDeck Keyboar Emulation
*/

#include <Keyboard.h>

//---------------------------------------------------------
//                           Setup
//---------------------------------------------------------

void setup() {
pinMode(2,INPUT_PULLUP);  // SHIFT
pinMode(3,INPUT_PULLUP);  // UP
pinMode(4,INPUT_PULLUP);  // DOWN

pinMode(5,INPUT_PULLUP);  // CUE
pinMode(6,INPUT_PULLUP);  // ENTER
pinMode(7,INPUT_PULLUP);  // RESET

Serial.begin(9600);       // begin serial comms for debugging

}


void loop() {
 Keyboard.begin();
  if (digitalRead(3) == 0 && digitalRead(2) == 0){ // PAGE UP (SHIFT UP)
    Keyboard.press(KEY_PAGE_UP);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(4) == 0 && digitalRead(2) == 0){ // PAGE DOWN (SHIFT DOWN)
    Keyboard.press(KEY_PAGE_DOWN);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(3) == 0)  // UP
  {
    Keyboard.press(KEY_UP_ARROW);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(4) == 0){ // DOWN
    Keyboard.press(KEY_DOWN_ARROW);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(5) == 0){  // CUE
    Keyboard.press(KEY_F2);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(6) == 0 && digitalRead(2) == 0)  // ENTER KEY (SHIFT OK)
  {
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(6) == 0)  // LOAD - OK
  {
    Keyboard.press(KEY_F1);
    delay(200);
    Keyboard.releaseAll();
  }
  else if (digitalRead(7) == 0)  // Rescan
  {

    Keyboard.press(KEY_RIGHT_ARROW);
    delay(200);
    Keyboard.releaseAll();
    delay(200);
    Keyboard.press(KEY_LEFT_CTRL);
    delay(200);
    Keyboard.releaseAll();
  }


  Keyboard.end();
}
