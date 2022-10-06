# include <stdio.h>
# define mod 1000000009ll
# define ll long long
# define N 300300

using namespace std;

int n, m, q;
ll ans;
int f[N];

int fi (int x) {
  return x == f[x] ? x : f[x] = fi(f[x]);
}

int main() {
  freopen("magician.in", "r", stdin);
  freopen("magician.out", "w", stdout);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (m = 1; m <= q; m++) {
    int s, t;
    scanf("%d%d", &s, &t);
    int fs = fi(s), ft = fi(t);
    if (fs == ft) {
      ans = (ans + ans + 1) % mod;
    } else {
      f[fs] = ft;
    }
    printf("%lld\n", ans);
  }
}
/*


*/

