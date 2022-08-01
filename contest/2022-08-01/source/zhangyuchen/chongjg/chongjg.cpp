#include <iostream>
using namespace std;
const int kMaxN=105;
bool can[kMaxN][kMaxN][27];
int n,m;
struct XDS
{
  int sum,tag;
}tr[kMaxN][kMaxN*4];
void Spread(int th,int where,int wl,int wr)
{
  int mid=(wl+wr)>>1;
  if(!tr[th][where].tag)return;
  tr[th][where<<1].tag=tr[th][where].tag;
  tr[th][where<<1].sum=tr[th][where].tag*(mid-wl+1);
  tr[th][where<<1|1].tag=tr[th][where].tag;
  tr[th][where<<1|1].sum=tr[th][where].tag*(wr-mid);
  tr[th][where].tag=0;
}
int Get(int th,int where,int wl,int wr,int l,int r)
{
  if(wl>=l&&wr<=r)
  {
    return tr[th][where].sum;
  }
  Spread(th,where,wl,wr);
  int mid=(wl+wr)>>1,ans=0;
  if(mid>=l)ans+=Get(th,where<<1,wl,mid,l,r);
  if(mid<r)ans+=Get(th,where<<1|1,mid+1,wr,l,r);
  tr[th][where].sum=tr[th][where<<1].sum+tr[th][where<<1|1].sum;
  return ans;
}
void Update(int th,int where,int wl,int wr,int l,int r,int k)
{
  if(wl>=l&&wr<=r)
  {
    tr[th][where].sum=k*(wr-wl+1);
    tr[th][where].tag=k;
    return;
  }
  Spread(th,where,wl,wr);
  int mid=(wl+wr)>>1;
  if(mid>=l)Update(th,where<<1,wl,mid,l,r,k);
  if(mid<r)Update(th,where<<1|1,mid+1,wr,l,r,k);
  tr[th][where].sum=tr[th][where<<1].sum+tr[th][where<<1|1].sum;
}
bool Check(int qx,int qy,int ex,int ey)
{
  for(int i=qx;i<=ex;i++)
  {
    if(Get(i,1,1,m,qy,ey))return false;
  }
  return true;
}
void Colour(int x,int y)
{
  int num=0;
  for(int i=1;i<=26;i++)
  {
    if(can[x][y][i])
    {
      num=i;
      break;
    }
  }
  int until;
  for(int i=y;i<=m;i++)
  {
    if(i-y+x>n)
    {
      until=i-1;
      break;
    }
    bool flag=true;
    if(!Check(x,y,x+i-y,i))flag=false;
    for(int j=1;j<num;j++)
    {
      if(!flag)break;
      if(can[x][i][j])
      {
        flag=false;
        break;
      }
    }
    if(!flag)
    {
      until=i-1;
      break;
    }
    if(i==m)
    {
      until=m;
      break;
    }
  }
  //cout<<x<<" "<<y<<" "<<num<<" "<<until<<"\n";
  for(int i=x;i<=until-y+x;i++)
  {
    Update(i,1,1,m,y,until,num);
  }
  for(int i=y;i<=until;i++)
  {
    can[x+until-y+1][i][num]=false;
  }
  for(int i=x;i<=until-y+x;i++)
  {
    can[i][until+1][num]=false;
  }
}
int main()
{
freopen("chongjg.in","r",stdin);
freopen("chongjg.out","w",stdout);
cin>>n>>m;
for(int i=0;i<=n+1;i++)
{
  for(int j=0;j<=m+1;j++)
  {
    for(int k=0;k<=26;k++)
    {
      can[i][j][k]=true;
    }
  }
}
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    if(!Get(i,1,1,m,j,j))
    {
      Colour(i,j);
    }
    cout<<(char)(Get(i,1,1,m,j,j)+'A'-1);
  }
  cout<<"\n";
}
return 0;
}