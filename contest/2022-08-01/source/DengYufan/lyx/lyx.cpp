#include <iostream>
#include <queue>
#define LL long long

using namespace std;

struct V {
  int d;
  vector<int> e;
} v[100001];
int n, m, ans;
queue<int> q;

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    v[x].e.push_back(y), v[y].d++;
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i].d) {
      q.push(i);
    }
  }
  for (; !q.empty(); q.pop()) {
    int c = q.front();
    if (v[c].e.empty()) {
      ans++;
    }
    for (int i : v[c].e) {
      q.push(i);
    }
  }
  cout << ans;
  return 0;
}
