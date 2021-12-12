#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;

const db PI = acos(-1.0);
const db eps = 1e-5;
const int N = 1e5 + 5;

db angle (db x, db y) {
  if (x == 0 && y > 0) return 90;
  if (x == 0 && y < 0) return 270;
  if (x < 0 && y == 0) return 180;
  if (x > 0 && y == 0) return 0;
  if (x > 0 && y > 0) return atan(1.0 * y / x) / PI * 180;
  if (x < 0 && y > 0) return atan(-1.0 * x / y) / PI * 180 + 90;
  if (x < 0 && y < 0) return atan(1.0 * y / x) / PI * 180 + 180;
  if (x > 0 && y < 0) return atan(-1.0 * x / y) / PI * 180 + 270;
  return 0; 
}

struct Node {
  int x, y;
  db len, ang;

  Node () {}
  Node (int _x, int _y) { 
    x = _x, y = _y;
    len = sqrt(1ll * x * x + 1ll * y * y), ang = angle(x, y);
  }
  friend bool operator < (const Node& n1, const Node& n2) {
    return n1.ang < n2.ang;
  }
} a[N] ;

int n, x, y;
ll cnt;

int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    a[i] = Node(x, y);
  }
  // cout << tan(PI * (1.0 / 3)) << endl;
  // cout << angle(1, sqrt(3)) << endl;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n - 2; ++i)
    for (int j = i + 1; j <= n - 1; ++j)
      for (int k = j + 1; k <= n; ++k)
        if (a[j].ang - a[i].ang < 180 && a[k].ang - a[j].ang < 180 && a[k].ang - a[i].ang > 180)
          ++cnt;
  cout << cnt << endl;
  // cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}