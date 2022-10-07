# include <bits/stdc++.h>

using namespace std;

long long a, b, k;
int vis[1001000];

int main() {
  freopen("kubi.in", "r", stdin);
  freopen("kubi.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &a, &b, &k);
    memset(vis, 0, sizeof vis);
    for (int i = 1;; i++, a = a * k % b) {
      if (a == 0) {
        printf("%d %d\n", i - 1, 0);
        break;
      }
      if (vis[a]) {
        printf("%d %d\n", vis[a] - 1, i - vis[a]);
        break;
      }
      vis[a] = i;
    }
  }
}