#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#define double long double
using namespace std;
const int kMaxL=101;
const double eps=1e-7;
const int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int t,r,c,qx,qy,ex,ey;
double tim;
char mp[kMaxL][kMaxL];
double dis[kMaxL][kMaxL];
bool vis[kMaxL][kMaxL];
double Check(double x)
{
  priority_queue<pair<double,pair<int,int> > >q;
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)vis[i][j]=false,dis[i][j]=1e9;
  }
  q.push(make_pair(0.0,make_pair(qx,qy)));
  dis[qx][qy]=0.0;
  while(!q.empty())
  {
    int nowx=q.top().second.first,nowy=q.top().second.second;
    q.pop();
    if(vis[nowx][nowy])continue;
    for(int i=1;i<=4;i++)
    {
      int xx=nowx+dx[i],yy=nowy+dy[i];
      if(xx<1||xx>r||yy<1||yy>c)continue;
      if(mp[xx][yy]=='#')continue;
      if(dis[xx][yy]>dis[nowx][nowy]+(i>=3?1.0:x))
      {
        dis[xx][yy]=dis[nowx][nowy]+(i>=3?1.0:x);
        if(!vis[xx][yy])
        {
          q.push(make_pair(-dis[xx][yy],make_pair(xx,yy)));
        }
      }
    }
  }
  return dis[ex][ey];
}
int main()
{
freopen("maze.in","r",stdin);
freopen("maze.out","w",stdout);
cin>>t;
while(t--)
{
  cin>>tim>>r>>c;
  char sb=getchar();
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)
    {
      char in=getchar();
      if(in==' '||in=='#'||in=='S'||in=='E')mp[i][j]=in;
      if(mp[i][j]=='S')qx=i,qy=j;
      if(mp[i][j]=='E')ex=i,ey=j;
      if(j==c)in=getchar();
    }
  }
  //cout<<qx<<" "<<qy<<" "<<ex<<" "<<ey<<"\n";
  double l=0.0,r=10.0,mid,ans=0.0;
  while(r-l>eps)
  {
    mid=(l+r)/2.0;
    double ck=Check(mid);
    if(fabsl(ck-tim)<=eps)
    {
      ans=mid;
      break;
    }
    else if(ck>tim)ans=mid,r=mid;
    else ans=mid,l=mid;
  }
  cout<<fixed<<setprecision(5)<<ans<<"\n";
}
return 0;
}
