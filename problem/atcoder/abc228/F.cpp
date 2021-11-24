#include <deque>
#include <iostream>
using namespace std;
using LL = long long;
using Pil = pair<int, LL>;
using T = deque<Pil>;
const int kN = 1001;
int n, m, h1, w1, h2, w2;
LL a[kN][kN], ans;
T q[kN], l;
void update(T &q, const int l) {
  while (!q.empty() && q.front().first < l) q.pop_front();
}
void insert(T &q, const Pil &o) {
  while (!q.empty() && q.back().second <= o.second) q.pop_back();
  q.push_back(o);
}
LL S(int x1, int y1, int x0, int y0) { return x1 = max(0, x1), y1 = max(0, y1), a[x0][y0] - a[x0][y1] - a[x1][y0] + a[x1][y1]; }
int main() {
  cin >> n >> m >> h1 >> w1 >> h2 >> w2;
  for (int i = (h2 = min(h2, h1), w2 = min(w2, w1), 1); i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j], a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = (l.clear(), 1); j <= m; ++j) update(q[j], i - h1 + h2), insert(q[j], {i, S(i - h2, j - w2, i, j)}), update(l, j - w1 + w2), insert(l, {j, q[j].front().second}), ans = max(ans, S(i - h1, j - w1, i, j) - l.front().second);
  cout << ans;
  return 0;
}