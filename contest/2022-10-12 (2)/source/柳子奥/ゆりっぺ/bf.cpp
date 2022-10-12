#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 101;

int n, A, B, C;
int a[kMaxN], b[kMaxN], c[kMaxN];
pair<int, int> f[kMaxN][kMaxN][kMaxN];

pair<int, int> add(pair<int, int> p1, pair<int, int> p2) {
  return make_pair(p1.first + p2.first, p1.second + p2.second);
}

int Main() {
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
  }
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      for (int k = 0; k <= C; ++k) {
        f[i][j][k] = make_pair(-1e18, -1e18);
      }
    }
  }
  f[0][0][0] = make_pair(0, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = min(i, A); ~j; --j) {
      for (int k = min(i, B); ~k; --k) {
        for (int s = min(i, C); ~s; --s) {
          if (j) f[j][k][s] = max(f[j][k][s], add(f[j - 1][k][s], make_pair(a[i], a[i] + b[i] + c[i])));
          if (k) f[j][k][s] = max(f[j][k][s], add(f[j][k - 1][s], make_pair(b[i], a[i] + b[i] + c[i])));
          if (s) f[j][k][s] = max(f[j][k][s], add(f[j][k][s - 1], make_pair(c[i], a[i] + b[i] + c[i])));
        }
      }
    }
  }
  cout << f[A][B][C].first << endl << f[A][B][C].second << endl;  
  return 0;
}

int main() {
  freopen("yxy.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> n >> A >> B >> C;
  Main();
  return 0;
}