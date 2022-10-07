#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b,k;

int gcd(int x,int y){
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

int cnt,pri[30],t[30];

int qp(int x,int y,int mod){
	int ans=1;
	
	while(y){
		if(y&1)
			ans=ans*x%mod;
		
		x=x*x%mod;
		y>>=1;
	}
	
	return ans;
}

int ans;

void dfs(int step,int sum){
	if(sum>=ans)
		return;
	
	if(step==cnt+1){
		if(qp(k,sum,b)==1)
			ans=min(ans,sum);
		return;
	}
	
	dfs(step+1,sum);
	
	for(int i=1;i<=t[step];i++){
		sum*=pri[step];
		dfs(step+1,sum);
	}
}

signed main(){
	freopen("kubi.in","r",stdin);
	freopen("kubi.out","w",stdout); 
	
	int T;
	cin>>T;
	while(T--){
		cin>>a>>b>>k;
		
		int tmp=gcd(a,b);
		a/=tmp,
		b/=tmp;
		
		cnt=0;
		int kk=k;
		
		for(int i=2;i*i<=k;i++){
			if(k%i==0){
				cnt++;
				pri[cnt]=i;
				
				while(k%i==0){
					k/=i;
				}
			}
		}
		
		if(k!=1){
			cnt++;
			pri[cnt]=k;
		}
		
		k=kk;
		
		int maxn=0,now=0;
		
		for(int i=1;i<=cnt;i++){
			if(b%pri[i]==0){
				now=0;
				
				while(b%pri[i]==0){
					now++;
					b/=pri[i];
				}
				
				maxn=max(maxn,now);
			}
		}
		
		cout<<maxn<<' ';
		
		b--;
		
		kk=b;
		cnt=0;
		
		for(int i=2;i*i<=b;i++){
			if(b%i==0){
				cnt++;
				pri[cnt]=i;
				t[cnt]=0;
				
				while(b%i==0){
					b/=i;
					t[cnt]++;
				}
			}
		}
		
		if(b!=1){
			cnt++;
			pri[cnt]=b;
			t[cnt]=1;
		}
		
		b=kk+1;
		
		ans=b-1;
		
		dfs(1,1);
		
		cout<<ans<<endl;
	}
	return 0;
}
