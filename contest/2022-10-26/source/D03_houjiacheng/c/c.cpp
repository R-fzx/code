# include <bits/stdc++.h>
# define ll long long

using namespace std;
int n, ans, now;
ll a[100100], mx, d;

void add() {
  int j;
  for (int i = 1; i <= n; i++) {
    ++a[i];
    if (a[i] & 1) {
      ++now;
    } else {
      for (j = 1; ((a[i] >> j) & 1) == 0; j++);
      now -= j - 1;
    }
  }
  ans = min(ans, now);
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    mx = max(mx, a[i]);
  }
  d = min(mx * 5, 501ll);
//  printf("%d", d);
  for (int i = 1; i <= n; i++) {
    a[i] = mx - a[i];
    ll t = a[i];
    while (t) {
      if (t & 1) {
        now++;
      }
      t >>= 1;
    }
  }
  ans = now;
  while (d--) {
    add();
  }
  printf("%d", ans);
}
 
