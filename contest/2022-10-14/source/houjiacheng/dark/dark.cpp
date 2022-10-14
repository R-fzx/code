# include <bits/stdc++.h>
# define ll long long

using namespace std;

struct Dis{
  ll x, y;
} d[200200];

int n, eps = 180;
ll ans;

bool cmp(Dis a, Dis b) {
  if (a.x * b.y  == b.x * a.y) {
    return a.x < b.x;
  }
  return a.x * b.y  < b.x * a.y;
}

void sov() {
  for (int i = 1, kj, tans, dx, dy; i < n; i++) {
    kj = min(n, i + eps);
    dx = d[i].x; dy = d[i].y;
    for (int j = i + 1; j <= kj; ++j) {
      tans = (dx - d[j].x) * (dx - d[j].x) + (dy - d[j].y) * (dy - d[j].y);
      if (tans < ans) {
        ans = tans;
      }
    }
  }
}

void sch(int kx, int ky, int bx, int by) {
  for (int i = 1; i <= n; i++) {
    d[i].x = d[i].x * kx + bx;
    d[i].y = d[i].y * ky + by;
  }
  sort(d + 1, d + 1 + n, cmp);
  sov();
}

int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    d[i].x = x; d[i].y = y;
  }
  ans = (d[1].x - d[2].x) * (d[1].x - d[2].x) + (d[1].y - d[2].y) * (d[1].y - d[2].y);
  sch(1, 1, 4500, 1);
  sch(-1, 1, 19000, 0);
  sch(1, 1, -4500, 2999);
  printf("%.3f", sqrt(ans));
}
