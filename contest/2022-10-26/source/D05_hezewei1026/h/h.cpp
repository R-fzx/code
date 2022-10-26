#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 2e5 + 1;

struct A {
  int a, b, val;
  bool operator<(const A& a) {
    return val < a.val;
  }
} b[kMaxN];

int n, m, k, x, y, a[kMaxN], tree[kMaxN];
long long ans;
short Used[kMaxN];
vector<pair<int, int>> p;

int read() {
  int x(0);
  char ch(getchar());
  while (ch < '0' || '9' < ch) {
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return x;
}

int build(int x, int l, int r) {
  if (l == r) {
    tree[x] = a[l];
  } else {
    tree[x] = min(build(x * 2, l, (l + r) >> 1), build(x * 2 + 1, ((l + r) >> 1) + 1, r));
  }
  return tree[x];
}

int Find(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return tree[x];
  } else if (r < L || R < l) {
    return 1e9 + 7;
  }
  return min(Find(x * 2, l, (l + r) >> 1, L, R), Find(x * 2 + 1, ((l + r) >> 1) + 1, r, L, R));
}

int main() {
  freopen(".in", "r", stdin);
  freopen("h.out", "w", stdout);
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  build(1, 1, n);
  m = read();
  for (int i = 0; i < m; i++) {
    x = read(), y = read();
    p.push_back(make_pair(x, y));
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < m - 1; i++) {
    b[i].a = i, b[i].b = i + 1;
    b[i].val = Find(1, 1, n, p[i].first, p[i + 1].first);
  }
  sort(b, b + m - 1);
  for (int s = m - 2; s >= 0; s--) {
    for (int i = b[s].a, x = 0; i >= 0 && !x; x = Used[i], i--) {
      for (int j = b[s].b, y = 0; j < m && !y && p[j].first - p[i].first < k; y = Used[j], j++) {
        if (abs(p[i].second - b[s].val) + abs(p[j].second - b[s].val) + p[j].first - p[i].first <= k) {
          ans++;
        }
      }
    }
    Used[b[s].a] = Used[b[s].b] = 1;
  }
  cout << ans << '\n';
  return 0;
}
