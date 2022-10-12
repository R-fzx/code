#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

const int LMT = 10000;

int N;

struct big_num
{
	int dat[100];
	big_num()
	{
		memset(dat, 0, sizeof(dat));
		dat[0]= 1;
	}
	friend inline void operator *= (big_num &a, int b)
	{
		big_num r;
		int len= a.dat[0];
		for(int i(1); i<= len; ++ i)
		{
			r.dat[i] += a.dat[i] * b;
			if(r.dat[i] >= LMT)
			{
				r.dat[i + 1] = r.dat[i] / LMT;
				r.dat[i] %= LMT;
			}
		}
		a= r;
		a.dat[0]= len;
		if(a.dat[len + 1])
			++a.dat[0];
	}
	void plus()
	{
		dat[1] ++ ;
		for(int i(1); dat[i] >= LMT; ++ i)
		{
			dat[i + 1]= dat[i] / LMT;
			dat[i] %= LMT;
		}
		if(dat[dat[0] + 1])
			++dat[0];
	}
	void dec()
	{
		dat[1] -- ;
		for(int i(1); dat[i] < 0; ++ i)
		{
			dat[i + 1] --;
			dat[i] += LMT;
		}
		if(!dat[dat[0]])
			--dat[0];
	}
	void print()
	{
		printf("%d", dat[dat[0]]);
		for(int i(dat[0] - 1); i; -- i)
			printf("%04d", dat[i]);
		printf("\n");
	}
};

void init()
{
	freopen("t3.in", "r", stdin);
	freopen("t3.out", "w", stdout);
	scanf("%d", &N);
}

void solve()
{
	big_num ans;
	ans.dat[1]= 1;
	for(int i(3); i<= N; ++ i)
	{
		ans *= i;
		if(i & 1)
			ans.dec();
		else
			ans.plus();
		//ans.print();
	}
	ans.print();
}

int main()
{
	init();
	solve();
	return 0;
}
