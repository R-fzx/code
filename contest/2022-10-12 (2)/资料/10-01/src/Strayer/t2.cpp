#include <cstdio>
#include <cstdlib>

using namespace std ;

typedef unsigned long long ULL;

ULL f[62];

bool chk(ULL a, ULL b, ULL lmt)
{
	ULL r= 1;
	for(int i(1); i<= b; ++ i)
	{
		r *= a;
		if(r > lmt)
			return 0;
	}
	return 1;
}

ULL calc(ULL x)
{
	if(x == 1)
		return 1;
	ULL r= 0;
	ULL cnt= 0;
	for(int i(60); i > 1; -- i)
	{
		ULL l = 1, r = 1000000000;
		while(l < r)
		{
			ULL mid = (l + r) >> 1;
			if(chk(mid, i, x))
				l= mid + 1;
			else
				r= mid;
		}
		f[i]= l - 2;
	}
	for(int i(60); i > 1; -- i)
		for(int j(i - 1); j > 1; -- j)
			if(!(i % j))
				f[j] -= f[i];
	for(int i(2); i<= 60; ++ i)
	{
		r += f[i] * i;
		cnt += f[i];
	}
	return r + (x - cnt);
}

void init()
{
	freopen("t2.in", "r", stdin);
	freopen("t2.out", "w", stdout);
	while(1)
	{
		ULL l, r;
		scanf("%I64u%I64u", &l, &r);
		if(l == 0)
			break;
		printf("%I64u\n", calc(r) - calc(l - 1));
	}
}

int main()
{
	init();
	return 0; 
}
