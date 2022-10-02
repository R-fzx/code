#include<bits/stdc++.h>
using namespace std;
int n,a[505][505],l[505][505],r[505][505];
int main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	cin>>n;
	memset(r,0x3f,sizeof r);
	for(int i=1,x;i<=n;i++)for(int j=1;j<=n;j++){
		cin>>x;
		if(i>=j)a[i][j]+=x;
		else a[j][i]+=x;
	}
	for(int i=1,x;i<=n;i++)for(int j=1;j<=n;j++){
		cin>>x;
		if(i>=j)l[i][j]=max(l[i][j],x);
		else l[j][i]=max(l[j][i],x);
	}
	for(int i=1,x;i<=n;i++)for(int j=1;j<=n;j++){
		cin>>x;
		if(i>=j)r[i][j]=min(r[i][j],x);
		else r[j][i]=min(r[j][i],x);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
	return 0;
}
