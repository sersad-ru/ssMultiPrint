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

void ssMultiPrint(Print &p, const auto &first, const auto&... rest);
void ssMultiPrintln(Print &p, const auto&... rest);