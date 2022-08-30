#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1, kM = 3e5 + 1;

int n, m, c;
vector<Pll> e[kN];
LL ans;
priority_queue<Pll, vector<Pll>, greater<Pll>> q;
bool v[kN];

int main() {
  cin >> n >> m;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  for (q.emplace(0, 1); !q.empty();) {
    Pll x = q.top();
    q.pop();
    if (!v[x.second]) {
      v[x.second] = 1, ++c, ans += x.first;
      for (Pll &i : e[x.second]) {
        if (!v[i.first]) {
          q.emplace(i.second, i.first);
        }
      }
    }
  }
  if (c != n) {
    cout << "orz";
  } else {
    cout << ans;
  }
  return 0;
}