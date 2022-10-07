#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

const int kMaxN = 100001;
int n, m, t, a[kMaxN], b[kMaxN];
LL ans;

inline LL Read() {
  LL x(0);
  char ch(getchar());
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch > '/' && ch < ':') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}

inline LL C(int n, int i, int *d) {
  LL c(0);
  for (int j(i), k(d[j]); j % n + 1 != i; j = j % n + 1) {
    if ((c += abs(k - t / n)) >= ans) {
      break;
    }
    k += d[j % n + 1] - t / n;
  }
  return c;
}

inline LL M(int n, int *d, int k) {
  ans = 1145141919810;
  if (n < 1001) {
    for (int i(1); i <= n; i++) {
      ans = min(ans, C(n, i, d));
    }
  } else {
    bool b[kMaxN] = {};
    while (clock() <= k) {
      int x(rand() * rand() % n + 1);
      for (; b[x]; x++) {
      }
      b[x] = true, ans = min(ans, C(n, x, d));
    }
  }
  return ans;
}

int main() {
  freopen("tanabata.in", "r", stdin);
  freopen("tanabata.out", "w", stdout);
  srand(time(0));
  n = Read(), m = Read(), t = Read();
  for (int i(1); i <= t; i++) {
    a[Read()]++, b[Read()]++;
  }
  if (t % n && t % m) {
    cout << "impossible";
  } else if (!(t % n) && !(t % m)) {
    cout << "both " << M(n, a, 490) + M(m, b, 980);
  } else if (t % n) {
    cout << "colume " << M(m, b, 980);
  } else {
    cout << "row " << M(n, a, 980);
  }
  return 0;
}
