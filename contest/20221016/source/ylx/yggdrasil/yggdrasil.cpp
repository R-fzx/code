#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Pii = pair<ll, ll>;

const ll N = 7e5 + 5;

ll n, v[N], f[N], g[N], s[N], p = 1;
vector<Pii> e[N];

void C(ll x, ll f) {
  s[x] = 1;
  for (Pii i : e[x]) {
    if (i.first != f) {
      C(i.first, x);
      s[x] += s[i.first];
    }
  }
}

void D(ll x, ll f) {
  for (Pii i : e[x]) {
    if (i.first != f) {
      D(i.first, x);
      g[x] += g[i.first] + (i.second - v[x]) * s[i.first];
    }
  }
}

void F(ll x, ll f) {
  for (Pii i : e[x]) {
    if (i.first != f) {
      g[i.first] = g[x] + (n - s[i.first]) * (i.second - v[i.first]) - s[i.first] * (i.second - v[x]);
      F(i.first, x);
    }
  }
}

int main() {
  freopen("yggdrasil.in", "r", stdin);
  freopen("yggdrasil.out", "w", stdout);
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (ll i = 1, x, y, l; i < n; i++) {
    cin >> x >> y >> l;
    e[x].push_back({y, l});
    e[y].push_back({x, l});
  }
  C(1, 0);
  D(1, 0);
  F(1, 0);
  for (ll i = 1; i <= n; i++) {
    if (g[p] > g[i]) {
      p = i;
    }
  }
  cout << p << '\n' << g[p];
  return 0;
}
/*
20 14 10 8 7 6 5 5
*/