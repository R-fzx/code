#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m, a[N], l[N], d[N];
ll r;
vector<int> e[N];

int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i;
  }
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  sort(l + 1, l + n + 1, [](int x, int y) { return a[x] > a[y]; });
  for (int i = 1; i <= n; i++) {
    for (int j : e[l[i]]) {
      if (!d[j]) {
        r += a[j];
      }
    }
    d[l[i]] = 1;
  }
  cout << r;
  return 0;
}
/*

*/