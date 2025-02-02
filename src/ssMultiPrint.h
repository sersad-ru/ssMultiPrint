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

