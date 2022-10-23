#include <bits/stdc++.h>

#include <fstream>
#pragma GCC optimize("Ofast")

using namespace std;
using ll = long long;

ifstream fin("triangle.in");
ofstream fout("triangle.out");

const ll N = 1e5 + 5;

ll n, q, a[N], L[N];

int main() {
  fin >> n >> q;
  for (ll i = 1; i <= n; i++) {
    fin >> a[i];
    L[i] = i;
  }
  sort(L + 1, L + n + 1, [](ll x, ll y) { return a[x] < a[y]; });
  for (ll l, r, f = 0; q--; f = 0) {
    fin >> l >> r;
    for (ll i = 1, j = 1, k = 1; k <= n; i++) {
      for (; i <= n && (L[i] < l || L[i] > r); i++) {
      }
      for (j = i + 1; j <= n && (L[j] < l || L[j] > r); j++) {
      }
      for (k = j + 1; k <= n && (L[k] < l || L[k] > r); k++) {
      }
      if (i <= n && j <= n && k <= n && a[L[i]] + a[L[j]] > a[L[k]]) {
        f = 1;
        break;
      }
    }
    fout << (f ? "Yes\n" : "No\n");
  }
  return 0;
}
/*
 */