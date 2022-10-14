#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

typedef double db;

const int kMaxN = 2e5 + 5;

struct Node {
  double x, y;
} a[kMaxN];

int n;
Node tmp[kMaxN];

db dist(Node a, Node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp1(Node a, Node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

bool cmp2(Node a, Node b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}

db solve(int l, int r) {
  if (l == r) return 1e9;
  if (l + 1 == r) return dist(a[l], a[r]);
  int mid = (l + r) >> 1, cnt = 0;
  db res = min(solve(l, mid), solve(mid + 1, r));
  for (int i = l; i <= r; ++i) {
    if (abs(a[i].x - a[mid].x) <= res) {
      tmp[++cnt] = a[i];
    }
  }
  sort(tmp + 1, tmp + 1 + cnt, cmp2);
  for (int i = 1; i <= cnt; ++i) {
    for (int j = i + 1; j <= cnt; ++j) {
      res = min(res, dist(tmp[i], tmp[j]));
    }
  }
  return res;
}

int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
  }
  sort(a + 1, a + 1 + n, cmp1);
  printf("%.3lf\n", solve(1, n) / 2.0);
  return 0;
}