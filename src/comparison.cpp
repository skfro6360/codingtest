#include "comparison.h"

void generateMsg(){
  vector<ZZX> v;
  v.resize(nslots);
  for (long i = 0; i < nslots; i++) {
    GF2X f;
    random(f, n);
    conv(v[i], f);
  } 
}
// Comparison Test over the Integer
// if lessThan = 1, lessThan circuit
// if lessThan = 0, greaterThan circuit
void comparisonTest(){
}
