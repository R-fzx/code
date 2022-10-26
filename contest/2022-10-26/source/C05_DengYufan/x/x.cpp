#include <algorithm>
#include <iostream>
#define LL long long

using namespace std;

const LL kMaxN = 1e5 + 1;
LL n, ans, d[kMaxN * 20], f[kMaxN];
pair<LL, LL> a[kMaxN];

LL Read() {
  LL x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

LL Ask(LL x) {
  LL ans = 0;
  for (LL i = x + kMaxN * 10; i >= 1; i -= i & -i) {
    ans = max(ans, d[i]);
  }
  return ans;
}

void Change(LL x, LL y) {
  for (LL i = x + kMaxN * 10; i < kMaxN * 20; i += i & -i) {
    d[i] = max(d[i], y);
  }
}

int main() {
  freopen("x.in", "r", stdin);
  freopen("x.out", "w", stdout);
  n = Read();
  for (LL i = 1; i <= n; i++) {
    a[i].first = Read(), a[i].second = Read();
  }
  sort(a + 1, a + n + 1);
  if (n <= 100) {
    for (LL i = 1; i <= n; i++) {
      f[i] = 1;
      for (LL j = 1; j < i; j++) {
        if (a[i].first - a[j].first > a[i].second + a[j].second) {
          f[i] = max(f[i], f[j] + 1);
        }
      }
      ans = max(ans, f[i]);
    }
  } else {
    for (LL i = 1; i <= n; i++) {
      f[i] = Ask(a[i].first - a[i].second - 1) + 1;
      Change(a[i].first + a[i].second, f[i]);
      ans = max(ans, f[i]);
    }
  }
  cout << ans;
  return 0;
}
