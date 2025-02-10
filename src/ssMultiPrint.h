/*
Arduino MultiPrint Library
(c)2025 by Sergey Sadovnikov (sersad@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <www.gnu.org/licenses/>.
*/


/*
* Вывод нескольких значений в поток.
* 
* ВНИМАНИЕ!!! 
* В варинте с constexprsizeof требуется включение поддержки синтаксиса 
* c++17 компилятором.
*
* В файле: ...packages/arduino/hardware/avr/1.8.6/platform.txt: 
* В списке значений параметра compiler.cpp.flags= 
* Меняем текущее значение на -std=gnu++17 (или -std=c++17)
* При обновлении среды может слететь. Надо следить!!!
*/

#pragma once
#include <Arduino.h>


void ssMultiPrint(Print &p); // Остановка рекурсии, нужно при отказе от sizeof и constexpr

template <typename T, typename ... Rest>
void ssMultiPrint(Print &p, T first, Rest ... rest){
  p.print(first);
//  if constexpr(sizeof...(rest) > 0) ssMultiPrint(p, rest...);
  ssMultiPrint(p, rest...);
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


template <typename T>
void ssFixedPrint(Print &p, T val, T scale = 10){
  p.print(val / scale);
  p.print('.');
  p.print(abs(val % scale)); 
}//ssFixedPrint


template <typename T>
void ssFixedPrintln(Print &p, T val, T scale = 10){
  ssFixedPrint(p, val, scale);
  p.println();
}//ssFixedPrint
