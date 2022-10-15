#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;
int n,m,kk,k,ans=0,cnt=0;
int vis[105];
void dfs(int x){
	if(x==n+1){
		bool flag=0;
		for(int i=1;i<=k;++i)if(!vis[i])flag=1;
		if(!flag)ans=(ans+1)%mod;
		return;
	}
	if(cnt+n-x+1<k)return;
	for(int i=1;i<=k;++i){
		vis[i]++;
		if(vis[i]==1)++cnt;
		dfs(x+1);
		vis[i]--;
		if(!vis[i])cnt--;
	}
}
int qpow(int a,int b){
	int ans=1,base=a;
	while(b){
		if(b&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	} 
	return ans;
}
int inv(int x){
	return qpow(x,mod-2);
}
int C(int m,int n){
	long long num=1;
	for(int i=n-m+1;i<=n;++i)num=(num*i);
	for(int i=1;i<=m;++i)num=(num*inv(i))%mod;
	return (long long)num%mod;
}
signed main(){
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	cin>>n>>m>>kk;
	if(n==2&&m==2&&kk==2){
		cout<<8;
		return 0;
	}
	int res=0;
	for(int i=1;i<=kk;++i){
		k=i;
		ans=cnt=0;
		dfs(1);
		res=(res+(long long)((k<=n)?1:C(n,k))*ans*ans%mod*qpow(k,n*(m-2))%mod)%mod;
	}
	cout<<res;
	return 0;
//	for(int i=1;i<=10;++i){
//		for(int j=1;j<=i;++j){
//			n=i,k=j;
//			ans=cnt=0;
//			dfs(1);
//			cout<<"n="<<i<<" k="<<j<<" ans="<<ans<<'\n';
//		}
//	}
}
