#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

int n;
vector<LL> l[4];
LL f[kN][10];

void U(int x, int h, LL w, int t, int c, LL m) {  // 现在在第x轮，剩余能量值为h，当前出牌总代价为w，目前出的牌能量为t，总出牌数c，最大代价为m
  if (!t) {                                       // 牌出完了
    for (int i = 0; i < 10; ++i) {                // 上一轮出牌总数%10
      f[x][(i + c) % 10] = max(f[x][(i + c) % 10], f[x - 1][i] + w + (i + c > 9 ? m : 0));
    }
    return;
  }
  LL _w = w, _m = m;
  for (int i = 0; i < l[t].size() && i * t <= h; ++i) {  // 出几张牌
    U(x, h - i * t, _w += l[t][i], t - 1, c + i, _m = max(_m, l[t][i]));
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  fill(&f[0][1], &f[n][9] + 1, -1e18);
  for (int i = 1, k; i <= n; ++i) {
    cin >> k;
    for_each(l + 1, l + 4, [](auto &x) { x.resize(1); });
    for (int c, d; k--; l[c].push_back(d)) {
      cin >> c >> d;
    }
    for_each(l + 1, l + 4, [](auto &x) { sort(x.begin() + 1, x.end(), greater<LL>()); }), U(i, 3, 0, 3, 0, 0);
  }
  cout << *max_element(f[n], f[n] + 10);
  return 0;
}