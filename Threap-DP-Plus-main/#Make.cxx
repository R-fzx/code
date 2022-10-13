#include <iostream>

#include "lib/mrrand.h"

using namespace std;

int main() {
  int c = rd(10);
  for (int i = 0; i < c; ++i) {
    for (int j = 0, l = rd(10); j < l; ++j) {
      cout << char(rd(26) + 'a');
    }
    cout << "agnus";
  }
  for (int j = 0, l = rd(10); j < l; ++j) {
    cout << char(rd(26) + 'a');
  }
  return 0;
}