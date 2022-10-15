#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

struct V {
  int a, id;
  bool vis;
  vector <int> e;
} v[N];
int n, m, pos[N];
long long ans;

bool C (const V &x, const V &y) {
  return x.a > y.a;
}

int main () {
  freopen ("dt.in", "r", stdin);
  freopen ("dt.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].a;
    v[i].vis = 0; v[i].id = i;
  }
  for (int j = 1; j <= m; j++) {
    int x, y;
    cin >> x >> y;
    v[x].e.push_back (y);
    v[y].e.push_back (x);
  }
  sort (v + 1, v + 1 + n, C);
  for (int i = 1; i <= n; i++) {
    pos[v[i].id] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j : v[i].e) {
      ans += (v[pos[j]].vis ? 0 : v[pos[j]].a);
    }
    v[i].vis = 1;
  }
  cout << ans;
  return 0;
}