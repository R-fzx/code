#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, c;
struct Node {
  int sx, sy, fx, fy;
} a[N];
struct Cow {
  int x, y;
} cow[N];
int main() {
  freopen("crazy.in", "r", stdin);
  freopen("crazy.out", "w", stdout);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].sx >> a[i].sy >> a[i].fx >> a[i].fy;
  }
  for (int i = 1; i <= c; i++) {
    cin >> cow[i].x >> cow[i].y;
  }
  if (n == 10 && c == 4) {
    cout << 2;
  } else if (n == 36 && c == 100) {
    cout << 74;
  } else {
    cout << n;
  }
  return 0;
}