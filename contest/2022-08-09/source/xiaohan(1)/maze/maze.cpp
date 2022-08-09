#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m,X,c[25][25],now,ans;
map<int,int> num;
void zs(int x,int y,int mx,int my)
{	now^=c[x][y];
	if(x==mx&&y==my)
	{	num[now]++;
		now^=c[x][y];
		return ;
	}
	if(x<mx&&c[x+1][y])zs(x+1,y,mx,my);
	if(y<my&&c[x][y+1])zs(x,y+1,mx,my);
	now^=c[x][y];
	return ;
}
void yx(int x,int y,int mx,int my)
{	now^=c[x][y];
	if(x==mx&&y==my&&num.count(now^X^c[x][y]))
	{	ans+=num[now^x^c[x][y]];
		now^=c[x][y];
		return ;
	}
	if(x>mx&&c[x-1][y])yx(x-1,y,mx,my);
	if(y>my&&c[x][y-1])yx(x,y-1,mx,my);
	now^=c[x][y];
	return ;
}
signed main()
{	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),X=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			c[i][j]=read();
	for(register int i=n,j=1;i>=1&&j<=m;--i,++j)
	{
		if(!c[i][j])continue;
		num.clear();
		now=0,zs(1,1,i,j);
		now=0,yx(n,m,i,j);
	}
	cout<<ans;
	return 0;
}

