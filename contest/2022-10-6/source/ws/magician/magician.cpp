#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1000000009;

int n,m;
int f[200005];
int find(int x){
	if(f[x]==x)
		return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}	
}

signed main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		f[i]=i;
	
	for(int i=1,ans=1,x,y;i<=m;i++){
		cin>>x>>y;
		x=find(x),
		y=find(y);
		
		if(x!=y)
			f[x]=y;
		else
			ans=ans*2%mod;
		
		cout<<(ans-1+mod)%mod<<endl;
	}
	return 0;
}
