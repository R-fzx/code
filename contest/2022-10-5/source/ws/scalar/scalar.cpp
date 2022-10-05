#include<bits/stdc++.h>
using namespace std;

int n,a[805],b[805];

int main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,greater<int>());
	
	long long ans=0;
	
	for(int i=1;i<=n;i++)
		ans+=1LL*a[i]*b[i];
	
	cout<<ans;
	return 0;
}
