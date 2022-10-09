#include <fstream>
#include <iostream>

using namespace std;
int f[1000000];

int main() {
  ofstream cout("test.out");
  for (int i = 1; i <= 100; i++) {
    int tmp = i, temp = i;
    for (; temp;) {
      tmp *= temp % 10, temp /= 10;
    }
    f[tmp]++;
  }
  for (int i = 1; i < 100000; i++) {
    if (f[i]) {
      cout << i << ' ' << f[i] << '\n';
    }
  }
}