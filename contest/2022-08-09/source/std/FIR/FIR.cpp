#include<bits\stdc++.h>
using namespace std;
int f[1111][1111],n,x,y,curx,cury,X,cnt;
bool used[1111][1111],fl,cur; 
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int dxx[]={1,-1,0,0,1,-1,1,-1},dyy[]={0,0,1,-1,-1,1,1,-1};
vector<pair<int,int> > v;
void dfs(int x,int y,int ff)
{
	used[x][y]=1;
	v.push_back(make_pair(x,y)); 
	for (int j=0;j<4;j++)
	{
		if (fl) return;
		int xx=x+dx[j],yy=y+dy[j];
		if (used[xx][yy]) continue;
		if (!f[xx][yy])
		{
			fl=1;
			return;
		}
		if (f[xx][yy]==ff) dfs(xx,yy,ff);
	}
}
bool DFS(int x,int y)
{
	v.clear();
	fl=0;
	dfs(x,y,f[x][y]);
	if (!fl)
	{
		for (int i=0;i<v.size();i++)
		{
			f[v[i].first][v[i].second]=0;
		}
	}
	for (int i=0;i<v.size();i++)
	{
		used[v[i].first][v[i].second]=0;
	}
	return fl;
}
int main()
{
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	scanf("%d%d",&n,&X);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if (f[x][y])
		{
			printf("illegal\n");
			return 0;
		}
		f[x][y]=(i&1)+1;
		if (f[x][y+1] && f[x][y+1]!=f[x][y]) DFS(x,y+1);
		if (f[x+1][y] && f[x+1][y]!=f[x][y]) DFS(x+1,y);
		if (f[x][y-1] && f[x][y-1]!=f[x][y]) DFS(x,y-1);
		if (f[x-1][y] && f[x-1][y]!=f[x][y]) DFS(x-1,y);
		if (!DFS(x,y))
		{
			printf("illegal\n");
			return 0;
		}
		for (int j=0;j<4;j++)
		{
			curx=x;cury=y;cnt=1;
			for (int k=0;k<X;k++)
			{
				curx+=dxx[j*2];cury+=dyy[j*2];
				if (f[curx][cury]!=f[x][y]) break;
				cnt++;
			}
			curx=x;cury=y;
			for (int k=0;k<X;k++)
			{
				curx+=dxx[j*2+1];cury+=dyy[j*2+1];
				if (f[curx][cury]!=f[x][y]) break;
				cnt++;
			}
			if (cnt>=X)
			{
				if (i&1) printf("ITer %d\n",i);
				else printf("Kitty %d\n",i);
				return 0;
			}
		}
	}
	printf("draw\n");
	return 0;
 } 
