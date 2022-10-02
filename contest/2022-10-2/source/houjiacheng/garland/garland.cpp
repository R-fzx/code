# include <stdio.h>
# include <algorithm>
# define ll long long
# define N (500 * 500 + 50)

using namespace std;

struct str {
  ll l, r, k, id;
} s[N];
int n;
ll ans, now;

bool cmp(str a, str b) {
  if (a.k == b.k) {
    return a.id < b.id;
  }
  return a.k > b.k;
}

int main() {
  freopen("garland.in", "r", stdin);
  freopen("garland.out", "w", stdout);
  scanf("%d", &n);
  int cn = n;
  n *= n;
  ll l = 0;
  for (int i = 1;  i <= n; i++) {
    scanf("%lld", &l);
    s[i].k = l;
    int x = (i - 1) / cn;
    int y = (i - 1) % cn;
    s[i].id = min(x + y * cn, x * cn + y);
  }
  for (int i = 1;  i <= n; i++) {
    scanf("%lld", &l);
    s[i].l = l;
    now += l;
    ans += l * s[i].k;
  }
  for (int i = 1;  i <= n; i++) {
    scanf("%lld", &l);
    s[i].r = l;
  }
  sort(s + 1, s + 1 + n, cmp);
  int i = 1;
  s[n + 1].id = -1;
  int ls1 = 0, fs2 = 0;
  while (now < 0 && i <= n) {
    if (s[i].id != s[i + 1].id) {
      int cnow = now;
      if (s[i].r - s[i].l + now > 0) {
        now = 0;
        ans += (-now) * s[i].k;
      } else {
        ans += (s[i].r - s[i].l) * s[i].k;
        now += s[i].r - s[i].l;
      }
      if(cnow != now) {
        ls1 = i;
      }
      i++;
    } else {
      if ((s[i].r - s[i].l) * 2 + now > 0) {
        now += ((-now) & 0xfffffffe);
        ans += ((-now) & 0xfffffffe) * s[i].k;
        if (fs2 = 0) {
          fs2 = i;
        }
      } else {
        ans += (s[i].r - s[i].l) * 2 * s[i].k;
        now += (s[i].r - s[i].l) * 2;
      }
      i += 2;
    }
  }
  if (now < 0) {
    ans -= s[ls1].k;
    ans += s[fs2].k * 2;
  }
  printf("%lld", ans);
}
// xy = n! * (x+y)
/*

4
7 0 1 0
0 0 0 0
1 0 0 0
0 0 0 0
1 -10 -10 -10
-10 1 -10 -10
-10 -10 1 -10
-10 -10 -10 1
9 10 10 10
10 10 10 10
10 10 10 10
10 10 10 10

*/