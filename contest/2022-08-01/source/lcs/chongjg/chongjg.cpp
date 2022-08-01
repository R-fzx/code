#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1005][1005];
void dfs(int A,int b,int sx,int sy)
{
	if(A==0||b==0)return;
	int minn=min(A,b);
	for(int i=1;i<=minn;++i)
		for(int j=1;j<=minn;++j)
			a[sx+i][sy+j]='A';
	if(A>b)
	{
		int f;
		if(a[sx+minn+1][sy]!='B')f=1;
		else f=0;
		for(int i=1;i<=b;++i)
		{
			if(f%2)a[sx+minn+1][sy+i]='B';
			else a[sx+minn+1][sy+i]='C';
			++f;
		}
		sx=sx+minn+1;
		A-=(b+1);
		dfs(A,b,sx,sy);
		return;
	}
	else if(A<b)
	{
		int f;
		if(a[sx][sy+minn+1]!='B')f=1;
		else f=0;
		for(int i=1;i<=b;++i)
		{
			if(f%2)a[sx+i][sy+minn+1]='B';
			else a[sx+i][sy+minn+1]='C';
			++f;
		}
		sy=sy+minn+1;
		b-=(A+1);
		dfs(A,b,sx,sy);
		return;
	}
	return;
}
int main()
{
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(n,m,0,0);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
