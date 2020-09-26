unsigned char morsetable[] = {
/*00000000,         */ 0x0,
/*00000001,         */ 0x20,          // Space
/*00000010,       . */ 0x45,          // "E"
/*00000011,       - */ 0x54,          // "T"
/*00000100,      .. */ 0x49,          // "I"
/*00000101,      .- */ 0x41,          // "A"
/*00000110,      -. */ 0x4E,          // "N"
/*00000111,      -- */ 0x4D,          // "M"
/*00001000,     ... */ 0x53,          // "S"
/*00001001,     ..- */ 0x55,          // "U"
/*00001010,     .-. */ 0x52,          // "R"
/*00001011,     .-- */ 0x57,          // "W"
/*00001100,     -.. */ 0x44,          // "D"
/*00001101,     -.- */ 0x4B,          // "K"
/*00001110,     --. */ 0x47,          // "G"
/*00001111,     --- */ 0x4F,          // "O"
/*00010000,    .... */ 0x48,          // "H"
/*00010001,    ...- */ 0x56,          // "V"
/*00010010,    ..-. */ 0x46,          // "F"
/*00010011,    ..-- */ 0x7B,          // "Ü" already german
/*00010100,    .-.. */ 0x4C,          // "L"
/*00010101,    .-.- */ 0x27,          // "Ä" already german
/*00010110,    .--. */ 0x50,          // "P"
/*00010111,    .--- */ 0x4A,          // "J"
/*00011000,    -... */ 0x42,          // "B"
/*00011001,    -..- */ 0x58,          // "X"
/*00011010,    -.-. */ 0x43,          // "C"
/*00011011,    -.-- */ 0x5A,          // "Y" becomes "Z"
/*00011100,    --.. */ 0x59,          // "Z" becomes "Y"
/*00011101,    --.- */ 0x51,          // "Q"
/*00011110,    ---. */ 0x84,          // "Ö" already german
/*00011111,    ---- */ 0x20,          // Space
/*00100000,   ..... */ 0x35,          // "5"
/*00100001,   ....- */ 0x34,          // "4"
/*00100010,   ...-. */ 0x0,
/*00100011,   ...-- */ 0x33,          // "3"
/*00100100,   ..-.. */ 0x0,
/*00100101,   ..-.- */ 0x0,
/*00100110,   ..--. */ 0x0,
/*00100111,   ..--- */ 0x32,          // "2"
/*00101000,   .-... */ 0x20,          // Space ("as")
/*00101001,   .-..- */ 0x0,
/*00101010,   .-.-. */ 0x5D,          // "+" becomes "]"
/*00101011,   .-.-- */ 0x0,
/*00101100,   .--.. */ 0x0,
/*00101101,   .--.- */ 0x0,
/*00101110,   .---. */ 0x0,
/*00101111,   .---- */ 0x31,          // "1"
/*00110000,   -.... */ 0x36,          // "6"
/*00110001,   -...- */ 0x29,          // "=" becomes ")"
/*00110010,   -..-. */ 0x26,          // "/" becomes "&"
/*00110011,   -..-- */ 0x0,
/*00110100,   -.-.. */ 0x0,
/*00110101,   -.-.- */ 0x0,
/*00110110,   -.--. */ 0x2A,          // "(" becomes "*"
/*00110111,   -.--- */ 0x0,
/*00111000,   --... */ 0x37,          // "7"
/*00111001,   --..- */ 0x0,
/*00111010,   --.-. */ 0x0,
/*00111011,   --.-- */ 0x0,
/*00111100,   ---.. */ 0x38,          // "8"
/*00111101,   ---.- */ 0x0,
/*00111110,   ----. */ 0x39,          // "9"
/*00111111,   ----- */ 0x30,          // "0"
/*01000000,  ...... */ 0x08,          // Backspace
/*01000001,  .....- */ 0x0,
/*01000010,  ....-. */ 0x0,
/*01000011,  ....-- */ 0x0,
/*01000100,  ...-.. */ 0x0,
/*01000101,  ...-.- */ 0x0D,          // Enter ("sk")
/*01000110,  ...--. */ 0x0,
/*01000111,  ...--- */ 0x0,
/*01001000,  ..-... */ 0x0,
/*01001001,  ..-..- */ 0x0,
/*01001010,  ..-.-. */ 0x0,
/*01001011,  ..-.-- */ 0x0,
/*01001100,  ..--.. */ 0x5F,          // "?" becomes "_"
/*01001101,  ..--.- */ 0x3F,          // "_" becomes "?"
/*01001110,  ..---. */ 0x0,
/*01001111,  ..---- */ 0x0,
/*01010000,  .-.... */ 0x0,
/*01010001,  .-...- */ 0x0,
/*01010010,  .-..-. */ 0x40,          // """ becomes "@"
/*01010011,  .-..-- */ 0x0,
/*01010100,  .-.-.. */ 0x0,
/*01010101,  .-.-.- */ 0x2E,          // "."
/*01010110,  .-.--. */ 0x0,
/*01010111,  .-.--- */ 0x0,
/*01011000,  .--... */ 0x0,
/*01011001,  .--..- */ 0x0,
/*01011010,  .--.-. */ 0x02,          // "@" special code to catch in printdisplay()
/*01011011,  .--.-- */ 0x0,
/*01011100,  .---.. */ 0x0,
/*01011101,  .---.- */ 0x0,
/*01011110,  .----. */ 0x0,
/*01011111,  .----- */ 0x0,
/*01100000,  -..... */ 0x0,
/*01100001,  -....- */ 0x2F,          // "-" becomes "/"
/*01100010,  -...-. */ 0x0,
/*01100011,  -...-- */ 0x0,
/*01100100,  -..-.. */ 0x0,
/*01100101,  -..-.- */ 0x0,
/*01100110,  -..--. */ 0x0,
/*01100111,  -..--- */ 0x0,
/*01101000,  -.-... */ 0x0,
/*01101001,  -.-..- */ 0x0,
/*01101010,  -.-.-. */ 0x3C,          // ";" becomes "<"
/*01101011,  -.-.-- */ 0x21,          // "!"
/*01101100,  -.--.. */ 0x0,
/*01101101,  -.--.- */ 0x28,          // ")" becomes "("
/*01101110,  -.---. */ 0x0,
/*01101111,  -.---- */ 0x0,
/*01110000,  --.... */ 0x0,
/*01110001,  --...- */ 0x0,
/*01110010,  --..-. */ 0x0,
/*01110011,  --..-- */ 0x2C,          // ","
/*01110100,  --.-.. */ 0x0,
/*01110101,  --.-.- */ 0x0,
/*01110110,  --.--. */ 0x0,
/*01110111,  --.--- */ 0x0,
/*01111000,  ---... */ 0x3E,          // ":" becomes ">"
/*01111001,  ---..- */ 0x0,
/*01111010,  ---.-. */ 0x0,
/*01111011,  ---.-- */ 0x0,
/*01111100,  ----.. */ 0x0,
/*01111101,  ----.- */ 0x0,
/*01111110,  -----. */ 0x0,
/*01111111,  ------ */ 0x0,
/*10000000, ....... */ 0x08,          // Backspace
/*10000001, ......- */ 0x0,
/*10000010, .....-. */ 0x0,
/*10000011, .....-- */ 0x0,
/*10000100, ....-.. */ 0x0,
/*10000101, ....-.- */ 0x0,
/*10000110, ....--. */ 0x0,
/*10000111, ....--- */ 0x0,
/*10001000, ...-... */ 0x0,
/*10001001, ...-..- */ 0x0,
/*10001010, ...-.-. */ 0x0,
/*10001011, ...-.-- */ 0x0,
/*10001100, ...--.. */ 0x01,          // "ß" special code to catch in printdisplay()
};
