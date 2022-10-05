#include <iostream>
#include <queue>
using namespace std;
const int kMaxN=50;
const int dx[]={0,1,-1,0,0,1,-1,1,-1},dy[]={0,0,0,1,-1,1,-1,-1,1};
char mp[kMaxN][kMaxN];
int n,qx,qy;
int dist[9][kMaxN][kMaxN],d[9];
bool vis[9][kMaxN][kMaxN];
struct QUE
{
  int dis,wind,x,y;
  bool operator< (const QUE &x)const
  {
    return x.dis<dis;
  }
};
void Dij()
{
  priority_queue<QUE>q;
  for(int i=1;i<=8;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)
      {
        dist[i][j][k]=1e9;
        vis[i][j][k]=false;
      }
    }
    q.push((QUE){0,i,qx,qy});
    dist[i][qx][qy]=0;
  }
  while(!q.empty())
  {
    int nowx=q.top().x,nowy=q.top().y,w=q.top().wind;
    q.pop();
    if(vis[w][nowx][nowy])continue;
    vis[w][nowx][nowy]=true;
    for(int i=1;i<=8;i++)
    {
      int xx=nowx+dx[i],yy=nowy+dy[i];
      if(xx<1||xx>n||yy<1||yy>n)continue;
      if(mp[xx][yy]=='X')continue;
      if(dist[w][xx][yy]>dist[w][nowx][nowy]+(i==w?3:1))
      {
        dist[w][xx][yy]=dist[w][nowx][nowy]+(i==w?3:1);
        if(!vis[w][xx][yy])
        {
          q.push((QUE){dist[w][xx][yy],w,xx,yy});
        }
      }
    }
  }
  for(int i=1;i<=8;i++)
  {
    d[i]=1e9;
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)
      {
        if(mp[j][k]=='*')d[i]=min(d[i],dist[i][j][k]);
      }
    }
  }
}
int main()
{
freopen("desert.in","r",stdin);
freopen("desert.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    cin>>mp[i][j];
    if(mp[i][j]=='@')qx=i,qy=j;
  }
}
Dij();
int ans=0;
for(int i=1;i<=8;i++)ans=max(ans,d[i]);
if(ans==1e9)cout<<-1;
else cout<<ans;
return 0;
}