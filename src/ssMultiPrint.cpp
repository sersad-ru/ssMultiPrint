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

#include "ssMultiPrint.h"

void ssMultiPrint(Print &p){
  p.print("");
}//ssMultiPrint


void ssBytePrint(Print &p, uint8_t b){
  if(b < 16) p.print('0');
  p.print(b, HEX);
}//ssBytePrint


void ssUnicodeCharPrint(Print &p, const uint32_t code){
  if(code < 0x80) { // Нижний диапазон 0xxx.xxxx
    p.print((char)code);
  } else if (code < 0x800){ // 2 байта 110x.xxxx 10xx.xxxx
    p.print((char)(0xC0 | (code >> 6)));
    p.print((char)(0x80 | (code & 0x3F)));
  } else if(code < 0x10000){ // 3 байта 1110.xxxx 10xx.xxxx 10xx.xxxx
    p.print((char)(0xE0 | (code >> 12)));
    p.print((char)(0x80 | ((code >> 6) & 0x3F)));
    p.print((char)(0x80 | (code & 0x3F)));
  } else { // 4 байта 1111.xxxx 1111.xxxx 10xx.xxxx 10xx.xxxx 10xx.xxxx
    p.print((char)(0xF0 | (code >> 18)));
    p.print((char)(0x80 | ((code >> 12) & 0x3F)));
    p.print((char)(0x80 | ((code >> 6) & 0x3F)));
    p.print((char)(0x80 | (code & 0x3F)));
  }//if
}//ssUnicodeCharPrint