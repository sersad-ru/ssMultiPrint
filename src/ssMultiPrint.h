/*
* Вывод нескольких значений в поток.
* 
* ВНИМАНИЕ!!! Требуется включение поддержки синтаксиса c++17 компилятором!!!
* В файле: packages/arduino/hardware/avr/1.8.6/platform.txt: 
* В списке значений параметра compiler.cpp.flags= 
* Меняем текущее значение на -std=gnu++17
* При обновлении может слететь. Надо следить!!!
*/

#pragma once
#include <Arduino.h>


template <typename T, typename ... Rest>
void ssMultiPrint(Print &p, T first, Rest ... rest){
  p.print(first);
  if constexpr(sizeof...(rest) > 0) ssMultiPrint(p, rest...);
}// ssMultiPrint


template <typename ... Args>
void ssMultiPrintln(Print &p, Args ... args){
  ssMultiPrint(p, args...);
  p.println();
}// ssMultiPrintln


template <typename T, typename ST>
void ssArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC){
  for(ST i = 0; i < size; i++){
    p.print(arr[i], base);
    if(i < (size - 1)) p.print(separator);
  }//for
}//ssArrayPrint


template <typename T, typename ST>
void ssArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC){
  ssArrayPrint(p, arr, size, separator, base);
  p.println();
}//ssArrayPrintln


void ssBytePrint(Print &p, uint8_t b);


template <typename T>
void ssHexPrint(Print& p, T val, const uint8_t use_prefix = true){
  if(use_prefix) p.print(F("0x"));
  for(uint8_t i = sizeof(T); i > 0; i--) ssBytePrint(p, (uint8_t)((val >> (i - 1) * 8) & 0xFF));    
}


template <typename T>
void ssHexPrintln(Print& p, T val, const uint8_t use_prefix = true){
  ssHexPrint(p, val, use_prefix);
  p.println();
}//ssHexPrintln


template <typename T, typename ST>
void ssHexArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true){
  for(ST i = 0; i < size; i++){
    ssHexPrint(p, arr[i], use_prefix);
    if(i < (size - 1)) p.print(separator);
  }//for
}//ssHexArrayPrint


template <typename T, typename ST>
void ssHexArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true){
  ssHexArrayPrint(p, arr, size, separator, use_prefix);
  p.println();
}//ssHexArrayPrintln
