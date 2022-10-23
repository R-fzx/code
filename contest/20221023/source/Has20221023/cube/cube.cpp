#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N][6][22], v[N], b[6];
long long ans;

int main() {
  freopen("cube.in", "r", stdin);
  freopen("cube.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, j = 0; i <= n; ++i) {
    for (int k = 0; k < 6; ++k) {
      cin >> a[i][k][0];
    }
    j += i == (1 << j + 1);
    v[i] = j;
  }
  for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      for (int k = 0; k < 3; ++k) {
        a[i][k][j] = max(a[i][k][j - 1], a[i + (1 << (j - 1))][k][j - 1]);
      }
      for (int k = 3; k < 6; ++k) {
        a[i][k][j] = min(a[i][k][j - 1], a[i + (1 << (j - 1))][k][j - 1]);
      }
    }
  }
  for (int i = 1, l, r; i <= n; ++i) {
    b[0] = b[1] = b[2] = 0, b[3] = b[4] = b[5] = 1e9;
    for (int j = 0; j < 3; ++j) {
      if (i != n) {
        l = i + 1, r = n;
        int d = v[r - l + 1];
        b[j] = max(a[l][j][d], a[r - (1 << d) + 1][j][d]);
      }
      if (i != 1) {
        l = 1, r = i - 1;
        int d = v[r - l + 1];
        b[j] = max(b[j], max(a[l][j][d], a[r - (1 << d) + 1][j][d]));
      }
    }
    for (int j = 3; j < 6; ++j) {
      if (i != n) {
        l = i + 1, r = n;
        int d = v[r - l + 1];
        b[j] = min(a[l][j][d], a[r - (1 << d) + 1][j][d]);
      }
      if (i != 1) {
        l = 1, r = i - 1;
        int d = v[r - l + 1];
        b[j] = min(b[j], min(a[l][j][d], a[r - (1 << d) + 1][j][d]));
      }
    }
    ans += (long long)(b[3] - b[0] + 1) * (b[4] - b[1] + 1) * (b[5] - b[2] + 1);
  }
  cout << ans;
  return 0;
}