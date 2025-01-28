/*
 * Пример использования ssMultiPrint
 *
 * (c)sersad 2025. 28.01.2025
 * 
*/

#include <ssMultiPrint.h>

void setup() {
  Serial.begin(9600);
  ssMultiPrintln(Serial, F("Some String and numbers: "), 10, 42, " and more string");
}

void loop() {
}

