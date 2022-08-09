#include<bits\stdc++.h>
#include<windows.h>
using namespace std;
int f[1111][1111],n,x,y,curx,cury,X,cnt,ap;
bool used[1111][1111],fl,cur; 
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int dxx[]={1,-1,0,0,1,-1,1,-1},dyy[]={0,0,1,-1,-1,1,1,-1};
vector<pair<int,int> > v;
bool fs;
pair<int,int> num[1111111];
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
	//freopen("1.out","w",stdout);
	srand(GetTickCount());
	n=1000;X=rand()%10+1;
	printf("%d %d\n",n,X);
	x=rand()%200+1;y=rand()%200+1;
	printf("%d %d\n",x,y);
	f[x][y]=2;
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=200;j++)
		num[(i-1)*200+j]=make_pair(i,j);
	}
	for (int i=2;i<=n;i++)
	{
		ap=rand();
		if (ap>36500)
		{
			for (int j=1;j<=200;j++)
			{
				for (int k=1;k<=200;k++)
				{
					if (f[j][k]) 
					{
						printf("%d %d\n",j,k);
					}
				}
			}
			for (int j=i+1;j<=n;j++)
			{
				printf("%d %d\n",rand()%200+1,rand()%200+1);
			}
			return 0;
		}
		random_shuffle(num+1,num+40001);
		for (int j=1;j<=40000;j++)
		{
			x=num[j].first;y=num[j].second;
			if (f[x][y]) continue;
			fs=0;
			for (int h=0;h<4;h++)
			{
				int xx=x+dx[h],yy=y+dy[h];
				if (f[xx][yy])
				{
					fs=1;
					break;
				}
			}
			if (fs) break;
		}
		printf("%d %d\n",x,y);
		f[x][y]=(i&1)+1;
		if (f[x][y+1] && f[x][y+1]!=f[x][y]) DFS(x,y+1);
		if (f[x+1][y] && f[x+1][y]!=f[x][y]) DFS(x+1,y);
		if (f[x][y-1] && f[x][y-1]!=f[x][y]) DFS(x,y-1);
		if (f[x-1][y] && f[x-1][y]!=f[x][y]) DFS(x-1,y);
	}
	return 0;
}
