#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const int kM = 1e9 + 7;
const int kMaxN = 2e5 + 1;

int n, m, tot;
struct node {
  int x, r;
};
struct node2 {
  int l, r, v;
  inline bool operator<(node2 y) { return l < y.l; }
} a[kMaxN];
inline bool operator<(node x, node y) { return x.r > y.r; }
priority_queue<node> q;
bool v[kMaxN];
int l[kMaxN];
ll ans;

bool check() {
  int i, las;
  for (i = 0; i < m; i++) {
    if (v[i] == 1) {
      if (a[i].l > 1) {
        return 0;
      } else {
        las = i;
        break;
      }
    }
  }
  for (++i; i < m - 1; i++) {
    if (v[i] == 1) {
      if (a[i].l - 1 > a[las].r) {
        return 0;
      } else {
        las = i;
      }
    }
  }
  return a[las].r == n;
}

void dfs(int dep, ll now) {
  if (dep == m) {
    if (check()) {
      ans += now, ans %= kM;
    }
    return;
  }
  v[dep] = 1;
  dfs(dep + 1, now * a[dep].v % kM);
  v[dep] = 0;
  dfs(dep + 1, now);
}

int main() {
  ifstream cin("gugugu.in");
  ofstream cout("gugugu.out");

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i].l >> a[i].r >> a[i].v;
  }
  sort(a, a + m);
  if (m == 0) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (; i == a[tot].l; q.push({tot, a[tot++].r})) {
  //   }
  //   if (q.size() == 1) {
  //     ans *= a[i].v, v[q.top().x] = 1;
  //   }
  //   for (; !q.empty() && i == q.top().r; q.pop()) {
  //   }
  // }
  // for (int i = 0; i < m; i++) {
  //   if (v[i] == 1) {
  //     l[a[i].l] = 1, l[a[i].r + 1] = -1;
  //   }
  // }
  // bool flag = 1;
  // for (int i = 1; i <= n; i++) {
  //   l[i] += l[i - 1], flag = flag && l[i];
  // }
  return 0;
}
