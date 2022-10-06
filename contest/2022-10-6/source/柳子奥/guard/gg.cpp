#include <bits/stdc++.h>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define summary debug("----------- End -----------\n"), \
                debug("Memory %.5lfMB\n", fabs(&m_ed - &m_st) / 1048576), \
                debug("Time %.2lfs\n", clock() * 1.0 / CLOCKS_PER_SEC)

using namespace std;



int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

bool m_st;

typedef double db;

const int kMaxN = 205, kMaxK = 4e4 + 5;

int n, l, k, mx;
int a[kMaxN];
db f[kMaxN], g[kMaxN][kMaxK];

bool m_ed;

int main() {
  // file("guard");
  return summary, 0;
}