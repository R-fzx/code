#pragma GCC optimize(2)
#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

typedef vector<int> di;

const int kMaxN = 305, kMaxA = 1005;

int n;
int a[kMaxN], sum[kMaxA];
di ans, dd[kMaxN], fac[kMaxN], C[kMaxN][kMaxN], A[kMaxN][kMaxN], K[kMaxN], F[kMaxN];

void print(di x) {
  for (int i = x.size() - 1; ~i; --i) {
    cout << x[i];
  }
  cout << endl;
}

di todi(int x) {
  di tmp;
  tmp.clear();
  if (!x) {
    tmp.emplace_back(0);
    return tmp;
  }
  while (x) {
    tmp.emplace_back(x % 10), x /= 10;
  }
  return tmp;
}

di mul(di a, di b) {
  di c, tmp;
  c.clear();
  c.resize(a.size() + b.size() + 2);
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)b.size(); ++j) {
      c[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < (int)c.size() - 1; ++i) {
    c[i + 1] += c[i] / 10, c[i] %= 10;
  }
  int sz = 1;
  for (sz = c.size() - 1; ~sz; --sz) {
    if (c[sz]) break ;
  }
  tmp.resize(sz + 1);
  for (int i = 0; i <= sz; ++i) {
    tmp[i] = c[i];
  }
  return tmp;
}

di add(di a, di b) {
  di c, tmp;
  c.clear();
  c.resize(max(a.size(), b.size()) + 1);
  for (int i = 0; i < max(a.size(), b.size()); ++i) {
    int r = 0;
    if (i < a.size()) r += a[i];
    if (i < b.size()) r += b[i];
    c[i] += r;
    if (i < c.size() - 1) c[i + 1] += c[i] / 10, c[i] %= 10;
  }
  int sz = 1;
  for (sz = c.size() - 1; ~sz; --sz) {
    if (c[sz]) break ;
  }
  tmp.resize(sz + 1);
  for (int i = 0; i <= sz; ++i) {
    tmp[i] = c[i];
  }
  return tmp;
}

di div(di x, int y) {
  di c, tmp;
  c.clear();
  int nw = 0;
  for (int i = x.size() - 1; ~i; --i) {
    nw = nw * 10 + x[i];
    if (nw >= y) {
      c.emplace_back(nw / y), nw %= y;
    } else {
      if (c.size()) c.emplace_back(0);
    }
  }
  reverse(c.begin(), c.end());
  return c;
}

void getfac() {
  fac[0] = todi(1);
  for (int i = 1; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], todi(i));
  }
  // print(fac[n]);
}

void getc() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (!j) {
        C[i][j] = todi(1);
      } else {
        C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
      }
      // A[i][j] = mul(C[i][j], fac[j]);
    }
  }
  dd[0] = todi(0);
  for (int i = 1; i <= n; ++i) {
    K[i] = mul(fac[i - 1], fac[n - i]);
    dd[i] = todi(i);
    F[i] = mul(fac[i - 1], fac[n - i - 1]);
  }
}

int main() {
  freopen("queue.in", "r", stdin);
  freopen("qq.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++sum[a[i]];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= 1000; ++i) {
    sum[i] += sum[i - 1];
  }
  getfac(), getc();
  // debug("!!!");
  for (int i = 1; i <= n; ++i) {
    // debug(i);
    int v = a[i]; di ss = todi(0);
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k < j; ++k) {
        // debug(j, k);
        if (k == 0) {
          // debug("!!!");
          // if (i == 1) debug(sum[1000] - sum[v]); 
          if (sum[v - 1] < j - 1) continue ;
          // debug("!!!");
          // print(todi(j));
          // print(C[sum[v - 1]][j - 1]);
          // print(mul(fac[j - 1], fac[n - j]));
          ss = add(ss, mul(dd[j], mul(C[sum[v - 1]][j - 1], K[j])));
          // if (i == 1) cout << j << ':', print(ss);
        } else {
          if (sum[v - 1] < j - k - 1) continue ;
          ss = add(ss, mul(dd[j - k], mul(C[sum[v - 1]][j - k - 1], mul(dd[sum[1000] - sum[v - 1] - 1], F[j - k]))));
          // if (i == 1) cout << j << ' ' << k << ':', print(ss);
        }
      }
    }
    // print(ss);
    ans = add(ans, ss);
  }
  // print(ans);
  ans = mul(ans, todi(1000));
  for (int i = 2; i <= n; ++i) {
    ans = div(ans, i);
  }
  // print(ans);
  if (ans[0] >= 5) ++ans[1];
  for (int i = ans.size() - 1; i >= 1; --i) {
    cout << ans[i];
    if (i == 3) cout << '.';
  }
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}