#include <iostream>
#include <cstdio>
#pragma GCC optimize("Ofast")

using namespace std;

const int mod = 10007;

int n, m, k, ans;

int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  if (n * m < k) {
    cout << 0;
    return 0;
  }
  if (n * m == k) {
    cout << 1;
    return 0;
  }
  cout << k / n * m % mod;
  return 0;
}
