#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001, kInf = 1e8;

int n, m, p[kN], t, v[kN], f[kN];
LL a[kN], d[kN], ans;
vector<Pii> e[kN];

int F(int x) {
  // if (v[x] ^ t) {
    v[x] = t;
    for (auto &i : e[x]) {
      if (v[i.first] ^ t) {
        if (a[x] + a[i.first] == i.second) {
          v[i.first] = t, f[i.first] = x;
          if (!p[i.first]) {
            return i.first;
          }
          f[p[i.first]] = i.first;
          int r = F(p[i.first]);
          if (r) {
            return r;
          }
        } else {
          d[x] = min(d[x], a[x] + a[i.first] - i.second);
        }
      }
    }
  // }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  fill_n(a + 1, n, -kInf);
  for (int i = 1, x, y, v; i <= m; ++i) {
    cin >> x >> y >> v;
    e[x].emplace_back(y + n, v), e[y + n].emplace_back(x, v), a[x] = max(a[x], (LL)v);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      d[j] = kInf, f[j] = f[j + n] = 0;
    }
    ++t;
    for (int l = F(i);;) {
      if (l) {
        for (; l; p[l] = f[l], p[f[l]] = l, l = f[f[l]]) {
        }
        break;
      }
      LL z = kInf;
      for (int j = 1; j <= n; ++j) {
        if (v[j] == t) {
          z = min(z, d[j]);
        }
      }
      for (int j = 1; j <= n; ++j) {
        if (v[j] == t) {
          a[j] -= z, d[j] -= z;
        }
        if (v[j + n] == t) {
          a[j + n] += z;
        }
      }
      for (int j = 1; j <= n; ++j) {
        if (!d[j]) {
          d[j] = kInf, l = F(j);
          if (l) {
            break;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n + n; ++i) {
    ans += a[i];
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    cout << p[i + n] << " ";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}