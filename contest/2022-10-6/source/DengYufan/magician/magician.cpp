#include <iostream>
#include <vector>
#define LL long long

using namespace std;

struct V {
  vector<pair<LL, LL>> e;
} v[101];
LL n, m;
bool ans[101][65536];

void T(LL s, LL x, LL t, LL b) {
  if (s == x && b) {
    ans[t][b] = 1;
    return;
  }
  for (auto i : v[x].e) {
    if (!(b & 1 << i.second)) {
      T(s, i.first, max(t, i.second), b | 1 << i.second);
    }
  }
}

int main() {
  freopen("magician.in", "r", stdin);
  freopen("magician.out", "w", stdout);
  cin >> n >> m;
  for (LL i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    v[x].e.push_back({y, i}), v[y].e.push_back({x, i});
  }
  for (LL i = 1; i <= n; i++) {
    T(i, i, 0, 0);
  }
  for (LL i = 1, c = 0; i <= m; i++) {
    for (LL j = 0; j < 65536; j++) {
      c += ans[i][j];
    }
    cout << c << '\n';
  }
  return 0;
}
