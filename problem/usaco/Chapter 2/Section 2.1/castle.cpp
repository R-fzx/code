/*
ID: wsfxk.e1
LANG: C++
TASK: castle
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

ifstream fin("castle.in");
ofstream fout("castle.out");

const int kN = 51, kD[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

struct E {
  int c, n;
} e[kN * kN];
int n, m, k, q[kN * kN], h, t, ans[2], s[kN * kN];

int Encode(int x, int y) {
  return x * m + y;
}
Pii Decode(int x) {
  return Pii(x / m, x % m);
}
bool InRange(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
void R(int x, int y) {
  if (InRange(x, y) && e[Encode(x, y)].c == 0) {
    q[++t] = Encode(x, y), e[Encode(x, y)].c = k, ++s[k];
  }
}
void Bfs(int x) {
  for (h = 1, t = 0, R(Decode(x).first, Decode(x).second); h <= t; ++h) {
    int x = Decode(q[h]).first, y = Decode(q[h]).second;
    for (int i = 0; i < 4; ++i) {
      if (e[q[h]].n >> i & 1) {
        R(x + kD[i][0], y + kD[i][1]);
      }
    }
  }
}
int C(int x, int d) {
  int nx = Decode(x).first + kD[d][0], ny = Decode(x).second + kD[d][1];
  return (e[x].n >> d & 1) || !InRange(nx, ny) ? 0 : s[e[x].c] + (e[Encode(nx, ny)].c == e[x].c ? 0 : s[e[Encode(nx, ny)].c]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      fin >> e[Encode(i, j)].n;
      e[Encode(i, j)].n ^= 15;
    }
  }
  for (int i = 0; i <= Encode(n - 1, m - 1); ++i) {
    if (!e[i].c) {
      ++k, Bfs(i);
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     fout << e[Encode(i, j)].c << ' ';
  //   }
  //   fout << '\n';
  // }
  // for (int i = 1; i <= k; ++i) {
  //   fout << s[i] << ' ';
  // }
  // fout << '\n';
  fout << k << endl
       << *max_element(s + 1, s + k + 1) << endl;
  ans[0] = Encode(n - 1, 0), ans[1] = 1;
  for (int j = 0; j < m; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      for (int k = 1; k <= 2; ++k) {
        if (C(Encode(i, j), k) > C(ans[0], ans[1])) {
          ans[0] = Encode(i, j), ans[1] = k;
        }
      }
    }
  }
  fout << C(ans[0], ans[1]) << endl
       << Decode(ans[0]).first + 1 << ' ' << Decode(ans[0]).second + 1 << ' ' << ((ans[1] & 1) ? 'N' : 'E') << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}