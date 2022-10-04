#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)
#define E(i, j) ((i - 1) * c + j) 

using namespace std;
const int kN = 105, kM = kN * kN, kI = 1e9, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

double k, d[kM];
char map[kN][kN];
vector <int> ve[kM];
vector <double> vk[kM];
int T, r, c, s, e, t[kM];
struct Pid {
  int i;
  double w;
  bool operator < (const Pid &a) const {
    return w > a.w;
  }
}; priority_queue <Pid> Q;
void A (int u, int v, double w) {
  ve[u].push_back (v), vk[u].push_back (w), ve[v].push_back (u), vk[v].push_back(w);
}
int main () {
  file ("maze");
  // ios :: sync_with_stdio (false);
  // cin.tie (0), cout.tie (0);

  for (cin >> T; T; T--) {
    cin >> k >> r >> c;
    for (int i = 1; i <= r; i++) {
      char ch;
      for (scanf ("%c", &ch); ch != '\n'; scanf ("%c", &ch)) {}
      for (int j = 1; j <= c; j++) {
        for (scanf ("%c", &ch); ch == '\n'; scanf ("%c", &ch)) {}
        map[i][j] = ch, ch == 'S' && (s = E (i, j)), ch == 'E' && (e = E (i, j));
      }
    }
    double _l = 0, _r = 10;
    for ( ; _r - _l > 1e-7; ) {
      double mid = (_l + _r) / 2;
      for (int i = 1; i <= r * c; i++) {
        ve[i].clear (), vk[i].clear ();
      }
      for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {  
          for (int _d = 0; _d < 4; _d++) {
            int di = i + kD[_d][0], dj = j + kD[_d][1];
            map[i][j] != '#' && map[di][dj] != '#' && (A (E (i, j), E (di, dj), _d >= 2 ? 1 : mid), false);
          }
        }
      }
      fill (d + 1, d + r * c + 1, kI), fill (t + 1, t + r * c + 1, 0);
      for ( ; Q.size (); Q.pop ()) {}
      for (d[s] = 0, Q.push ({s, 0}); !Q.empty (); ) {
        int _h;
        do { _h = Q.top ().i, Q.pop (); } while (t[_h] && !Q.empty ());
        if (!t[_h]) {
          t[_h] = true;
        } else {
          break;
        }
        for (int i = 0; i < ve[_h].size (); i++) {
          if (d[_h] + vk[_h][i] < d[ve[_h][i]]) {
            d[ve[_h][i]] = d[_h] + vk[_h][i], Q.push ({ve[_h][i], d[ve[_h][i]]});
          }
        }
      }
      d[e] > k ? _r = mid : _l = mid;
    }
    cout << fixed << setprecision (5) << _l << '\n';
  }
  return 0;
}