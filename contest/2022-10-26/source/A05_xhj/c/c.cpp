#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF=1e6;
int A[INF],n;
int f(int x){
	int Ct=0,K=1;
	while(Ct++){
		if(K>x){
			Ct+=f(x-K/2);
			return Ct;
		}
		if(K==x){
			return Ct;
		}
		if(Ct==n){
			Ct+=f(x-K);
			return Ct;
		}
		K*=2;
	}
}signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n; int cnt=0;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>A[i];
		cnt=max(A[i],cnt);
	}int Ans=0; for(int i=1;i<=n;i++){
		Ans+=f(cnt-A[i]);
	} cout<<Ans<<endl;
return 0;
}
