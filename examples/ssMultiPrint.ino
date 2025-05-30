/*
 * Пример использования ssMultiPrint
 *
 * (c)2025 by sersad.ru 
 * 28.01.2025
 * 06.02.2025
 * 
*/

#include <ssMultiPrint.h>

uint8_t arr[] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  Serial.begin(9600);
  ssMultiPrintln(Serial, F("Some String and numbers: "), 10, ',', 42, " and more string"); // Some String and numbers: 10,42 and more string
  ssHexArrayPrintln(Serial, arr, 4, ':'); // 0xDE:0xAD:0xBE:0xEF
  ssHexArrayPrintln(Serial, arr, 4, ':', false); // DE:AD:BE:EF
  ssArrayPrintln(Serial, arr, 4); // 222 173 190 239
  ssFixedPrintln(Serial, -4288, 100); // -42.88
  ssFixedPrintln(Serial, 366); // 36.6
  ssUnicodeCharPrint(Serial, 0x1F4CC); // the red pushpin symbol "📌"
  Serial.println(ssGetCharCount(2147483648, 10)); // 10
  ssAlignPrintln(Serial, 42, 10); // "        42"
  ssAlignPrintln(Serial, 42, 10, ALIGN_LEFT); // "42        "
  ssAlignPrintln(Serial, 42, 10, ALIGN_CENTER); // "    42    "
}

void loop() {
}

