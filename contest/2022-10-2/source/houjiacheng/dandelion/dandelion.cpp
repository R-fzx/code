# include <bits/stdc++.h>
# define N 50050
# define K 1000

using namespace std;

struct str{
  int a, v, id;
} a[N];

int c[42][42][N];
int tc[N];
int ans[42][42];
int pr[N];
int n, m, l0, r0, x;

bool cmp1(str a, str b) {
  return a.a < b.a;
}

bool cmp2(str a, str b) {
  return a.id < b.id;
}

int main() {
  freopen("dandelion.in", "r", stdin);
  freopen("dandelion.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1, in; i <= n; i++) {
    scanf("%d", &in);
    a[i].a = in; a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp1);
  a[1].v = 1;
  for (int i = 2; i <= n; i++) {
    a[i].v = a[i - 1].v + (a[i].a != a[i - 1].a);
    pr[a[i].v] = a[i].a;
  }
  sort(a + 1, a + 1 + n, cmp2);
  int discnt = (n - 1) / K; //第K个数后
  for (int i = 1; i < discnt; i++) {
    for (int j = i + 1; j <= discnt; j++) {
      x = ans[i][j - 1];
      for (int k = 1; k <= n; k++) {
        c[i][j][k] = c[i][j - 1][k];
      }
      for (int k = (j - 1) * K + 1; k <= j * k; k++) {
        ++c[i][j][a[k].v];
        if (c[i][j][a[k].v] > c[i][j][x] || c[i][j][a[k].v] == c[i][j][x] && a[k].v < x) {
          x = a[k].v;
        }
      }
      ans[i][j] = x;
    }
  }
  x = 0;
  while (m--) {
    scanf("%d%d", &l0, &r0);
    int l = (l0 + x - 1) % n + 1, r = (r0 + x - 1) % n + 1;
    if (l > r) {
      swap(l, r);
    }
    if (r - l + 1 <= K) {
      x = 0;
      for (int k = l; k <= r; k++) {
        ++tc[a[k].v];
        if (tc[a[k].v] > tc[x] || tc[a[k].v] == tc[x] && a[k].v < x) {
          x = a[k].v;
        }
      }
      for (int k = l; k <= r; k++) {
        --tc[a[k].v];
      }
      printf("%d\n", pr[x]);
      continue;
    }
    int ldis = (l - 1) / K + 1, rdis = (r - 1) / K;
    x = ans[ldis][rdis];
    for (int k = l; k <= K * ldis; k++) {
      ++c[ldis][rdis][a[k].v];
      if (c[ldis][rdis][a[k].v] > c[ldis][rdis][x] || c[ldis][rdis][a[k].v] == c[ldis][rdis][x] && a[k].v < x) {
        x = a[k].v;
      }
    }
    for (int k = rdis * K + 1; k <= r; k++) {
      ++c[ldis][rdis][a[k].v];
      if (c[ldis][rdis][a[k].v] > c[ldis][rdis][x] || c[ldis][rdis][a[k].v] == c[ldis][rdis][x] && a[k].v < x) {
        x = a[k].v;
      }
    }
    printf("%d\n", pr[x]);
    for (int k = l; k <= K * ldis; k++) {
      --c[ldis][rdis][a[k].v];
    }
    for (int k = rdis * K + 1; k <= r; k++) {
      --c[ldis][rdis][a[k].v];
    }
  }
}