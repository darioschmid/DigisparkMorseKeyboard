# DigisparkMorseKeyboard

This is a Morse Code USB Keyboard Arduino script for the Digispark.\
\
This is based on Ralf Beesner's [Digispark-Morse-Keyboard](http://www.elektronik-labor.de/Arduino/Digispark-Morsekeyboard.html) which is itself based on "morse code decoder" by Burkhard Kainka.\
If you want to do this without the Digispark (just with AtTiny85), check out Ralf Beesner's website.\
\
I completed the morse code character set by adding: ; ! _ ( ) ' @\
I also added seamless integration for both US and DE Keyboard Layouts.\
You can get a complete list of all available morse code characters at [./MorseCodes.txt](https://raw.githubusercontent.com/maludo99/DigisparkMorseKeyboard/master/Morse.txt).\
Although all the letters should work on all QWERTY/QWERTZ style keyboards, there is currently no support for special characters for other Keyboard Layouts.


## Wiring

* Attach the Key to Pin 0
* Attach an LED and current limiting resistor to Pin 1 (ignore this if you use a Digispark, there's already a LED built in)
* Attach the Speed Switch to Pin 2

![Picture](https://github.com/maludo99/DigisparkMorseKeyboard/blob/master/Images/MaludoUnoFritzing.jpg?raw=true)

Alternatively, you can use my [Maludo Uno](https://github.com/maludo99/MaludoUno) custom PCB:

<!--- ![Picture2]() --->


## How it works

Follow the official [Digispark setup](https://digistump.com/wiki/digispark/tutorials/connecting) guide for setting up the Arduino IDE and installing drivers.
