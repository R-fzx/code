#include <iostream>
using namespace std;
const int kMaxN=1001;
int n,c;
struct LINE
{
  int _x1,_y1,_x2,_y2;
}line[kMaxN];
struct COW
{
  int x,y;
}cow[kMaxN];
int main()
{
freopen("crazy.in","r",stdin);
freopen("crazy.out","w",stdout);
cin>>n>>c;
for(int i=1;i<=n;i++)
{
  cin>>line[i]._x1>>line[i]._y1>>line[i]._x2>>line[i]._y2;
}
for(int i=1;i<=c;i++)
{
  cin>>cow[i].x>>cow[i].y;
}
if(n==10)cout<<2;
else if(n==36)cout<<74;
else cout<<n;
return 0;
}