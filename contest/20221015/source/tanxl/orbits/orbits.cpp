#include <bits/stdc++.h>
using namespace std;
const int kM = 1e4 + 7;
int n, m;
long long k, tot;
bool G(long long x) {
  long long v = x / k;
  if (v * k != x) {
    return false;
  }
  for (int i = 2; i <= min(v, k); i++) {
    if (v % i == 0 && k % i == 0) {
      return false;
    }
  }
  return true;
}
void F(int x, long long sum) {
  if (x == n) {
    if (G(sum)) {
      tot = (tot + 1) % kM;
    }
    return;
  }
  for (int i = 1; i <= m; i++) {
    F(x + 1, sum * i);
  }
}
int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  cin >> n >> m >> k;
  F(0, 1);
  cout << tot % kM;
  return 0;
}