#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std ;

const int max_n = 500005;
const __int64 inf = 999999999999999999ll;

struct node
{
	int a, b, c, idx; 
};

int N, A, B, C;
node d_old[max_n], d_sort[max_n], d[305];
int flag[max_n]; int tot;
__int64 dp[102][102][102], sum[102][102][102];

void init()
{
	freopen("ゆりっぺ.in", "r", stdin);
	freopen("ゆりっぺ.out", "w", stdout);
	scanf("%d%d%d%d", &N, &A, &B, &C);
	for(int i(1); i<= N; ++ i)
	{
		scanf("%d%d%d", &d_old[i].a, &d_old[i].b, &d_old[i].c);
		d_old[i].idx = i;
		d_sort[i] = d_old[i];
	}
}

inline bool cmp1(node a, node b)
{
	return a.a > b.a ;
}

inline bool cmp2(node a, node b)
{
	return a.b > b.b;
}

inline bool cmp3(node a, node b)
{
	return a.c > b.c;
}

void solve()
{
	if(A + B + C > N)
	{
		printf("I am a godlike cowcowcow\n");
		return ;
	}
	int t = A + B + C;
	
	partial_sort(d_sort + 1, d_sort + 1 + t, d_sort + 1 + N, cmp1);
	for(int i(1); i<= t; ++ i)
		flag[d_sort[i].idx]= 1;
	partial_sort(d_sort + 1, d_sort + 1 + t, d_sort + 1 + N, cmp2);
	for(int i(1); i<= t; ++ i)
		flag[d_sort[i].idx]= 1;
	partial_sort(d_sort + 1, d_sort + 1 + t, d_sort + 1 + N, cmp3);
	for(int i(1); i<= t; ++ i)
		flag[d_sort[i].idx]= 1;
	for(int i(1); i<= N; ++ i)
		if(flag[i])
			d[++tot]= d_old[i];
	
	for(int i(0); i<= A; ++ i)
		for(int j(0); j<= B; ++ j)
			for(int k(0); k<= C; ++ k)
				dp[i][j][k] = sum[i][j][k] = - inf;
	dp[0][0][0]= sum[0][0][0]= 0;
	for(int p(1); p<= tot; ++ p)
	{
		for(int i(A); i >= 0; -- i)
			for(int j(B); j >= 0; -- j)
				for(int k(C); k >= 0; -- k)
				{
					__int64 tmp_sum = sum[i][j][k] + d[p].a + d[p].b + d[p].c;
					if(dp[i][j][k] + d[p].a == dp[i + 1][j][k])
						sum[i + 1][j][k] >?= tmp_sum;
					if(dp[i][j][k] + d[p].a > dp[i + 1][j][k])
						dp[i + 1][j][k]= dp[i][j][k] + d[p].a,
						sum[i + 1][j][k] = tmp_sum;
					
					if(dp[i][j][k] + d[p].b == dp[i][j + 1][k])
						sum[i][j + 1][k] >?= tmp_sum;
					if(dp[i][j][k] + d[p].b > dp[i][j + 1][k])
						dp[i][j + 1][k]= dp[i][j][k] + d[p].b,
						sum[i][j + 1][k] = tmp_sum;
					
					if(dp[i][j][k] + d[p].c == dp[i][j][k + 1])
						sum[i][j][k + 1] >?= tmp_sum;
					if(dp[i][j][k] + d[p].c > dp[i][j][k + 1])
						dp[i][j][k + 1]= dp[i][j][k] + d[p].c,
						sum[i][j][k + 1] = tmp_sum;
				}
	}		
	printf("%I64d\n%I64d\n", dp[A][B][C], sum[A][B][C]);
}

int main()
{
	init();
	solve();
	return 0;
}
