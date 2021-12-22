#include <bits/stdc++.h>

using namespace std;
#define int long long

int x, y, a, b, c;
bool Judge(int x, int y, int a, int b, int c) {
  int s1 = (a + x - 1) / x, s2 = (b + x - 1) / x, s3 = (c + x - 1) / x;
  if (s1 + s2 + s3 <= y) {
    return true;
  }
  if (s1 < y) {
    int temp = y - s1;
    if ((c + temp - 1) / temp + (b + temp - 1) / temp <= x) {
      return true;
    }
  }
  if (s2 < y) {
    int temp = y - s2;
    if ((a + temp - 1) / temp + (c + temp - 1) / temp <= x) {
      return true;
    }
  }
  if (s3 < y) {
    int temp = y - s3;
    if ((b + temp - 1) / temp + (a + temp - 1) / temp <= x) {
      return true;
    }
  }
  return false;
}
signed main() {
  cin >> x >> y >> a >> b >> c;
  if (Judge(x, y, a, b, c) || Judge(y, x, a, b, c)) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
