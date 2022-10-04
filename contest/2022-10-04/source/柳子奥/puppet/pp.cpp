#pragma GCC optimize(2)
#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxN = 55;

int n, ans, rr;
int a[kMaxN], b[kMaxN], c[kMaxN], cnt[105], pr[105];
int tt[kMaxN], cs[kMaxN], rnd[1000005];
bool vis[kMaxN];
multiset<int> s;

int rs() {
  random_shuffle(b + 1, b + 1 + n);
  return 1;
}

void solve() {
  memset(pr, 0, sizeof(pr));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = i, ++pr[a[i]];
  }
  int fff = 0, ct = 0;
  ans = 0;
  do {
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]] = pr[a[i]];
      cs[i] = -1;
    }
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
      int x = b[i];
      int ccc = cnt[a[x] - 1] + cnt[a[x]] + cnt[a[x] + 1];
      if (ccc == 0) {
        ++tmp; continue ;
      }
      int rd = rand() % ccc + 1;
      if (rd <= cnt[a[x] - 1]) {
        --cnt[a[x] - 1], cs[i] = a[x] - 1;
      } else if (rd <= cnt[a[x] - 1] + cnt[a[x]]) {
        --cnt[a[x]], cs[i] = a[x];
      } else {
        --cnt[a[x] + 1], cs[i] = a[x] + 1;
      }
    }
    ans = max(ans, tmp);
    // if (tmp == 3) {
    //   // debug(fff);
    //   ++fff;
    //   if (fff > 1) continue ;
    //   for (int i = 1; i <= n; ++i) {
    //     cerr << a[b[i]] << ' ' << cs[i] << endl;
    //   }
    //   cerr << endl;
    // }
    if (++ct == 4e4) break ;
  } while (rs());
  cout << ans << endl;
}

int main() {
  freopen("puppet.in", "r", stdin);
  freopen("puppet.out", "w", stdout);
  srand(time(NULL));
  while (cin >> n) {
    solve();
  }
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}