#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 101;

int n, c[kN], s[3][kN], t, b[kN][kN];
bool l[kN][kN], v[kN][kN], f[kN][kN], w[kN];
vector<int> p[3][kN], ans;

void D(int x, int _c) {
  if (c[x] == 3 - _c) {
    cout << "No solution";
    exit(0);
  }
  if (!c[x]) {
    ++s[c[x] = _c][t], p[_c][t].push_back(x);
    for (int i = 1; i <= n; ++i) {
      if (v[x][i]) {
        D(i, 3 - _c);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int x; (cin >> x) && x;) {
      l[i][x] = 1;
    }
    for (int j = 1; j <= n; ++j) {
      if (i != j && !l[i][j]) {
        v[i][j] = v[j][i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) {
      ++t, D(i, 1);
    }
  }
  f[0][0] = 1;
  for (int i = 1; i <= t; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 1; k < 3; ++k) {
        if (j >= s[k][i] && f[i - 1][j - s[k][i]]) {
          f[i][j] = 1, b[i][j] = k;
        }
      }
    }
  }
  for (int i = n / 2; i >= 0; --i) {
    if (f[t][i]) {
      for (int j = i, k = t; j; j -= s[b[k][j]][k], --k) {
        for (int x : p[b[k][j]][k]) {
          ans.push_back(x), w[x] = 1;
        }
      }
      sort(ans.begin(), ans.end());
      cout << ans.size();
      for (int j : ans) {
        cout << " " << j;
      }
      cout << endl << n - ans.size();
      for (int j = 1; j <= n; ++j) {
        if (!w[j]) {
          cout << " " << j;
        }
      }
      return 0;
    }
  }
  return 0;
}