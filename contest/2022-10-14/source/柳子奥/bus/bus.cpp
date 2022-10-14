#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

typedef long long ll;

const int kMaxN = 1e5 + 5;

int n; ll ans;
int a[kMaxN], mi[kMaxN];

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  mi[0] = 1e9;
  for (int i = 1; i <= n; ++i) {
    mi[i] = min(mi[i - 1], a[i]);
    ans += mi[i];
  }
  printf("%lld\n", ans);
  return 0;
}