#include<bits/stdc++.h>
using namespace std;
int n,X;
int vis[1005][1005],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool cheakwin(int x,int y,int S)
{
	int tot1=0,tot2=0,tot3=0,tot4=0;
	for(int i=x;i>=1&&vis[i][y]==S;--i)++tot1;
	for(int i=x+1;i<=1000&&vis[i][y]==S;++i)++tot1;
	for(int i=y;i>=1&&vis[x][i]==S;--i)++tot2;
	for(int i=y+1;i<=1000&&vis[x][i]==S;++i)++tot2;
	for(int i=0;vis[i+x][i+y]==S;++i)++tot3;
	for(int i=-1;i+x>=1&&i+y>=1&&vis[i+x][i+y]==S;--i)++tot3;
	for(int i=0;i-y>=1&&vis[i+x][i-y]==S;++i)++tot4;
	for(int i=-1;i+x>=1&&vis[i+x][i-y]==S;--i)++tot4;
	if(tot1>=X||tot2>=X||tot3>=X||tot4>=X)return 1;
	return 0;
}
bool vis2[1005][1005];
int q[2][10005],tot;
int dfs(int x,int y,int s)
{
	int qi=0;
	q[0][++tot]=x,q[1][tot]=y;
	vis2[x][y]=1;
	for(int i=0;i<=3;++i)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>0&&ny>0&&vis[nx][ny]==s&&!vis2[nx][ny])
		{
			qi+=dfs(nx,ny,s);
		}
		if(!vis[nx][ny]&&!vis2[nx][ny]&&nx>0&&ny>0)
		{
			++qi;
			vis2[nx][ny]=1;q[0][++tot]=nx;q[1][tot]=ny;
		}
	}
	return qi;
}
bool weigui(int x,int y,int s)
{
	if(vis[x][y])return 1;
	vis[x][y]=s;
	for(int i=0;i<=3;++i)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(vis[nx][ny]!=s&&vis[nx][ny])
		{
			int qi=0;
			if(s==1)qi=dfs(nx,ny,2);
			else qi=dfs(nx,ny,1);
			if(!qi)while(tot>0)vis[q[0][tot]][q[1][tot]]=vis2[q[0][tot]][q[1][tot]]=0,--tot;
			while(tot>0)vis2[q[0][tot]][q[1][tot]]=0,--tot;
		}
	}
	int qi=dfs(x,y,s);
	while(tot>0)vis2[q[0][tot]][q[1][tot]]=0,--tot;
	if(!qi)return 1;
	return 0;
}
int main()
{
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	scanf("%d%d",&n,&X);
	for(int len=1;len<=n;++len)
	{
		int x,y,s=len%2+1;
		scanf("%d%d",&x,&y);
		if(weigui(x,y,s))
		{
			printf("illegal");
			return 0;
		}
		else if(cheakwin(x,y,s))
		{
			if(s==1)printf("Kitty ");
			else printf("Iter ");
			printf("%d",len);
			return 0;
		}
	}
	printf("draw");
	return 0;
}
