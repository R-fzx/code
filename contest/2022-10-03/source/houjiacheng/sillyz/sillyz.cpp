# include <stdio.h>

using namespace std;

int sum[1001000];

int main() {
  freopen("sillyz.in", "r", stdin);
  freopen("sillyz.out", "w", stdout);
  long long a, b;
  scanf("%lld%lld", &a, &b);
  if (b > 1000000) {
    return 0;
  }
  for (int i = 1; i <= 1000000; i++) {
    int x = i, y = i;
    while(x <= 1000000 && y) {
      x *= y % 10;
      y /= 10;
    }
    if (x <= 1000000) {
      sum[x]++;
    }
  }
  int ans = 0;
  for (int i = a; i <= b; i++) {
    ans += sum[i];
  }
  printf("%d", ans);
}