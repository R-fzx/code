#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;

int main() {
  int x;
  cin >> x;
  printf("AGC%03d", x + (x >= 42));
  return 0;
}