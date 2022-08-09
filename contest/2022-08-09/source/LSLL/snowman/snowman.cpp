#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int a[N],ans;
int n;
signed main(){
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int l1=1;l1<n;l1++){
		for(int l2=l1+1;l2<=n;l2++){
			int len=1;
			int s=a[l1]-a[l2];
			bool f=1;
			for(;len<=n-l2;len++){
				if(a[l1+len]-a[l2+len]!=s){
					f=0;
					break;
				}
			}
			if(!f)continue;
			ans=max(ans,min(l2-l1,len));
		}
	}
	printf("%lld",ans);
	return 0;
}
