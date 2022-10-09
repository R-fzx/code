#include<bits/stdc++.h>
using namespace std;

int n,x[2][205];

int dp[80005];

int main(){
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[0][i]>>x[1][i];
	
	int ans=0,sum=0,sum2=0;
	
	for(int o=0;o<2;o++){
		memset(dp,0,sizeof dp);
		dp[0]=1;
		sum=sum2=0;
		
		for(int i=1;i<=n;i++){
			sum2+=x[o][i]*x[o][i];
			sum+=x[o][i];
			
			for(int j=80000;j>=2*x[o][i];j--)
				dp[j]|=dp[j-2*x[o][i]];
		}
		
		for(int i=0;i<=sum;i++)
			if(dp[sum-i] || dp[sum+i]){
				ans+=(i*i-sum2)/2;
				break;
			}
	}
	cout<<ans<<".00";
	return 0;
}
