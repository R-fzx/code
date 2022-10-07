#include <iostream>

using namespace std;

int a[100000];

int main() {
  int v = 1;
  for (int i = 1;  i< 149; i++) {
    if (a[v]) {
      cout << "shit";
    }
    a[v] = 1;
    cout << v << ' ';
    v = v * 35 % 149;
  }
}