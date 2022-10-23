#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int a[100005],b[100005];
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		int l,r;
		cin>>l>>r;
		int t=r-l;
		for(int i=0;i<=t;i++){
			b[i]=a[l+i];
		}
		sort(b+0,b+t+1);
		bool f=0;
		for(int i=0;i<=t-2;i++){
			if(b[i]+b[i+1]>b[i+2]){
				f=1;
				//cout<<b[i]<<b[i+1]<<b[i+2];
				break;
			}
		}
		if(f==1){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
		cout<<'\n';
	}
	return 0;
}
