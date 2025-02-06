#include "ssMultiPrint.h"

void ssBytePrint(Print &p, uint8_t b){
  if(b < 16) p.print('0');
  p.print(b, HEX);
}//ssBytePrint
