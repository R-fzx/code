#include <iostream>
using namespace std;
const int kMaxN=51;
long long dp[kMaxN][2][2][2];
string n;
int num[kMaxN],len;
int main()
{
freopen("perm.in","r",stdin);
freopen("perm.out","w",stdout);
cin>>n;
len=n.length();
for(int i=0;i<len;i++)
{
  num[i+1]=n[i]-'0';
}
for(int i=1;i<=len;i++)
{
  if(i==1)
  {
    dp[i][0][0][0]=1;
    if(num[i]>2)
    {
      dp[i][1][0][0]=1;
      dp[i][0][1][0]=1;
    }
    else if(num[i]==2)
    {
      dp[i][1][0][0]=1;
      dp[i][0][1][1]=1;
    }
    else if(num[i]==1)
    {
      dp[i][1][0][1]=1;
    }
    //cout<<i<<" "<<dp[i][1][1][0]<<" "<<dp[i][0][1][0]<<" "<<dp[i][1][0][0]<<"\n";
    continue;
  }
  dp[i][0][0][0]=1;
  if(num[i]>2)
  {
    dp[i][1][0][0]=dp[i-1][1][0][0]+dp[i-1][1][0][1]+dp[i-1][0][0][0];
    dp[i][0][1][0]=dp[i-1][0][1][0]+dp[i-1][0][1][1]+dp[i-1][0][0][0];
    dp[i][1][1][0]=dp[i-1][0][1][0]+dp[i-1][0][1][1]+dp[i-1][1][0][0]+dp[i-1][1][0][1]+dp[i-1][1][1][0]+dp[i-1][1][1][1];
  }
  else if(num[i]==2)
  {
    dp[i][1][0][0]=dp[i-1][1][0][0]+dp[i-1][1][0][1]+dp[i-1][0][0][0];
    dp[i][0][1][0]=dp[i-1][0][1][0]+dp[i-1][0][1][1]+dp[i-1][0][0][0];
    dp[i][1][1][0]=dp[i-1][0][1][0]+dp[i-1][0][1][1]+dp[i-1][1][0][0]+dp[i-1][1][1][0]+dp[i-1][1][1][1];
    dp[i][1][1][1]=dp[i-1][1][0][1];
  }
  else if(num[i]==1)
  {
    dp[i][1][0][0]=dp[i-1][1][0][0]+dp[i-1][1][0][1]+dp[i-1][0][0][0];
    dp[i][0][1][0]=dp[i-1][0][1][0]+dp[i-1][0][1][1]+dp[i-1][0][0][0];
    dp[i][1][1][0]=dp[i-1][1][1][0]+dp[i-1][1][1][1]+dp[i-1][1][0][0]+dp[i-1][0][1][0];
    dp[i][1][1][1]=dp[i-1][0][1][1];
  }
  else
  {
    dp[i][1][0][0]=dp[i-1][1][0][0]+dp[i-1][0][0][0];
    dp[i][1][0][1]=dp[i-1][1][0][1];
    dp[i][0][1][0]=dp[i-1][0][1][0]+dp[i-1][0][0][0];
    dp[i][0][1][1]=dp[i-1][0][1][1];
    dp[i][1][1][0]=dp[i-1][1][1][0]+dp[i-1][1][0][0]+dp[i-1][0][1][0];
    dp[i][1][1][1]=dp[i-1][1][1][1];
  }
  //cout<<i<<" "<<dp[i][1][1][0]<<" "<<dp[i][0][1][0]<<" "<<dp[i][1][0][0]<<"\n";
}
cout<<dp[len][1][1][0];
return 0;
}