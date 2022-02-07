#include <iostream>
#include <vector>

using namespace std;

const int kN = 201, kD[8][2] = {{3, 1}, {1, 3}, {3, -1}, {1, -3}, {-1, -3}, {-3, -1}, {-1, 3}, {-3, 1}};

int n, m, k, v[kN * kN], t, s, p[kN * kN];
bool a[kN][kN];
vector<int> ne[kN * kN];

int Encode(int x, int y) {
  return (x - 1) * m + y;
}
bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (int i : ne[x]) {
      if (!p[i] || F(p[i])) {
        return p[i] = x;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, x, y; i <= k; ++i) {
    cin >> x >> y;
    a[x][y] = 1;
  }
  k = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      k += a[i][j];
    }
  }
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; ++j) {
      if (!a[i][j]) {
        for (int k = 0; k < 8; ++k) {
          int x = i + kD[k][0], y = j + kD[k][1];
          if (x >= 1 && x <= n && y >= 1 && y <= m && !a[x][y]) {
            ne[Encode(i, j)].push_back(Encode(x, y)), ne[Encode(x, y)].push_back(Encode(i, j));
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; ++j) {
      ++t, s += F(Encode(i, j));
    }
  }
  cout << n * m - s - k;
  return 0;
}