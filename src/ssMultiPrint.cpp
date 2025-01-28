#include "ssMultiPrint.h"

void ssMultiPrint(Print &p, const auto &first, const auto&... rest){
  p.print(first);
  if constexpr(sizeof...(rest) > 0) ssMultiPrint(p, rest...);
}// ssMultiPrint


void ssMultiPrintln(Print &p, const auto&... rest){
  ssMultiPrint(p, rest...);
  p.println();
}// ssMultiPrintln
