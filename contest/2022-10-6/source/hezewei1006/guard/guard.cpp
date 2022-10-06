#include <iomanip>
#include <iostream>
#include <list>

#define f first
#define s second
#define t front

using namespace std;

int n, l, k, w[201], val;
bool b[200201][201];
double dp[200201][201], New[200201][201][2], ans;
list<pair<int, int>> L;

int main() {
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);
  cin >> n >> l >> k;
  L.push_back({k + 200, 0});
  b[k + 200][0] = dp[k + 200][0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int i = 0, temp = L.size(); i < n; i++, temp = L.size()) {
    cin >> val;
    for (int j = 0; j < temp; j++, L.pop_front()) {
      if (!dp[L.t().f][L.t().s] && !New[L.t().f][L.t().s][0] && !New[L.t().f][L.t().s][1]) {
        continue;
      }
      dp[L.t().f][L.t().s] += New[L.t().f][L.t().s][i % 2];
      New[L.t().f][L.t().s][i % 2] = 0;
      if (!b[L.t().f + val][L.t().s + 1] && w[i]) {
        b[L.t().f + val][L.t().s + 1] = 1;
        L.push_back({L.t().f + val, L.t().s + 1});
      }
      New[L.t().f + val][L.t().s + 1][(i + 1) % 2] += dp[L.t().f][L.t().s] * w[i] / 100.000;
      dp[L.t().f][L.t().s] *= (100 - w[i]) / 100.000;
      L.push_back({L.t().f, L.t().s});
    }
  }
  while (!L.empty()) {
    if (L.t().f >= 200 && L.t().s >= l) {
      ans += dp[L.t().f][L.t().s] + New[L.t().f][L.t().s][0] + New[L.t().f][L.t().s][1];
    }
    L.pop_front();
  }
  cout << fixed << setprecision(6) << (double)(ans * 100000000 + 5) / 100000000 << endl;
  return 0;
}