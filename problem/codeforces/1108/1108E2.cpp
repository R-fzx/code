#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Pii = pair<int, int>;

const int kN = 1e5 + 2, kM = 301;

int n, m, a[kN], ans, l;
bool v[kN];
Pii b[kM], p[kN], mn[kN];
vector<int> al;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
    v[b[i].first - 1] = v[b[i].second] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (p[++l].first = i; !v[i] && i < n; ++i) {
    }
    p[l].second = i;
  }
  for (int i = 1; i <= l; ++i) {
    auto x = minmax_element(a + p[i].first, a + p[i].second + 1);
    mn[i] = {*(x.second), *(x.first)};
  }
  for (int i = 1; i <= l; ++i) {
    for (int j = 1; j <= l; ++j) {
      vector<int> _al;
      int c = 0;
      for (int k = 1; k <= m; ++k) {
        if (b[k].first <= p[j].first && b[k].second >= p[j].second && (b[k].first > p[i].second || b[k].second < p[i].first)) {
          _al.push_back(k), ++c;
        }
      }
      if (ans < mn[i].first - mn[j].second + c) {
        ans = mn[i].first - mn[j].second + c, al = _al;
      }
    }
  }
  cout << ans << endl
       << al.size() << endl;
  for (int i : al) {
    cout << i << " ";
  }
  return 0;
}