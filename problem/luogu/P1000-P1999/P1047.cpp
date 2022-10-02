#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 10;

int a[kN][kN], ans = -1, d[kN], c[kN];
bool v[kN];

int C(int x, int y) {
  return a[x][y] * (10 - max(abs(x - 5), abs(y - 5)));
}
void D(int x, int y, int s) {
  // cout << x << ' ' << y << ' ' << s << '\n';
  // for (int i = 1; i < kN; ++i) {
  //   for (int j = 1; j < kN; ++j) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  if (y == kN) {
    D(x + 1, 1, s);
    return;
  }
  if (x == kN) {
    ans = max(ans, s);
    return;
  }
  if (a[d[x]][y]) {
    D(x, y + 1, s + C(d[x], y));
  } else {
    fill(v + 1, v + kN, 1);
    for (int i = 1; i < kN; ++i) {
      v[a[d[x]][i]] = v[a[i][y]] = 0;
    }
    for (int bx = (d[x] - 1) / 3, i = bx * 3 + 1; i <= bx * 3 + 3; ++i) {
      for (int by = (y - 1) / 3, j = by * 3 + 1; j <= by * 3 + 3; ++j) {
        v[a[i][j]] = 0;
      }
    }
    vector<int> l;
    for (int i = 1; i < kN; ++i) {
      v[i] && (l.push_back(i), 0);
    }
    for (int i : l) {
      a[d[x]][y] = i, D(x, y + 1, s + C(d[x], y)), a[d[x]][y] = 0;
    }
  }
}

int main() {
  for (int i = 1; i < kN; ++i) {
    for (int j = 1; j < kN; ++j) {
      cin >> a[i][j];
      c[i] += !a[i][j];
    }
    d[i] = i;
  }
  sort(d + 1, d + kN, [](int i, int j) { return c[i] < c[j]; });
  D(1, 1, 0);
  cout << ans;
  return 0;
}