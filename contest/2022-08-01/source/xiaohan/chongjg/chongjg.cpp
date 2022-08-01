#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m;
char c[1005][1005];
void dfs(int sx,int sy)
{	int bc=min(n-sx+1,m-sy+1);
	char s=c[sx-1][sy],z=c[sx][sy-1],now;
	if(s+z=='A'+'B')now='C';
	else if(s!='A'&&z!='A')now='A';
	else if(s!='B'&&z!='B')now='B';
	if(n-sx+1<m-sy+1)
	{	for(register int i=sx;i<=sx+bc-1;++i)
			for(register int j=sy;j<=sy+bc-1;++j)
				c[i][j]=now;
		dfs(sx,sy+bc);
	}
	else if(n-sx+1==m-sy+1)
	{	for(register int i=sx;i<=sx+bc-1;++i)
			for(register int j=sy;j<=sy+bc-1;++j)
				c[i][j]=now;
		return ;
	}
	else if(n-sx+1>m-sy+1)
	{	for(register int i=sx;i<=sx+bc-1;++i)
			for(register int j=sy;j<=sy+bc-1;++j)
				c[i][j]=now;
		dfs(sx+bc,sy);
	}
	return ;
} 
int main()
{	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	n=read(),m=read();
	dfs(1,1);
	for(register int i=1;i<=n;++i)
	{	for(register int j=1;j<=m;++j)
			cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}

