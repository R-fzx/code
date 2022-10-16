#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 105;

struct JL{
  int a, b, t, vis;
} qwq[M];

int n, k, m, ans;

int find(int x) {
  int l = 1, r = m, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (qwq[mid].a < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

// void dfs(int pos, int t, int v) {
//   int x = find(pos);
//   if (qwq[x].vis) {
//     return;
//   }
//   if (x != 1 && t + pos - qwq[x - 1].a <= qwq[x - 1].t) {
//     dfs(qwq[x - 1].a, t + pos - qwq[x - 1].a, v + qwq[x - 1].b);
//   }
//   if (x != m && t + qwq[x + 1].a - pos <= qwq[x + 1].t) {
//     dfs(qwq[x + 1].a, t + qwq[x + 1].a - pos, v + qwq[x + 1].b);
//   }
// }

int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> qwq[i].a >> qwq[i].b >> qwq[i].t;
    ans = max(ans, qwq[i].b);
  }
  sort(qwq + 1, qwq + m + 1, [] (JL x, JL y) { return x.a < y.a; });
  // dfs(k, 0, 0);
  cout << ans;
  return 0;
}