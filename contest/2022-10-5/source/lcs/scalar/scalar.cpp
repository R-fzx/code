#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,a[805],b[805];
int ans;
signed main(){
	freopen("scalar.in","r",stdin) ;
	freopen("scalar.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int j=1;j<=n;++j){
		scanf("%lld",&b[j]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)ans+=a[i]*b[n-i+1];
	printf("%lld",ans);
	return 0;
}
