#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1, kD[9][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0}};

int n;
LL k;
Pll a[kN];
map<Pll, vector<int>> mp;
vector<Pii> ans;

bool C(int i, int j) { return (a[j].first - a[i].first) * (a[j].first - a[i].first) + (a[j].second - a[i].second) * (a[j].second - a[i].second) <= k * k; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    mp[{a[i].first / k, a[i].second / k}].push_back(i);
  }
  for (auto p : mp) {
    for (int i = 0; i < 9; ++i) {
      Pll x = {p.first.first + kD[i][0], p.first.second + kD[i][1]};
      auto _p = mp.find(x);
      if (_p != mp.end()) {
        for (int j : p.second) {
          for (int k : _p->second) {
            if (j < k && C(j, k)) {
              ans.push_back({j, k});
            }
          }
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (Pii i : ans) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}