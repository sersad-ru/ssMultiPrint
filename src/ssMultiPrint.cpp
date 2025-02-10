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
