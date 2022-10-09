#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef long long LL;
int cal (LL m1, LL n1, LL m2, LL n2, LL &a, LL &b)
{
    if (m1 < n1 && m2 > n2) a = 1, b = 1;
    else if (m1 >= n1 && m2 >= n2)
    {
        LL k = n1 ? (n2 ? min(m1 / n1, m2 / n2) : m1 / n1) : m2 / n2;
        cal(m1 - k * n1, n1, m2 - k * n2, n2, a, b), a += k * b;
    }
    else cal(n2, m2, n1, m1, b, a); return 0;
}
LL gcd (LL a, LL b) { return b ? gcd(b, a % b) : a; }
int main ()
{
	freopen("baseball.in", "r", stdin), freopen("baseball.out", "w", stdout);
    int n; LL deno, nemo, a, b;
    while (scanf("%d 0.%lld", &n, &nemo) == 2)
    {
        for (deno = 2; n; deno *= 10, --n);
        nemo ? cal(nemo * 2 - 1, deno, nemo * 2 + 1, deno, a, b) : (b = 1);
        if (nemo)
        {
			LL g = gcd(nemo * 2 - 1, deno);
			b = min(b, deno / g);
		}
        printf("%lld\n", b);
    }
    fclose(stdin), fclose(stdout);
	return 0;
}
