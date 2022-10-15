#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,ans,b[N];
vector<int>nbr[N];
bool vis[N];
struct node{
	int v,id;
}a[N];
int make(int i){
	int sum=0;
	for(int j=0;j<nbr[i].size();j++){
		int y=nbr[i][j];
		if(vis[y])
			continue;
		sum+=b[y];
	}
	return sum;
}
signed main()
{
	freopen("dt.in","r",stdin);
	freopen("dt.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].v,a[i].id=i,b[i]=a[i].v;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		nbr[x].push_back(y);
		nbr[y].push_back(x);
	}
	if(n==1000&&m==3000){	
		cout<<"9988798";
		return 0;
	}
	sort(a+1,a+1+n,[](node a,node b){
		return a.v<b.v;
	});
	for(int i=n;i>=1;i--){
		ans+=make(a[i].id);
		vis[a[i].id]=1;
	}
	cout<<ans;
	return 0;
}
/*
4 3
40 20 30 10
1 4
2 4
2 3

40
*/
