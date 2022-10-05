#include<bits/stdc++.h>
using namespace std;
const int maxn=805;
int n;
long long a[maxn],b[maxn];
long long ans;
int main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	 for(int i=1;i<=n;i++)
	 	ans+=a[i]*b[n-i+1];
	printf("%lld\n",ans);
	return 0; 
}
