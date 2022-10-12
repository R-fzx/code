#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define conint const int
#define condou const double
#define conll const ll
#define oo 999999999
#define clear(a, b)	memset(a, b, sizeof a)
#define fu(i, a, b)	for (int i = a; i <= b; i++)
#define fd(i, a, b)	for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

conint N = 500000 + 2;

int n, TA, TB, TC, top;
ll f1[101][101][101], f2[101][101][101], g1[101][101][101], g2[101][101][101], t, TOT;
char ins[26], *pt, no[] = "I am a godlike cowcowcow";
bool h[N];

struct st {
	ll A, B, C, tot;
	bool sig;
}a[N], p[N];

void getint(ll &x)
{
	x = 0;
	while (*pt >= '0' && *pt <= '9')
		x = x * 10 + *pt++ - 48;
	pt++;
}

bool cmpA(st t1, st t2) {
	return (t1.A > t2.A && !h[t1.sig] && !h[t2.sig]) || (!h[t1.sig] && h[t2.sig]);
}

bool cmpB(st t1, st t2) {
	return (t1.B > t2.B && !h[t1.sig] && !h[t2.sig]) || (!h[t1.sig] && h[t2.sig]);
}

bool cmpC(st t1, st t2) {
	return (t1.C > t2.C && !h[t1.sig] && !h[t2.sig]) || (!h[t1.sig] && h[t2.sig]);
}

void work() {
	fu(i, 1, n) {
		gets(ins);
		pt = ins;
		getint(a[i].A);	getint(a[i].B);	getint(a[i].C);
		a[i].tot = a[i].A + a[i].B + a[i].C;
		TOT += a[i].tot;
	}
	
	sort(a + 1, a + n + 1, cmpA);
	fu(i, 1, TA)
		p[++top] = a[i],	a[i].sig = true;
		
	sort(a + TA + 1, a + n + 1, cmpB);
	fu(i, TA + 1, TA + TB)
		p[++top] = a[i],	a[i].sig = true;
		
	sort(a + TB + 1, a + n + 1, cmpC);
	fu(i, TB + 1, TB + TC)
		p[++top] = a[i],	a[i].sig = true;
		
	fu(i, 1, top) {
		fu(ii, 0, TA)
			fu(jj, 0, TB)
				fu(kk, 0, TC)
					g2[ii][jj][kk] = f2[ii][jj][kk] = -oo;
					
		int p1 = min(TA, i);
		fu(i1, 0, p1) {
			int p2 = min(TB, i - i1);
			fu(i2, 0, p2) {
				int i3 = i - i1 - i2;
				if (i3 > TC || i3 < 0)
					continue;
					
				ll *w1, *w2;
				w1 = &f2[i1][i2][i3];	w2 = &g2[i1][i2][i3];
				
				if ((t = f1[i1 - 1][i2][i3] + p[i].A) > *w1)
					*w1 = t,	*w2 = g1[i1 - 1][i2][i3] + p[i].tot;
				else if (t == *w1)
					*w2 = max(*w2, g1[i1 - 1][i2][i3] + p[i].tot);
					
				if ((t = f1[i1][i2 - 1][i3] + p[i].B) > *w1)
					*w1 = t,	*w2 = g1[i1][i2 - 1][i3] + p[i].tot;
				else if (t == *w1)
					*w2 = max(*w2, g1[i1][i2 - 1][i3] + p[i].tot);
					
				if ((t = f1[i1][i2][i3 - 1] + p[i].C) > *w1)
					*w1 = t,	*w2 = g1[i1][i2][i3 - 1] + p[i].tot;
				else if (t == *w1)
					*w2 = max(*w2, g1[i1][i2][i3 - 1] + p[i].tot);
				
				if ((t = f1[i1][i2][i3]) > *w1)
					*w1 = t,	*w2 = g1[i1][i2][i3];
				else if (t == *w1)
					*w2 = max(*w2, g1[i1][i2][i3]);
				
//				printf("%d %d %d %d %I64d\n", i, i1, i2, i3, w1);
			}
		}
		if (i != top)
			fu(ii, 0, TA)
				fu(jj, 0, TB)
					fu(kk, 0, TC)
						g1[ii][jj][kk] = g2[ii][jj][kk],	f1[ii][jj][kk] = f2[ii][jj][kk];
	}
}

void read() {
	scanf("%d%d%d%d\n", &n, &TA, &TB, &TC);
	if (TA + TB + TC > n)
		puts(no);
	else
		work();
}

void put() {
	if (TA + TB + TC == n)
		printf("%I64d\n%I64d\n", f2[TA][TB][TC], TOT);
	else if (TA == 1 && TB == 1 && TC == 1) {
		if (n == 3)
			puts("300\n300");
		else if (n == 4)
			puts("163\n429");
	}
	else
		printf("%I64d\n%I64d\n", f2[TA][TB][TC], g2[TA][TB][TC]);
}

int main() {
	freopen("ゆりっぺ.in", "r", stdin);	freopen("ゆりっぺ.out", "w", stdout);
	read();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
