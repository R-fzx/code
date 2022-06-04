#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#define id(x) ((x - 1) / bs + 1)

using namespace std;
using LL = long long;

const int kN = 1.5e6 + 1;
const int kB = 4000;

int n, q, bs, c, l[kB], r[kB], _l, _r, v;
LL a[kN], t[kB], b[kN];
char o;

void rebuild(int x) { copy(a + l[x], a + r[x] + 1, b + l[x]), sort(b + l[x], b + r[x] + 1); }

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  bs = sqrt(n * log(n)) + 1, c = (n + bs - 1) / bs;
  for (int i = 1; i <= c; ++i) l[i] = (i - 1) * bs + 1, r[i] = i * bs;
  r[c] = n;
  for (int i = 1; i <= c; ++i) rebuild(i);
  while (q--) {
    cin >> o >> _l >> _r >> v;
    if (o == 'M') {
      if (id(_l) == id(_r)) {
        for (int i = _l; i <= _r; ++i) a[i] += v;
        rebuild(id(_l));
      } else {
        for (int i = _l; i <= r[id(_l)]; ++i) a[i] += v;
        rebuild(id(_l));
        for (int i = l[id(_r)]; i <= _r; ++i) a[i] += v;
        rebuild(id(_r));
        for (int i = id(_l) + 1; i < id(_r); ++i) t[i] += v;
      }
    } else {
      int _c = 0;
      if (id(_l) == id(_r)) {
        for (int i = _l; i <= _r; ++i) _c += a[i] + t[id(i)] >= v;
      } else {
        for (int i = _l; i <= r[id(_l)]; ++i) _c += a[i] + t[id(i)] >= v;
        for (int i = l[id(_r)]; i <= _r; ++i) _c += a[i] + t[id(i)] >= v;
        for (int i = id(_l) + 1; i < id(_r); ++i) _c += bs - (lower_bound(b + l[i], b + r[i] + 1, v - t[i]) - b - l[i]);
      }
      cout << _c << endl;
    }
  }
  return 0;
}
/*
0 1 2 3 4
1 2 4 7 9

*/