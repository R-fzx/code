#include <iostream>
#define LL long long

using namespace std;

LL n, m, f[10], d[19] = {1};
bool flag, b[6001], _b[10][10], __b[10];
pair<LL, LL> a[10001];

LL GetRoot(LL x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

int main() {
  freopen("laser.in", "r", stdin);
  freopen("laser.out", "w", stdout);
  cin >> n >> m;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (LL i = 1; i <= 18; i++) {
    d[i] = d[i - 1] * 10;
  }
  for (LL i = 1; i < 10; i++) {
    f[i] = i;
  }
  for (LL i = 1; i <= n; i++) {
    for (LL j = a[i].first; j <= a[i].second; j++) {
      b[j] = 1;
    }
  }
  for (LL i = 1; i <= 6000; i++) {
    for (LL j = 1; j <= m; j++) {
      for (LL k = 1; k < 10; k++) {
        if (b[i] ^ b[i - i / d[j - 1] % 10 * d[j - 1] + k * d[j - 1]]) {
          _b[i / d[j - 1] % 10][k] = _b[k][i / d[j - 1] % 10] = 1;
        }
      }
    }
  }
  for (LL i = 1; i < 10; i++) {
    for (LL j = i + 1; j < 10; j++) {
      if (!_b[i][j] && GetRoot(i) != GetRoot(j)) {
        f[GetRoot(i)] = GetRoot(j);
      }
    }
  }
  for (LL i = 1; i < 10; i++, flag = 0) {
    for (LL j = 1; j < 10; j++) {
      if (!__b[j] && GetRoot(i) == GetRoot(j)) {
        cout << j;
        __b[j] = flag = 1;
      }
    }
    if (flag) {
      cout << '\n';
    }
  }
  return 0;
}
