#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int a[1000005],b[1000005];
int main(){
	freopen("section.in","r",stdin);
	freopen("section.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n,m,q,ans=0;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		if(x==1){
			int t=y+m-1;
			while(y<t){
				swap(a[y],a[t]);
				y++,t--;
			}
		}else{
			ans^=a[y];
		}
	}
	cout<<ans;
	return 0;
}
