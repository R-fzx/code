#include <bits/stdc++.h>
using namespace std;
const int kMaxM = 1e2 + 1, kMaxN = 1e3 + 1;
int n, k, m, maxx = -1, x;
struct node {
  int a, b, t;
} s[kMaxM + 1];
bool cmp(node x, node y) {
  return x.a < y.a;
}
void F(int ti, int x, int l, int r, int tot) {
  maxx = max(maxx, tot);
  if (l - 1 >= 1) {
    F(ti + abs(s[l - 1].a - s[x].a), l - 1, l - 1, r, tot + (ti + abs(s[l - 1].a - s[x].a) <= s[l - 1].t) * s[l - 1].b);
  }
  if (r + 1 <= n) {
    F(ti + abs(s[r + 1].a - s[x].a), r + 1, l, r + 1, tot + (ti + abs(s[r + 1].a - s[x].a) <= s[r + 1].t) * s[r + 1].b);
  }
}
int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s[i].a >> s[i].b >> s[i].t;
  }
  s[m + 1] = {k, 0, 1};
  sort(s + 1, s + m + 2, cmp);
  for (x = 1; s[x].a != k; x++) {
  }
  F(1, x, x, x, 0);
  cout << maxx;
  return 0;
}