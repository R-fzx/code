#include <bits/stdc++.h>
using namespace std;
vector<long long> v[100005];
long long t[100005];
long long dp[100005];
int main() {
  freopen("lyx.in","r",stdin);
  freopen("lyx.out","w",stdout);
  long long n, m;
  cin >> n >> m;
  queue<long long> q;
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
    t[y]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (t[i] == 0) {
      dp[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (long long i = 0; i < v[x].size(); i++) {
      t[v[x][i]]--;
      dp[v[x][i]] += dp[x];
      if (t[v[x][i]] == 0) {
        q.push(v[x][i]);
      }
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (v[i].size() == 0) {
      sum += dp[i];
    }
  }
  cout << sum;
}