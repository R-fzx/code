#include <iostream>
using namespace std;
const int kMaxN=1002;
const int Limit=1000;
const int dx[]={0,1,-1,0,0,1,-1,1,-1},dy[]={0,0,0,1,-1,1,-1,-1,1};
int color[kMaxN][kMaxN];
int n,win;
bool vis[kMaxN][kMaxN];
bool Check(int x,int y,int c)
{
  for(int i=1;i<=4;i++)
  {
    int xx=x+dx[i],yy=y+dy[i];
    if(xx>Limit||xx<1||yy>Limit||yy<1||vis[xx][yy])continue;
    if(color[xx][yy]==(c^1))continue;
    if(!color[xx][yy])return true;
    vis[xx][yy]=true;
    //cout<<xx<<" "<<yy<<" "<<" "<<color[xx][yy]<<"Check\n";
    bool flag=Check(xx,yy,c);
    vis[xx][yy]=false;
    if(flag)return true;
  }
  color[x][y]=0;
  return false;
}
bool Place(int c,int x,int y)
{
  if(color[x][y])return 0;
  color[x][y]=c;
  bool eatother=false;
  for(int i=1;i<=4;i++)
  {
    int xx=x+dx[i],yy=y+dy[i];
    if(xx>Limit||xx<1||yy>Limit||yy<1||vis[xx][yy]||!color[xx][yy])continue;
    if(color[xx][yy]==(c^1))
    {
      //cout<<xx<<" "<<yy<<" "<<color[xx][yy]<<" "<<c<<"Check\n";
      vis[xx][yy]=true;
      if(!(Check(xx,yy,color[xx][yy])))
      {
        eatother=true;
        color[xx][yy]=false;
        //cout<<xx<<" "<<yy<<" "<<"eaten\n";
      }
      vis[xx][yy]=false;
    }
  }
  if(eatother)return true;
  if(!Check(x,y,color[x][y]))return false;
  return true;
}
int Fan(int x)
{
  if(x%2==1)return x+1;
  return x-1;
}
bool Win(int x,int y)
{
  for(int i=1;i<=8;i++)
  {
    int xx=x,yy=y,num=0;
    while(xx<=Limit&&xx>=1&&yy<=Limit&&yy>=1&&color[xx][yy]==color[x][y])
    {
      num++;
      if(num==win)return true;
      xx+=dx[i],yy+=dy[i];
    }
    int j=Fan(i);
    xx=x+dx[j],yy=y+dy[j];
    while(xx<=Limit&&xx>=1&&yy<=Limit&&yy>=1&&color[xx][yy]==color[x][y])
    {
      num++;
      if(num==win)return true;
      xx+=dx[j],yy+=dy[j];
    }
  }
  return false;
}
int main()
{
freopen("FIR.in","r",stdin);
freopen("FIR.out","w",stdout);
cin>>n>>win;
for(int i=1;i<=n;i++)
{
  int x,y;
  cin>>x>>y;
  if(i%2==1)
  {
    if(!Place(2,x,y))
    {
      cout<<"illegal";
      return 0;
    }
    else if(Win(x,y))
    {
      cout<<"ITer "<<i;
      return 0;
    }
  }
  else
  {
    if(!Place(3,x,y))
    {
      cout<<"illegal";
      return 0;
    }
    else if(Win(x,y))
    {
      cout<<"Kitty "<<i;
      return 0;
    }
  }
}
cout<<"draw";
return 0;
}