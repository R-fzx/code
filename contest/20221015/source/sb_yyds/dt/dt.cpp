#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5;

ll n, m, ans, a[N], l[N];

bool v[N];

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
    v[l[i]] = 1;
    for (auto&& j : e[l[i]]) {
      if (!v[j]) {
        ans += a[j];
      }
    }
  }
  cout << ans;
  return 0;
}