#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m,T;
int r[200010],c[200010];
inline int solve_r()
{
	int res(0x3f3f3f3f);
	int ave = T/n;
	for(int i = 1;i <= n; i++)r[i] -= ave;
	for(int i = 1;i <= n; i++)r[i+n] = r[i];
	for(int i = 1; i <= n; i++)
	{
		int cnt(0);
		int last = r[i];
		for(int j = i+1;j <= i+n-1;j++)
		if(last != 0)
		{
			int now = r[j]+last; 
			cnt += abs(last);
			last = now;
		}
		else 
			last = r[j];
		res = min(res,cnt); 
	}
	return res;
}
inline int solve_c()
{
	int res(0x3f3f3f3f);
	int ave = T/m;
	for(int i = 1;i <= m; i++)c[i] -= ave;
	for(int i = 1;i <= m; i++)c[i+m] = c[i];
	for(int i = 1; i <= m; i++)
	{
		int cnt(0);
		int last = c[i];
		for(int j = i+1;j <= i+m-1;j++)
		if(last != 0)
		{
			int now = c[j]+last; 
			cnt += abs(last);
			last = now;
		}
		else 
			last = c[j];
		res = min(res,cnt); 
	}
	return res;
}
int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i = 1; i <= T; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		r[x]++;
		c[y]++;
	}
	if(T%n != 0&& T%m != 0)puts("impossible");
	else if(T%n == 0 && T%m != 0)printf("row %d\n",solve_r());
	else if(T%n != 0 && T%m == 0)printf("column %d\n",solve_c());
	else  printf("both %d\n",solve_r()+solve_c());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
