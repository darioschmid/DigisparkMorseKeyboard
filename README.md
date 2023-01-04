# DigisparkMorseKeyboard

This is a Morse Code USB Keyboard Arduino script for the Digispark.\
\
This is based on Ralf Beesner's [Digispark-Morse-Keyboard](http://www.elektronik-labor.de/Arduino/Digispark-Morsekeyboard.html).\
If you want to do this without the Digispark (just with AtTiny85), check out Ralf Beesner's website.\
\
I completed the morse code character set by adding: ; ! _ ( ) ' @\
I also added seamless integration for both US and DE Keyboard Layouts.\
You can get a complete list of all available morse code characters at [./MorseCodes.txt](https://raw.githubusercontent.com/darioschmid/DigisparkMorseKeyboard/master/MorseCodes.txt).\
Although all the letters should work on all QWERTY/QWERTZ style keyboards, there is currently no support for special characters for other Keyboard Layouts.

## How It Works

Visit [DigisparkMorseCode/MorseCodes.txt](https://raw.githubusercontent.com/darioschmid/DigisparkMorseKeyboard/master/MorseCodes.txt), or open a Text Editor and hold the key down for 4sec. It prints out all available Morse Codes. Hold down the key to switch between DE and US keyboard layout.

Example:

    "M  A   L    U   D   O      U  N   O"
    "-- •- •-•• ••- -•• ---    ••- -• ---"


Setting the Speed Switch to "Fast" activates automatic space insertion between words and allows your "dah's" (long presses) to be shorter.\
If you set the switch to "Slow", you must manually add spaces between words with the morse codes "----" or "•-•••".

## Wiring

* Attach the Key to Pin 0
* Attach an LED and current limiting resistor to Pin 1 (ignore this if you use a Digispark, there's already a LED built in)
* Attach the Speed Switch to Pin 2

![Picture](https://github.com/darioschmid/DigisparkMorseKeyboard/blob/master/Images/MaludoUnoFritzing.jpg?raw=true)

Alternatively, you can use my [Maludo Uno](https://github.com/darioschmid/MaludoUno) custom PCB:

![Picture](https://github.com/darioschmid/DigisparkMorseKeyboard/blob/master/Images/MaludoUno.jpg?raw=true)


## Software Setup

* Follow the official [Digispark setup guide](https://digistump.com/wiki/digispark/tutorials/connecting) for setting up the Arduino IDE and installing drivers.
* Download my Arduino project from [./DigisparkMorseKeyboard](https://github.com/darioschmid/DigisparkMorseKeyboard/tree/master/DigisparkMorseKeyboard) and open it in the Arduino IDE
* Adjust the "DeLayout" variable to reflect your Keyboard Layout
* Go to "Tools" --> "Boards" --> "Digispark Default"
* Go to "Tools" --> "Programmer" --> "Micronucleus"
* Hit Upload, then plug in the Digispark when it says so

Feel free to contact me if you encounter any problems :)


## 

Now you can start morsing! If you are a beginner (like me), flick the speed switch to deactivate the automatic space insertion between words and morsing at a slower speed. That means you have time to look up the Morse Codes for each letter one by one.

You can get a complete overview of all available Morse Codes at [./MorseCodes.txt](https://raw.githubusercontent.com/darioschmid/DigisparkMorseKeyboard/master/MorseCodes.txt) or by opening a text editor and holding the Button for 4 seconds.
 

