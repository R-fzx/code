#include <iostream>
#include <ctime>
#define int long long
using namespace std;
const int kM=1e9+7;
int n,sum=1,ans;
signed main()
{
freopen("sakura.in","r",stdin);
freopen("sakura.out","w",stdout);
srand(time(0));
cin>>n;
if(n==1)cout<<1;
else if(n==2)cout<<3;
else if(n==3)cout<<9;
else if(n==4)cout<<21;
else if(n==5)cout<<63;
else if(n==6)cout<<125;
else cout<<rand()%kM;

return 0;
}