#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int t,n,q;
struct node{
	int x,y;
}s[N];
signed main()
{
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y;
		}
		while(q--){
			int a,b;
			cin>>a>>b;
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=max(abs(a-s[i].x),abs(b-s[i].y));
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}

