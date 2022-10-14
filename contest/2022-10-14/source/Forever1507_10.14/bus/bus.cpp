#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005]; 
signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=0;
	int pos=1;
	while(pos<=n){
//		cout<<"Test: "<<pos<<'\n';
		int to=pos;
		while(a[pos]<=a[to]){
			ans+=a[pos];
			to++;
		}
		pos=to;
	}
	cout<<ans;
	return 0;
}

