#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct T
{
	int p, l, r; bool sp;
	T (void) {}
	T (int _p, int _l, int _r, bool _s) :
		p(_p), l(_l), r(_r), sp(_s) {}
	bool operator < (const T& a) const { return p < a.p; }
};
T rec[130010]; int mr, lt[130010], rt[130010];
const long long mi = 199311170000000LL;
long long P[610][610], L[610][610], R[610][610];
int main ()
{
	freopen("garland.in", "r", stdin), freopen("garland.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%lld", &P[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%lld", &L[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%lld", &R[i][j]);
		mr = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int p = P[i][j] + P[j][i], l = max(L[i][j], L[j][i]), r = min(R[i][j], R[j][i]);
				bool sp = (j == i);
				if (!sp) l <<= 1, r <<= 1;
				rec[mr++] = T(p, l, r, sp);
			}
		}
		sort(rec, rec + mr);
		lt[0] = rec[0].sp ? 0 : -1;
		for (int i = 1; i < mr; i++) lt[i] = rec[i].sp ? i : lt[i - 1];
		rt[mr - 1] = rec[mr - 1].sp ? mr - 1 : -1;
		for (int i = mr - 2; i >= 0; i--) rt[i] = rec[i].sp ? i : rt[i + 1];
		int pwr = 0; long long res = -mi, sum = 0;
		for (int i = 0; i < mr; i++) sum += rec[i].p * rec[i].r, pwr += rec[i].r;
		for (int i = 0; i < mr; i++)
		{
			sum -= rec[i].p * rec[i].r;
			pwr -= rec[i].r; int cur = -pwr;
			if (cur < rec[i].l || cur > rec[i].r)
			{
				sum += rec[i].p * rec[i].l, pwr += rec[i].l;
				continue;
			}
			int dlt;
			if ((cur & 1) && !rec[i].sp)
			{
				dlt = (lt[i] == -1) ? -mi : rec[lt[i]].p - rec[i].p;
				if (rt[i] != -1) dlt = max(dlt, rec[i].p - rec[rt[i]].p);
			}
			else dlt = 0;
			res = max(res, sum + (long long)cur * rec[i].p + dlt);
			sum += rec[i].p * rec[i].l;
			pwr += rec[i].l;
		}
		printf("%lld\n", res >> 1);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
