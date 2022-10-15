#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std ;

struct person
{
	int b, l;
};

double ans, res;
int N, K, A;
person p[10];
bool flag[10];

void init()
{
	freopen("assembly.in", "r", stdin);
	freopen("assembly.out", "w", stdout);
	scanf("%d%d%d", &N, &K, &A);
	for(int i(1); i<= N; ++ i)
		scanf("%d%d", &p[i].b, &p[i].l);
}

void update()
{
	double abl = 1;
	int cnt = 0, B = 0;
	for(int i(1); i<= N; ++ i)
	{
		if(flag[i])
		{
			abl *= p[i].l / 100.0;
			cnt ++ ;
		}else
		{
			B += p[i].b;
			abl *= (100 - p[i].l) / 100.0;
		}
	}
	if(cnt > (N >> 1))
	{
		res += abl;
		return ;
	}
	res += abl * (A / double(A + B));
	
}

void search_vote(int pos)
{
	if(pos > N)
	{
		update();
		return ;
	}
	flag[pos] = 1;
	search_vote(pos + 1);
	flag[pos] = 0; 
	search_vote(pos + 1);
}

void search_gift(int pos, int rest)
{
	if(!rest)
	{
		res = 0;
		search_vote(1);
		ans = max(ans, res);
		return ;
	}
	if(pos > N)
		return ;
	int bak = p[pos].l ;
	for(int i(0); i<= rest; ++ i)
	{
		p[pos].l = min(bak + i * 10, 100);
		search_gift(pos + 1, rest - i);
	}
	p[pos].l = bak;
}

void solve()
{
	search_gift(1, K);
	printf("%.6lf\n", ans);
}

int main()
{
	init();
	solve();
	return 0;
}
