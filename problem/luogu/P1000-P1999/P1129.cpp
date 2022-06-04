#include <iostream>

using namespace std;

const int kN = 201;

int t, n, a[kN][kN], p[kN], c, v[kN], s;

bool F(int x) {
  if (v[x] ^ c) {
    v[x] = c;
    for (int i = 1; i <= n; ++i) {
      if (a[x][i] && (!p[i] || F(p[i]))) {
        return p[i] = x;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      p[i] = v[i] = 0;
      for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
      }
    }
    s = c = 0;
    for (int i = 1; i <= n; ++i) {
      ++c, s += F(i);
    }
    cout << (s == n ? "Yes" : "No") << endl;
  }
  return 0;
}