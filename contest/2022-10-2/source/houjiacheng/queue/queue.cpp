# include <stdio.h>
# include <algorithm>
# define N 1111

using namespace std;

int n, h[N];
double ans;

int main() {
  freopen("queue.in", "r", stdin);
  freopen("queue.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
  }
  sort(h + 1, h + 1 + n);
  for (int i = 1; i <= n; i++) {
    int cnt = -1;
    for (int j = 1; j <= n; j++) {
      cnt += (h[j] >= h[i]);
    }
    double ct = 1.0 * cnt / (n - 1);
    double fct = 1.0 * (n - 1 - cnt) / (n - 1);
    double now0 = 1.0, now1 = 1.0, tans = 0.0;
    // printf("%.2f %.2f ", ct, fct);
    for (int j = 1; j <= n; j++) {
      tans += (1.0 * now0 + (n - j) * ct * now1) / n * j;
      // printf("(%.2f %.2f %.2f) ", (1.0 * now0 + (n - j) * ct * now1) / n, now0, now1);
      // j : 1 -> 2
      if (j < n)
      now0 *= (n - cnt - j) * 1.0 / (n - j);
      else now0 = 0.0;
      if (j < n - 1)
      now1 *= (n - cnt - j) * 1.0 / (n - 1 - j);
      else now1 = 0.0;
      // now0 : n - 1选j - 1,不选cnt
      // now1 : n - 2选j - 1,不选cnt - 1
    }
    // printf("%.2f\n", tans);
    ans += tans;
  }
  printf("%.2f", ans);
}