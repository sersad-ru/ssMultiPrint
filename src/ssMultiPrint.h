/*
* Вывод нескольких значений в поток.
* 
* ВНИМАНИЕ!!! Требуется включение поддержки синтаксиса c++14 компилятором!!!
* В файле: packages/arduino/hardware/avr/1.8.6/platform.txt: 
* В списке значений параметра compiler.cpp.flags= 
* Меняем текущее значение на -std=gnu++14
* При обновлении может слететь. Надо следить!!!
*/

#pragma once
#include <Arduino.h>

template <typename T, typename ... Args>
void ssMultiPrint(Print &p, T value, Args ... args){
  p.print(value);
  if constexpr(sizeof...(args) > 0) ssMultiPrint(p, args...);
}// ssMultiPrint


template <typename ... Args>
void ssMultiPrintln(Print &p, Args ... args){
  ssMultiPrint(p, args...);
  p.println();
}// ssMultiPrintln

