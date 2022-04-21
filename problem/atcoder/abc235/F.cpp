#include <atcoder/all>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using mL = modint998244353;
using Pll = pair<mL, mL>;

const int kN = 1e4 + 1, kL = 1024;

string n;
int m, v;
mL f[kN][kL], kP[kN] = {1}, c[kN][kL], px[kN];
bool _v[kN][kL];

Pll D(int x, int b, bool z, bool l, int t = 0) {
  debug("% *sD(%d,%d,%d,%d) Start.\n", t * 2, "", x, b, z, l);
  if (!z && !l && _v[x][b]) {
    debug("% *sD(%d,%d,%d,%d) End.Return {%u,%u}\n", t * 2, "", x, b, z, l, f[x][b].val(), c[x][b].val());
    return {f[x][b], c[x][b]};
  }
  mL s = 0, _c = 0;
  if (!b) {
    _c = (l ? px[x] + 1 : kP[x]), s = (_c - 1) * _c / 2;
  } else {
    if (!x) {
      debug("% *sD(%d,%d,%d,%d) End.Return {%u,%u}\n", t * 2, "", x, b, z, l, 0, 0);
      return {0, 0};
    }
    for (int i = 0, m = l ? n[x] - '0' : 9; i <= m; ++i) {
      debug("% *s%d:\n", t * 2, "", i);
      if (!i && z) {
        Pll p = D(x - 1, b, 1, i == m && l, t + 1);
        s += p.first, _c += p.second;
      } else {
        Pll p = D(x - 1, b & ~(1 << i), 0, i == m && l, t + 1);
        s += kP[x - 1] * i * p.second + p.first, _c += p.second;
      }
    }
  }
  if (!z && !l) {
    _v[x][b] = 1, f[x][b] = s, c[x][b] = _c;
  }
  debug("% *sD(%d,%d,%d,%d) End.Return {%u,%u}\n", t * 2, "", x, b, z, l, s.val(), _c.val());
  return {s, _c};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n.size(); ++i) {
    kP[i] = kP[i - 1] * 10;
  }
  n.push_back(' '), reverse(n.begin(), n.end());
  for (int i = 1; i < n.size(); ++i) {
    px[i] = px[i - 1] + kP[i - 1] * (n[i] - '0');
  }
  for (int x; m--; v |= 1 << x) {
    cin >> x;
  }
  cout << D(n.size() - 1, v, 1, 1).first.val();
  return 0;
}