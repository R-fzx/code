# include <bits/stdc++.h>
# define ll long long

using namespace std;

int n;
ll a = 0x3f3f3f3f, ans;

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  scanf("%d", &n);
  for (ll i = 1, in; i <= n; i++) {
    scanf("%lld", &in);
    a = min(a, in);
    ans += a;
  }
  printf("%lld", ans);
}
