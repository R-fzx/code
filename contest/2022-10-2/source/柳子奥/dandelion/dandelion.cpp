#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxN = 4e4 + 5, kMaxB = 2e2 + 5;

int n, m, lst, kk, sz, ct;
int a[kMaxN], b[kMaxN];
int bel[kMaxN], L[kMaxB], R[kMaxB], mx[kMaxB][kMaxB], num[kMaxB][kMaxB], cnt[kMaxN], cc[kMaxB][kMaxN];

void prework() {
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  kk = unique(b + 1, b + 1 + n) - (b + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + 1 + kk, a[i]) - b;
  }
// =======
  sz = sqrt(n);
  if (n % sz == 0) ct = n / sz;
  else ct = n / sz + 1;
  for (int i = 1; i <= ct; ++i) {
    L[i] = R[i - 1] + 1, R[i] = min(i * sz, n);
    for (int j = 1; j <= kk; ++j) {
      cc[i][j] = cc[i - 1][j];
    }
    for (int j = L[i]; j <= R[i]; ++j) {
      bel[j] = i;
      ++cc[i][a[j]];
    }
  }
  for (int i = 1; i <= ct; ++i) {
    mx[i][i - 1] = 0, num[i][i - 1] = 1e9;
    for (int j = i; j <= ct; ++j) {
      mx[i][j] = mx[i][j - 1], num[i][j] = num[i][j - 1];
      for (int k = L[j]; k <= R[j]; ++k) {
        ++cnt[a[k]];
        if (cnt[a[k]] > mx[i][j]) {
          mx[i][j] = cnt[a[k]], num[i][j] = a[k];
        } else if (cnt[a[k]] == mx[i][j] && a[k] < num[i][j]) {
          num[i][j] = a[k];
        }
      }
    }
    fill(cnt + 1, cnt + 1 + n, 0);
  }
}

int solve(int l, int r) {
  int x = bel[l], y = bel[r], mxx = 0, numm = 1e9;
  if (x == y) {
    for (int i = l; i <= r; ++i) {
      ++cnt[a[i]];
      if (cnt[a[i]] > mxx) {
        mxx = cnt[a[i]], numm = a[i];
      } else if (cnt[a[i]] == mxx && a[i] < numm) {
        numm = a[i];
      }
    }
    for (int i = l; i <= r; ++i) {
      cnt[a[i]] = 0;
    }
  } else {
    mxx = mx[x + 1][y - 1], numm = num[x + 1][y - 1];
    for (int i = l; i <= R[x]; ++i) {
      if (y - 1 >= x + 1) cnt[a[i]] = cc[y - 1][a[i]] - cc[x][a[i]];
    }
    for (int i = L[y]; i <= r; ++i) {
      if (y - 1 >= x + 1) cnt[a[i]] = cc[y - 1][a[i]] - cc[x][a[i]];
    }
    for (int i = l; i <= R[x]; ++i) {
      ++cnt[a[i]];
      if (cnt[a[i]] > mxx) {
        mxx = cnt[a[i]], numm = a[i];
      } else if (cnt[a[i]] == mxx && a[i] < numm) {
        numm = a[i];
      }
    }
    for (int i = L[y]; i <= r; ++i) {
      ++cnt[a[i]];
      if (cnt[a[i]] > mxx) {
        mxx = cnt[a[i]], numm = a[i];
      } else if (cnt[a[i]] == mxx && a[i] < numm) {
        numm = a[i];
      }
    }
    for (int i = l; i <= R[x]; ++i) {
      cnt[a[i]] = 0;
    }
    for (int i = L[y]; i <= r; ++i) {
      cnt[a[i]] = 0;
    }
  }
  return numm;
}

int main() {
  freopen("dandelion.in", "r", stdin);
  freopen("dandelion.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  prework();
  for (int i = 1, l, r; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    l = (l + lst - 1) % n + 1, r = (r + lst - 1) % n + 1;
    if (l > r) swap(l, r);
    // debug(l, r);
    printf("%d\n", lst = b[solve(l, r)]);
  }
  // cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}