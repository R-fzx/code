#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,A,B,C,D,X0,Y0,M;

int t[5][5],ans;

signed main(){
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	
	cin>>n>>A>>B>>C>>D>>X0>>Y0>>M;
	
	t[X0%3][Y0%3]++;
	
	for(int i=2;i<=n;i++){
		X0=(A*X0%M+B)%M;
		Y0=(C*Y0%M+D)%M;
		
		t[X0%3][Y0%3]++;
	}
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans+=t[i][j]*(t[i][j]-1)*(t[i][j]-2);
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++){
					if(i==k && j==l)continue;
					
					ans+=t[i][j]*t[k][l]*t[(9-i-k)%3][(9-j-l)%3];
				}
	
	ans/=6;
	cout<<ans;
	return 0;
}
