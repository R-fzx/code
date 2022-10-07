# include <bits/stdc++.h>

using namespace std;

int n, m, t;
long long ans;
long long visn[100100], vism[100100];
long long sum[100100];

void sov(int n, long long * vis, long long x) {
  sum[1] = 0;
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + vis[i] - x;
  }
  sort(sum + 1, sum + 1 + n);
  int mid = sum[(n + 1) / 2];
  for (int i = 1; i <= n; i++) {
    ans += abs(mid - sum[i]);
  }
}

int main() {
  freopen("tanabata.in", "r", stdin);
  freopen("tanabata.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1, x, y; i <= t; i++) {
    scanf("%d%d", &x, &y);
    visn[x]++;
    vism[y]++;
  }
  if (t % n == 0 && t % m == 0) {
    sov(n, visn, t / n);
    sov(m, vism, t / m);
    printf("both %lld\n", ans);
    return 0;
  }
  if (t % n == 0) {
    sov(n, visn, t / n);
    printf("row %lld\n", ans);
    return 0;
  }
  if (t % m == 0) {
    sov(m, vism, t / m);
    printf("column %lld\n", ans);
    return 0;
  }
  printf("impossible\n");
}