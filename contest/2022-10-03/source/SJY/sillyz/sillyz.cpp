#include <iostream>
#include <cstdio>

using namespace std;

long long a, b;
long long ans;

int main() {
  freopen("sillyz.in", "r", stdin);
  freopen("sillyz.out", "w", stdout);
  cin >> a >> b;
  for (int i = 1; i <= b; ++i) {
    int temp = i, x = 1;
    while (temp) {
      x *= temp % 10;
      temp /= 10;
    }


    // cout << x;
    if (x * i != 0 && x * i >= a && x * i <= b) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}