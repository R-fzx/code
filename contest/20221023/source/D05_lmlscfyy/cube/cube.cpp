#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int dt[105][105][105],n;
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int t=1;t<=n;t++){
		int x,y,z,Q,W,E;
		cin>>Q>>W>>E>>x>>y>>z;
		for(int i=Q;i<=x;i++){
			for(int j=W;j<=y;j++){
				for(int k=E;k<=z;k++){
					dt[i+50][j+50][k+50]++;
					//cout<<i<<' '<<j<<' '<<k<<'\n';
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=100;i++){
			for(int j=0;j<=100;j++){
				for(int k=0;k<=100;k++){
					if(dt[i][j][k]>=n-1) ans++;
				}
			}
		}
		cout<<ans;
	return 0;
}
