#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 201;

int n, k, a[kN], q[kN], h = 1, t, ans;
vector<int> e[kN];
bool v[kN];

void R(int x) { !v[x] && (v[x] = 1, q[++t] = x); }
void M(int x, int f, int d, int v) {
  d <= k && (for_each(e[x].begin(), e[x].end(), [&](int i) { i != f && (M(i, x, d + 1, v), 0); }), a[x] -= v);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k, for_each(a + 1, a + n + 1, [](int &i) { cin >> i; });
  for (int i = 1, x, y; i < n; cin >> x >> y, e[x].push_back(y), e[y].push_back(x), ++i) {
  }
  for (R(1); h <= t; for_each(e[q[h]].begin(), e[q[h]].end(), [](int i) { R(i); }), ++h) {
  }
  for (int i = n; i >= 1; a[q[i]] > 0 && (ans += a[q[i]], M(q[i], 0, 0, a[q[i]]), 0), --i) {
  }
  cout << ans;
  return 0;
}