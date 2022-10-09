#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i, l, r) for (int i = l; i < r; i++)
#define drep(i, r, l) for (int i = r - 1; i >= l; i--)
typedef long long LL;
const LL UB = 1000000000LL;
const int maxn = 300010;
  
int tv, tc[8];
int rv[maxn], rc[maxn][8], mr;
  
void dfs (int r, int s)
{
    if (r == 10 || s >= 18) return;
    dfs(r + 1, s);
    if ((LL)tv * r > UB) return;
    tv *= r, ++tc[r - 2];
    rv[mr] = tv; rep (i, 0, 8) rc[mr][i] = tc[i]; ++mr;
    dfs(r, s + 1);
    tv /= r, --tc[r - 2];
}
LL frac[19];
LL stat0 (int rem)
{
    int tc1 = rem;
    rep (i, 0, 8) tc1 -= tc[i];
    LL res = frac[rem] / frac[tc1];
    rep (i, 0, 8) res /= frac[tc[i]];
    return res;
}
LL stat1 (LL b, int ms)
{
    if (b == 0) return 0;
    LL res = 0;
    int d[19]; rep (i, 0, 19) d[i] = b % 10, b /= 10;
    int k = 18; while (!d[k]) --k;
    int s = 0; rep (i, 0, 8) tc[i] = rc[ms][i], s += tc[i];
    rep (i, 1, k + 1) if (i >= s) res += stat0(i);
    for (; k >= 0; --k)
    {
        if (d[k] == 0 || s - 1 > k) break;
        rep (i, 2, d[k])
        {
            if (tc[i - 2])
            {
                --tc[i - 2], --s;
                if (k >= s) res += stat0(k);
                ++tc[i - 2], ++s;
            }
        }
        if (d[k] > 1)
        {
            if (k >= s) res += stat0(k);
            if (!tc[d[k] - 2]) break;
            --tc[d[k] - 2], --s;
        }
    }
    return res;
}
LL stat2 (LL b)
{
    if (b == 0) return 0;
    LL res = 0;
    rep (i, 0, mr) res += stat1(b / rv[i] + 1, i);
    return res;
}
int main ()
{
    freopen("sillyz.in", "r", stdin);
    freopen("sillyz.out", "w", stdout);
    mr = 1, rv[0] = 1; tv = 1, dfs(2, 0);
    frac[0] = 1; rep (i, 1, 19) frac[i] = frac[i - 1] * i;
    LL l, r; scanf("%lld %lld", &l, &r);
    printf("%lld\n", stat2(r) - stat2(l - 1));
    return 0;
}
