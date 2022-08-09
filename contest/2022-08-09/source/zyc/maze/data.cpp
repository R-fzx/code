#include <iostream>
#include <ctime>
#define int long long
using namespace std;
const int kMaxN=20;
int n=kMaxN,m=kMaxN;
int mp[21][21];
int can[100000000],cnt;
void Dfs(int x,int y,int z)
{
  if(clock()*1.0/CLOCKS_PER_SEC>10)return;
  if(x==n&&y==m)
  {
    can[++cnt]=z;
    return;
  }
  if(x+1<=n)Dfs(x+1,y,z^mp[x+1][y]);
  if(y+1<=m)Dfs(x,y+1,z^mp[x][y+1]);
}
signed main()
{
srand(time(0));
//freopen("maze.in","w",stdout);
cout<<kMaxN<<" "<<kMaxN<<" ";
for(int i=1;i<=kMaxN;i++)
{
  for(int j=1;j<=kMaxN;j++)
  {
    mp[i][j]=1ll*rand()*rand()%101;
  }
}
Dfs(1,1,mp[1][1]);
cout<<can[1ll*rand()*rand()%cnt+1]<<"\n";
for(int i=1;i<=kMaxN;i++)
{
  for(int j=1;j<=kMaxN;j++)
  {
    cout<<mp[i][j]<<" ";
  }
  cout<<"\n";
}
return 0;
}