#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

LL n, m, a[kN], ans;
deque<LL> q[kN];
deque<Pll> e;

int main() {
  // freopen("D.in", "r", stdin);
  // freopen("D.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    q[a[i] % m].push_back(i);
  }
  for (int i = 0; i < (m << 1); ++i) {
    while (q[i % m].size() > n / m) {
      e.push_back({i, q[i % m].back()}), q[i % m].pop_back();
    }
    while (q[i % m].size() < n / m && !e.empty()) {
      auto p = e.back();
      q[i % m].push_back(p.second), a[p.second] += i - p.first, ans += i - p.first, e.pop_back();
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
/*
6 3
3 2 0 8 10 13
0 2 0 2 1 1

*/