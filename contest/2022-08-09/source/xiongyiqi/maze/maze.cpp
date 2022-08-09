//maze
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,aim,ans;
int a[25][25];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void bfs(int x,int y,int num)
{
	if(x==n && y==m && num==aim)
	{
		++ans;
	}
	
	if(a[x+1][y]!=0)
		bfs(x+1,y,num^a[x+1][y]);
	if(a[x][y+1]!=0)
		bfs(x,y+1,num^a[x][y+1]);
		
	return ;
}

signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	n=read(),m=read(),aim=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read();
			
	bfs(1,1,a[1][1]);
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

