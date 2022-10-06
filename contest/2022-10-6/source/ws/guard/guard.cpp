#include<bits/stdc++.h>
using namespace std;

int n,l,k;
double p[205];
double dp[205][205][405];

int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	
	cin>>n>>l>>k;
	
	if(k>n)
		k=n;
	
	for(int i=1;i<=n;i++){
		cin>>p[i];
		p[i]/=100;
	}
	
	dp[0][0][n+k]=1;
	
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=0;j<i;j++)
			for(int o=0;o<=n+n;o++){
				if(o+x>=0)
					dp[i][j+1][min(o+x,n+n)]+=dp[i-1][j][o]*p[i];
				dp[i][j][o]+=dp[i-1][j][o]*(1-p[i]);
			}
	}
	
	double ans=0;
	
	for(int i=l;i<=n;i++)
		for(int j=n;j<=n+n;j++)
			ans+=dp[n][i][j];
	
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
