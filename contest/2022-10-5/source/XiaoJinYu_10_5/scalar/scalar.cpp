#include <bits/stdc++.h>

using namespace std;

const int MAXN = 805;

int a[MAXN], b[MAXN];

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.out", "w", stdout);
  int n;
  long long ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n, cmp);
  for (int i = 0; i < n; ++i) {
    ans += 1ll * a[i] * b[i];
  }
  cout << ans;
  return 0;
}