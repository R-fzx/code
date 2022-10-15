#include <iostream>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
using ll = long long;
const int kN = 2e3 + 5, kM = 1e9 + 7;

int n, m, k, ans, a[kN][kN], f[kN], b[kN], c[kN << 1];
int Q (int a, ll b) {
  ll r = 1;
  for ( ; b; (b & 1) && (r = 1ll * r * a % kM), a = 1ll * a * a % kM, b >>= 1) {}
  return r;
}
int main () {
  file ("painting");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m >> k;
  if (m == 1) {
    ans = Q (k, n);
  } else {
    for (int i = 0; i <= n; i++) {
      a[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % kM;
      }
    }
    for (int i = 1; i <= n; i++) {
      f[i] = Q (i, n);
      for (int j = 1; j < i; j++) {
        f[i] = (f[i] - 1ll * f[j] * a[i][j] % kM + kM) % kM;
      }
    }
    b[0] = c[0] = 1;
    for (int i = 1; i <= n; i++) {
      b[i] = 1ll * b[i - 1] * Q (i, kM - 2) % kM;
    }
    for (int i = 1; i <= n * 2 && i <= k; i++) {
      c[i] = 1ll * c[i - 1] * (k - i + 1) % kM;
    }
    for (int i = 0, r; i <= n; i++) {
      r = Q (i, 1ll * n * (m - 2));
      for (int j = 0; i + j <= n && i + j * 2 <= k; j++) {
        ans = (ans + 1ll * c[i + j * 2] * b[j] % kM * b[j] % kM * b[i] % kM * f[i + j] % kM * f[i + j] % kM * r) % kM;
      }
    }
  }
  put (ans);
  return 0;
}

/*

1 1 1
1 1 1

1 1 1
2 2 2

1 1 1
2 1 2

2 2 2
2 2 2

2 2 2
1 1 1 

2 2 2
1 2 1

1 2 2
2 1 1

1 2 2
2 2 1



*/