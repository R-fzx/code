#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1e5 + 1;
int n, m, l = 1, sum;
struct node {
  vector<int> e;
  bool f;
  int tot;
} s[kMaxN];
struct node1 {
  int x, d;
} t[kMaxN];
bool cmp(node1 x, node1 y) {
  return x.x > y.x;
}
int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].x;
    t[i].d = i;
  }
  for (int i = 1, a, b; i <= m; i++) {
    cin >> a >> b;
    s[a].e.push_back(b);
    s[a].tot += t[b].x;
    s[b].e.push_back(a);
    s[b].tot += t[a].x;
  }
  sort(t + 1, t + n + 1, cmp);
  while (l <= n) {
    sum += s[t[l].d].tot;
    for (int i : s[t[l].d].e) {
      s[i].tot -= t[l].x;
    }
    l++;
  }
  cout << sum;
  return 0;
}