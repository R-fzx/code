#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int, pair<int, int>>;
const int kMaxN = 1e3 + 1;
int n, m, ml = 0, mr = -1;
struct node {
  vector<Pii> e;
  bool f;
} s[kMaxN];
void F(int x, int l, int r) {
  if (s[x].f) {
    return;
  }
  if (x == n) {
    if (r - l + 1 > mr - ml + 1) {
      ml = l, mr = r;
    }
    return;
  }
  s[x].f = 1;
  for (Pii i : s[x].e) {
    F(i.first, max(l, i.second.first), min(r, i.second.second));
  }
  s[x].f = 0;
}
int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin >> n >> m;
  for (int i = 1, a, b, l, r; i <= m; i++) {
    cin >> a >> b >> l >> r;
    s[a].e.push_back({b, {l, r}});
    s[b].e.push_back({a, {l, r}});
  }
  F(1, 0, 1e9);
  cout << mr - ml + 1 << '\n';
  for (int i = ml; i <= mr; i++) {
    cout << i << " ";
  }
  return 0;
}