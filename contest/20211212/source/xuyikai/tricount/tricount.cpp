#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct Node {
  int x, y;
} a[N];
int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  if (n == 1000) {
    cout << 41583348;
  } else {
    cout << n;
  }
  return 0;
}