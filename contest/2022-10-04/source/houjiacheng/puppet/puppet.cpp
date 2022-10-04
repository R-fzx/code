# include <stdio.h>
# include <algorithm>
# include <string.h>
# define abs(a) ((a)<0?-(a):(a))

using namespace std;

int f[100], n;
int p[100];

int s(int l, int r) {
  if (r - l <= 1) {
    return 0;
  }
  for (int i = 1; i <= r - l; i++) {
    if (abs(p[r - i + 1] - p[l + i - 1]) <= 1) {
      return i - 1;
    }
    for (int j = l; j <= r - i; j++) {
      if (p[j + i] - p[j] > 1) {
        return i - 1;
      }
    }
  }
  return 0;
}

int main() {
  freopen("puppet.in", "r", stdin);
  freopen("puppet.out", "w", stdout);
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", p + i);
    }
    sort(p + 1, p + 1 + n);
    memset(f, 0, sizeof f);
    for (int i = 3; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        f[i] = max(f[i], f[j] + s(j + 1, i));
      }
    }
    printf("%d\n", f[n]);
  }
}
