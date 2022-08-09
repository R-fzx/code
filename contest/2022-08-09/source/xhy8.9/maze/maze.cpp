#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int N=50,M=50,X=12000;
int n,m,x,ans,tty;
int a[N][M];
int f[N][M][X];
inline char gt() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
	register int x=0;
	register char ch;
	while(ch<48||ch>57)ch=gt();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
}
inline void write(register int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		if(tty==x)ans++;
		return;
	}
	if(x<n)tty^=a[x+1][y],dfs(x+1,y),tty^=a[x+1][y];
	if(y<m)tty^=a[x][y+1],dfs(x,y+1),tty^=a[x][y+1];
	return;
}
signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),x=read();
	for(re int i=1; i<=n; i++)
		for(re int j=1; j<=m; j++)
			a[i][j]=read();
	if(n<=10&&m<=10)
	{
		dfs(1,1);
		write(ans);
		return 0;
	}
	f[1][1][a[1][1]]=1;
	for(re int i=1; i<=n; i++)
		for(re int j=1; j<=m; j++)
		{
			if(i==1&&j==1)continue;
			if(!a[i][j])continue;
			for(re int k=0; k<=11111; k++)
			{
				if(!a[i][j-1])
					f[i][j][k]=f[i][j][k]+f[i][j-1][k^a[i][j]];
				if(!a[i-1][j])
					f[i][j][k]=f[i][j][k]+f[i-1][j][k^a[i][j]];
			}
		}
	write(f[n][m][x]);
//	cerr<<clock();
	return 0;
}
