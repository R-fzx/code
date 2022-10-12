#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct P {
  long long num;
  pair<long long, long long> val[4];
} p[500001];

long long n, Size[5];
long long ans1, ans2, dp[3][101];
long long Last[500001];
priority_queue<pair<long long, long long>> q[3];

pair<long long, long long> Find(long long x) {
  pair<int, int> Max[4];
  for (long long i = 0; i < 3; i++) {
    Max[p[x].val[i].second] = {-p[x].val[i].first, p[x].val[i].second};
    if (q[p[x].val[i].second].size() >= Size[p[x].val[i].second]) {
      int tmp = q[p[x].val[i].second].top().second;
      Max[p[x].val[i].second].first -= q[p[x].val[i].second].top().first;
      for (int j = Last[tmp]; j < 3; j++, Last[tmp] = j) {
        if (q[p[tmp].val[j].second].size() < Size[p[tmp].val[j].second]) {
          Max[p[x].val[i].second].first -= p[tmp].val[j].first;
          break;
        }
      }
    }
  }
  sort(Max, Max + 3);
  Last[x] = Max[0].second;
  return Max[0];
}

long long Check(int x) {
  pair<long long, long long> temp = Find(x);
  if (q[temp.second].size() >= Size[temp.second]) {
    int tmp = q[temp.second].top().second;
    q[temp.second].pop();
    for (int j = Last[tmp]; j < 3; j++, Last[tmp] = j) {
      if (q[p[tmp].val[j].second].size() < Size[p[tmp].val[j].second]) {
        q[p[tmp].val[j].second].push({-p[tmp].val[j].first, tmp});
        break;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (p[x].val[i].second == temp.second) {
      q[temp.second].push({-p[x].val[i].first, x});
      break;
    }
  }
  return temp.first;
}

int main() {
  freopen("ゆりっぺ.in", "r", stdin);
  freopen("ゆりっぺ.out", "w", stdout);
  cin >> n >> Size[0] >> Size[1] >> Size[2];
  if (Size[0] + Size[1] + Size[2] > n) {
    cout << "I am a godlike cowcowcow\n";
    return 0;
  }
  Size[3] = 1e18;
  for (long long i = 0; i < n; i++) {
    cin >> p[i].val[0].first >> p[i].val[1].first >> p[i].val[2].first;
    p[i].num = p[i].val[0].first + p[i].val[1].first + p[i].val[2].first;
    p[i].val[0].second = 0;
    p[i].val[1].second = 1;
    p[i].val[2].second = 2;
    sort(p[i].val, p[i].val + 3, [](pair<long long, long long> a, pair<long long, long long> b) {
      return a.first > b.first;
    });
  }
  sort(p, p + n, [](P a, P b) {
    return a.num > b.num;
  });
  for (long long i = 0; i < Size[0] + Size[1] + Size[2]; i++) {
    ans2 += p[i].num;
  }
  for (long long i = 0; i < Size[0] + Size[1] + Size[2] || p[i].num == p[i - 1].num; i++) {
    ans1 -= Check(i);
  }
  cout << ans1 << '\n'
       << ans2 << '\n';
  return 0;
}
