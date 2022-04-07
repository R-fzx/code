// #pragma optimize(3)
#include <ctime>
#include <iostream>

using namespace std;

int a[1000000];

int main() {
  int p = 1, _c = 4;
  p += ++p == _c;
  cout << p;
  return 0;
}