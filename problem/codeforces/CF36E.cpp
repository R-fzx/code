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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 10001;

int n, m, _f[kN], t[kN], c[kN], ct;
vector<Pll> e[kN], ans[2];
bool l[kN];
Pll _e[kN];

void D(int x, int y, int o) {
  // fprintf(stderr, "D(%d, %d, %d) Start. ct = %d\n", x, y, o, ct);
  bool b = 0;
  for (;;) {
    for (; t[x] < e[x].size() && !l[e[x][t[x]].second]; ++t[x]) {
    }
    if (t[x] == e[x].size()) {
      break;
  }
    b = 1, l[e[x][t[x]].second] = 0, D(e[x][t[x]].first, e[x][t[x]].second, o);
  }
  if (!b && ct++) {
    ct = 0, l[y] = 1, --t[_e[y].first], --t[_e[y].second], D(x, 0, 1);
  } else {
    ans[o].emplace_back(x, y);
  }
  // fprintf(stderr, "D(%d, %d, %d) End. ct = %d\n", x, y, o, ct);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m;
  if (m == 1) {
    cout << -1;
  } else {
    for (int i = 1; i <= m; ++i) {
      cin >> _e[i].first >> _e[i].second;
      int &x = _f[_e[i].first], &y = _f[_e[i].second];
      !x && (x = ++n), !y && (y = ++n), e[x].emplace_back(y, i), e[y].emplace_back(x, i), ++c[x], ++c[y], l[i] = 1;
    }
    int s = 1, _c = count_if(c + 1, c + n + 1, [](int x) { return x & 1; });
    if (_c > 4) {
      cout << -1;
    } else {
      for (int i = 1; i <= n; ++i) {
        if (c[i] & 1) {
          s = i;
          break;
        }
      }
      // cout << s << endl;
      D(s, 0, 0);
      // for (auto i : ans[0]) {
      //   cout << i.first << " " << i.second << endl;
      // }
      // cout << endl;
      s = 0;
      for (int i = 1; i <= n; ++i) {
        // cout << t[i] << " " << e[i].size() << endl;
        if (t[i] < e[i].size() && (_c > 2 ? (c[i] & 1) : 1)) {
          s = i;
          break;
        }
      }
      // cout << s << endl;
      if (s) {
        ct = 0, D(s, 0, 1);
        // for (auto i : ans[1]) {
        //   cout << i.first << " " << i.second << endl;
        // }
        // cout << endl;
      }
      if ((_c == 0 || _c == 2) && ans[1].empty()) {
        if (ans[0].size() - 1 < m) {
          cout << -1;
        } else {
          cout << 1 << endl
               << ans[0][ans[0].size() - 2].second << endl
               << ans[0].size() - 2 << endl;
          for (auto i = ans[0].rbegin() + 2; i != ans[0].rend(); ++i) {
            cout << i->second << endl;
          }
        }
      } else {
        if (ans[0].size() + ans[1].size() - 2 < m) {
          cout << -1;
        } else {
          for (int i = 0; i < 2; ++i) {
            ans[i].pop_back();
            cout << ans[i].size() << endl;
            for (auto j : ans[i]) {
              cout << j.second << endl;
            }
          }
        }
      }
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}