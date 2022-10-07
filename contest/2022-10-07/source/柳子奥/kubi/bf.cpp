#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...)
#endif

#define int long long
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

int T, a, b, k;
int bit[1000005];

void get(int a, int b) {
  int c = 0;
  map<int, int> vis;
  vis.clear();
  a *= k;
  for (int i = 1; a; a *= k, ++i) {
    bit[i] = a / b;
    a %= b;
    debug(a);
    if (vis[a]) {
      cout << vis[a] - 1 << ' ' << i - vis[a] << endl;
      return ;
    }
    vis[a] = i, c = i;
  }
  if (!a) cout << c << ' ' << 0 << endl;
}

signed main() {
  // file("kubi");
  cin >> T;
  while (T--) {
    cin >> a >> b >> k;
    int d = __gcd(a, b);
    a /= d, b /= d;
    get(a, b);
  }
  return 0;
}