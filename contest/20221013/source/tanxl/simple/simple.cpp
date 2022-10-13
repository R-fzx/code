#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 5e5 + 1;
int t, n, q, sum, a, b, minn;
struct node {
  int x, y;
} s[kMaxN];
int main() {
  freopen("simple.in", "r", stdin);
  freopen("simple.out", "w", stdout);
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> s[i].x >> s[i].y;
    }
    while (q--) {
      cin >> a >> b;
      for (int i = 1; i <= n; i++) {
        sum += b - a;
      }
    }
    cout << sum << '\n';
  }
  return 0;
}