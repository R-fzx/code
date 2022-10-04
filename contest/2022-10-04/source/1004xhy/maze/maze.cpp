#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define re register
#define gt getchar
using namespace std;
const int N=109;
int T,n,m;
double l,ans;
int xs,ys,xe,ye;
char c[N][N];
bool vis[N][N];
struct node{
	int x,y;
}f[N][N];
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
inline int read()
{
	re int x=0;
	re char ch=gt();
	while(ch<48||ch>57)ch=gt();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
} 
inline void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void dfs(int fx,int fy,int x,int y)
{
	if(c[x][y]=='E')return;
	for(re int i=0; i<4; i++)
	{
		if(c[x+mx[i]][y+my[i]]!='#'&&(fx!=x+mx[i]||fy!=y+my[i]))
		{
			if(i&1)
			{
				if(f[x][y+my[i]].y>f[x][y].y+1)
					f[x][y+my[i]].x=f[x][y].x,f[x][y+my[i]].y=f[x][y].y+1,dfs(x,y,x,y+my[i]);
			}
			else
			{
				if(f[x+mx[i]][y].x>f[x][y].x+1)
					f[x+mx[i]][y].y=f[x][y].y,f[x+mx[i]][y].x=f[x][y].x+1,dfs(x,y,x+mx[i],y);
			}
		}
	}
}
signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	T=read();
	while(T--)
	{
		scanf("%lf",&l),n=read(),m=read();
		for(re int i=1; i<=n; gt(),i++)
			for(re int j=1; j<=m; j++)
			{
				c[i][j]=gt();
				if(c[i][j]=='S')
					xs=i,ys=j;
				if(c[i][j]=='E')
					xe=i,ye=j;
				f[i][j].x=f[i][j].y=1e5;
			}
		f[xs][ys].x=f[xs][ys].y=0,dfs(0,0,xs,ys);
		ans=1.0*(l-f[xe][ye].y)/f[xe][ye].x;
		printf("%.5lf\n",ans);
	}
	return 0;
}
