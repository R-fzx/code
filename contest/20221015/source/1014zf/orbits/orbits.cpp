#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3005, mod = 10007;

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll n, m, k, cnt, a[N], o;

void dfs(ll t, ll ji) {
  if (t == n + 1) {
    if (gcd(ji, k * k) == k) {
      cnt++;
    }
    return;
  }
  for (int i = 1; i <= m; i++) {
    a[t] = i;
    dfs(t + 1, ji * a[t]);
  }
}

int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  cin >> n >> m >> k;
  dfs(1, 1); 
  cout << cnt % mod;
  return 0;
}