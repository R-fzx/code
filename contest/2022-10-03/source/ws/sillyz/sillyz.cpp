#include<bits/stdc++.h>
#define int long long
using namespace std;

int l,r,ans;

signed main(){
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	
	cin>>l>>r;
	
	for(int i=1;i<=r;i++){
		int x=i,t=1;
		while(x){
			t*=x%10;
			x/=10;
		}
		if(i*t>=l && i*t<=r)
			ans++;
	}
	cout<<ans;
	return 0;
}
