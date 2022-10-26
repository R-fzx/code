# include <bits/stdc++.h>
# define ll long long

using namespace std;

int n, k, m;
int h[100100];
ll ans;
int st[25][100100];
int d[100100];
struct dis {
  int x, y;
} a[100100];

int init() {
  d[0] = -1;
  for (int i = 1; i <= n; i++) {
    st[0][i] = h[i];
    d[i] = d[i - 1];
    if ((i & (i - 1)) == 0) {
      ++d[i];
    }
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
}

inline int fi(int l, int r) {
  int k = d[r - l + 1];
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}

inline void add(int x, int y) {
  ll re = 0, mi = fi(min(a[x].x, a[y].x), max(a[x].x, a[y].x));
  if (a[x].y <= mi || a[y].y <= mi) {
    re = abs(a[x].y - a[y].y);
  } else {
    re = abs(a[x].y - mi) + abs(a[y].y - mi);
  }
  ans += (abs(a[x].x - a[y].x) + re <= k);
//  printf("%d %d %d %d  %d   %lld      %d\n", a[x].x, a[x].y, a[y].x, a[y].y, abs(a[x].x - a[y].x), re, mi);
}

int main() {
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
  }
  init();
  
//  printf("%d %d %d\n", fi(1, 5), fi(1, 4), fi(4, 4));
//  return 0;


  scanf("%d", &m);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    a[i].x = x;
    a[i].y = y;
    for (int j = 1; j < i; j++) {
      add(i, j);
    }
  }
  printf("%d", ans);
}
