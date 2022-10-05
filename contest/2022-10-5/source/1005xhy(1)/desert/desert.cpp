#include<bits/stdc++.h>
#define re register
#define int long long
//#define gt getchar
using namespace std;
const int N=51,inf=1e6;
int n,m,dis[N*N],a[N*N][N*N];
bool vis[N*N],c[N][N];
char cc;
int id,xs,ys,xe[N*N],ye[N*N],ans;
int mx[8]={1,0,-1,0,1,1,-1,-1};
int my[8]={0,1,0,-1,1,-1,1,-1};
inline char gt()
{
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
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
inline void init(int x)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[xs][ys]=0LL;
}
inline void dijkstra()
{
	for(re int i=1; i<=n; i++)
		for(re int j=1; j<=n; j++)
		{
			int x=0,y=0;
			for(re int k=1; k<=n; k++)
				for(re int l=1; l<=n; l++)
					if(!vis[k][l]&&((x==0&&y==0)||dis[k][l]<dis[x][y]))
						x=k,y=l;
			vis[x][y]=true;
			for(re int k=1; k<=n; k++)
				for(re int l=1; l<=n; l++)
					dis[k][l]=min(dis[k][l],dis[i][j]+a[i][j][k][l]);
		}
}
signed main()
{
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	n=read();
	for(re int i=1; i<=n; i++)
		for(re int j=1; j<=n; j++)
		{
			cc=gt();
			if(cc!='@'&&cc!='-'&&cc!='X'&&cc!='*'){j--;continue;}
			else if(cc=='@')xs=i,ys=j;
			else if(cc=='*')xe[++id]=i,ye[++id]=j;
			else c[i][j]=(cc=='-');
		}
	for(re int i=1; i<=n; i++)
	{
		for(re int j=1; j<=n; j++)
		{
			int u=i*j;
			for(re int k=0; k<8; k++)
			
		}
	}
	ans=inf;
	for(re int i=0; i<8; i++)
	{
		init(i);
		dijkstra();
		for(re int j=1; j<=id; j++)
			ans=max(ans,dis[xe[j]][ye[j]]);
	}
	write(ans);
	return 0;
}
