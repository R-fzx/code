#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, a, b, c;
long long ans = 1;
pair<int, int> Min[1001];
bool M[1001];
vector<pair<int, int>> dot[1001];
priority_queue<pair<int, int>> q;

void Find() {
  while (!q.empty()) {
    pair<int, int> tmp = q.top();
    q.pop();
    while (M[tmp.second]) {
      tmp = q.top();
      q.pop();
      if (q.empty() && M[tmp.second]) {
        return;
      }
    }
    M[tmp.second] = 1;
    for (int i = 0; i < dot[tmp.second].size(); i++) {
      if ((dot[tmp.second][i].second - tmp.first < Min[dot[tmp.second][i].first].first) || !Min[dot[tmp.second][i].first].second) {
        Min[dot[tmp.second][i].first] = {dot[tmp.second][i].second - tmp.first, 1};
        q.push({tmp.first - dot[tmp.second][i].second, dot[tmp.second][i].first});
      } else if (dot[tmp.second][i].second - tmp.first == Min[dot[tmp.second][i].first].first) {
        Min[dot[tmp.second][i].first].second++;
      }
    }
  }
}

int main() {
  freopen("Castle.in", "r", stdin);
  freopen("Castle.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    dot[a].push_back({b, c});
    dot[b].push_back({a, c});
  }
  Min[1] = {1, 1};
  q.push({-1, 1});
  Find();
  for (int i = 1; i <= n; i++) {
    ans *= Min[i].second;
  }
  cout << ans << endl;
  return 0;
}