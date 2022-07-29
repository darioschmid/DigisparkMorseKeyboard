/*
 * Digispark USB Morse Keyboard
 *
 * I used this script to power my "Maludo Uno", a compact, single key Keyboard:
 * 
 * This is based on Ralf Beesner's Digispark-Morse-Keyboard (http://www.elektronik-labor.de/Arduino/Digispark-Morsekeyboard.html)
 * which is itself based on "morse code decoder" by Burkhard Kainka.
 * If you want to do this without the Digispark (just with AtTiny85), check out Ralf Beesner's website.
 * 
 * I completed the morse code character set by adding: ; ! _ ( ) ' @
 * I also added seamless integration for both US and DE Keyboard Layouts.
 * You can get a complete list of all available morse code characters by holding down the Morse Key for 2 sec, or here:
 * https://github.com/maludo99/DigisparkMorseKeyboard/blob/master/MorseCodes.txt
 * 
 * Although all the letters should work on all QWERTY/QWERTZ style keyboards, there is currently no support for special characters for other Keyboard Layouts.
 * 
 * 
 * Attach the Key to Pin 0
 * Attach an LED and current limiting resistor to Pin 1 (ignore this if you use a Digispark, there's already a LED built in)
 * Attach the Speed Switch to Pin 2
 * 
 * You may adjust "KeyPin", "ledPin" and "SpeedSwitch", but keep in mind that Pins 3 and 4 are already used by the USB interface,
 * Pin 5 may act as reset button, and on Pin 1 there is a built-in LED on the Digispark
 * 
 * By pulling the Speed Switch Pin low, you deactivate automatic space insertion between words and you morse at a slower Speed.
 * The Slow Speed is recommended for beginners, because you can take your time to look up the next letter's morse code
*/

#define USB_CFG_DEVICE_NAME 'M','a','l','u','d','o','U','n','o'
#define USB_CFG_DEVICE_NAME_LEN 9

//Set "DeLayout" to 1 if you are using a german Keyboard, set it to 0 if you use a US Keyboard
#define DeLayout 1


#if DeLayout == 1
#include "morsetoasciiDE.h"
#else
#include "morsetoascii.h"
#endif
#include <DigiKeyboard.h>



#define KeyPin 0
#define ledPin 1
#define SpeedSwitch 2

//Adjust "fastSpeedValue" and "slowSpeedValue" to your liking. Note that higher values means slower speed.
#define fastSpeedValue 45
#define slowSpeedValue 60

//Debounce time, 15ms seems to be a good value
#define debounce 15


static unsigned int morsechar;
static unsigned int timepressed;
static unsigned int timenotpressed;
static unsigned short charactercode;
static unsigned int idling;

static unsigned int dithalf;
static unsigned int tpconst;
static unsigned int tnpconst;
static unsigned int iconst;

bool key;
bool ini = true;
bool autoSpace = true;
bool fastSpeed = true;
bool pendingBS = false;
bool pendingSpace = false;
bool noPendingSpace = false;



void setup() {
  DigiKeyboard.sendKeyStroke(0);
  pinMode(ledPin, OUTPUT);
  pinMode(KeyPin, INPUT_PULLUP);
  pinMode(SpeedSwitch, INPUT_PULLUP);
}

void printdisplay(void) {

  if (charactercode == 0b1000111000) {
    DigiKeyboard.print("SOS");
    pendingSpace = false;
    return;
  }

  morsechar = morsetable[charactercode];

  //Press Backspace if necessary
  if (pendingBS) {
    DigiKeyboard.write(0x08);
    pendingBS = false;
  }

  //Press Spacebar if necessary
  if (pendingSpace && !ini && (morsechar != 0x08) && !noPendingSpace && digitalRead(SpeedSwitch)) {
    DigiKeyboard.write(char(0x20));
    pendingSpace = false;
  }

  noPendingSpace = ((morsechar == 0x08) || (morsechar == 0x0A));

  //Type "@" Character if necessary using the German Keyboard Layout
  if (DeLayout && (morsechar == 0x01)) {
    DigiKeyboard.sendKeyStroke(0x2D, MOD_ALT_LEFT | MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
    pendingSpace = false;
    return;
  }

  //Type Eszett/Doppel-S/"ß" Character if necessary using the German Keyboard Layout
  if (DeLayout && (morsechar == 0x02)) {
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_ALT_LEFT | MOD_CONTROL_LEFT);
    pendingSpace = false;
    return;
  }

  DigiKeyboard.write(morsechar);
  pendingSpace = false;
}


void getkey(void) {
  key = !digitalRead(KeyPin);
  if (key != 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}


void getkeytimes(void) {
  timepressed = 0;
  timenotpressed = 0;
  idling = 0;
  do {
    getkey();
    DigiKeyboard.delay (1);
    idling++;
  } while (key == 0);

  do {
    DigiKeyboard.delay(1);
    timepressed++;
    getkey();
  } while (key > 0);

  do {
    DigiKeyboard.delay(1);
    timenotpressed++;
    getkey();
  } while ((key == 0) & (timenotpressed < tnpconst));
}




void loop() {
  fastSpeed = digitalRead(SpeedSwitch);
  if (fastSpeed) {
    dithalf = fastSpeedValue;
    autoSpace = true;
  } else {
    dithalf = slowSpeedValue;
    autoSpace = false;
  }

  tpconst = dithalf * 4;                                     // 1.5 * Dit; maximum tinme for a dit
  tnpconst = dithalf * 4;                                    // 2 * Dit; minimum time for a dah
  iconst = dithalf * 10;                                     // space between words
  charactercode = 1;

  do {
    getkeytimes();
    if ((idling > iconst) && autoSpace) { // inserts space between morse words
      //printdisplay();                  // may be deactivated if you want to insert spaces only by <AS>
      pendingSpace = true;
    }
    if (timepressed > 1300) {
      if (DeLayout) {
        DigiKeyboard.println("https://github.com&darioschmid&DigisparkMorseKezboard&blob&master&MorseCodes.txt");
      } else {
        DigiKeyboard.println("https://github.com/darioschmid/DigisparkMorseKeyboard/blob/master/MorseCodes.txt");
      }
      charactercode = 1;
      pendingSpace = false;
    } else if (timepressed > debounce) {
      charactercode = charactercode << 1;
      if (timepressed > tpconst) {
        charactercode++;
      }
    }
  }
  while (timenotpressed < tnpconst);
  printdisplay();
  ini = false;
}
