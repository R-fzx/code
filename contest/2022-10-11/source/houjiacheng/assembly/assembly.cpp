# include <bits/stdc++.h>
# define db double

using namespace std;

int n, k, a, cnt, B;
int l[20], b[20];
db p[20], ans, now;

db sov() {
  db re = 0;
  for (int i = 0; i < (1 << n); i++) {
    cnt = 0, B = 0;
    now = 1.0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        cnt++;
        now *= p[j];
      } else {
        now *= (1.0 - p[j]);
        B += b[j];
      }
    }
    if (cnt > n / 2) {
      re += now;
    } else {
      re += (now * a) / (a + B);
    }
  }
  // printf(" %f\n", re);
  return re;
}

void dfs(int d) {
  if (d == n) {
    // for (int i = 0; i < n; i++) {
    //   printf("%f ", p[i]);
    // }printf("\n");
    ans = max(ans, sov());
    return;
  }
  for (int i = 0; i <= k; i++) {
    k -= i;
    p[d] = min(100, l[d] + i * 10) / 100.0;
    dfs(d + 1);
    k += i;
  }
}

int main() {
  freopen("assembly.in", "r", stdin);
  freopen("assembly.out", "w", stdout);
  scanf("%d%d%d", &n, &k, &a);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", b + i, l + i);
  }
  dfs(0);
  printf("%.6f\n", ans);
}