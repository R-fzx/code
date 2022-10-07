#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
typedef map<LL, int> type;
typedef type::const_iterator trc;
#define X first
#define Y second
LL gcd (LL a, LL b) { return b ? gcd(b, a % b) : a; }

type divi (LL a)
{
	type r;
	for (int i = 2; (LL)i * i <= a; i++)
	{
		if (a % i == 0)
		{
			int p = 0;
			while (a % i == 0) ++p, a /= i;
			r[i] = p;
		}
	}
	if (a != 1) r[a] = 1;
	return r;
}
LL euler (LL a, const type& r)
{
	for (trc i = r.begin(); i != r.end(); i++)
	{
		if (i->Y) a = a / i->X * (i->X - 1);
	} return a;
}
LL hmul (LL a, LL b, LL m)
{
	LL ans = 0, p = a % m;
	while (b)
	{
		if (b & 1) ans = (ans + p) % m;
		p = (p + p) % m;
		b >>= 1;
	} return ans;
}
LL hmod (LL a, LL b, LL m)
{
	LL ans = 1, p = a % m;
	while (b)
	{
		if (b & 1) ans = hmul(ans, p, m);
		p = hmul(p, p, m);
		b >>= 1;
	} return ans;
}
int main ()
{
	freopen("kubi.in", "r", stdin), freopen("kubi.out", "w", stdout);
	LL a, b, k; int t; for (scanf("%d", &t); t; --t)
	{
		scanf("%I64d %I64d %I64d", &a, &b, &k);
		LL g = gcd(a, b); a /= g, b /= g;
		type sb = divi(b), sk = divi(k);
		int p1 = 0; LL nb = b;
		for (trc i = sk.begin(); i != sk.end(); i++)
		{
			int p = sb[i->X]; sb[i->X] = 0;
			p1 = max(p1, (p + i->Y - 1) / i->Y);
			while (p)
			{
				nb /= i->X, --p;
			}
		}
		LL p2; if (nb == 1) p2 = 0;
		else
		{
			LL eb = euler(nb, sb);
			p2 = eb;
			sb = divi(eb);
			for (trc i = sb.begin(); i != sb.end(); i++)
			{
				int p = i->Y;
				while (p)
				{
					if (hmod(k, p2 / i->X, nb) == 1)
					{
						--p, p2 /= i->X;
					}
					else break;
				}
			}
		}
		printf("%d %I64d\n", p1, p2);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
