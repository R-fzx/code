#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,k,maxi,maxx,c[N],t[N];
void dfs(int cur,int num,int ans)
{
	maxx=max(maxx,ans);
	if(cur>=maxi){
		return ;
	}
	if(num>n||num<1){
		return ;
	}
	if(t[num]>=cur){
		int tmp=c[num];
		c[num]=0;
		dfs(cur+1,num+1,ans+c[num]);
		dfs(cur+1,num-1,ans+c[num]);
		c[num]=tmp;
	}
	else{
		dfs(cur+1,num+1,ans);
		dfs(cur+1,num-1,ans);
	}
}
int main()
{
	freopen("go.in","r",stdin);
	freopen("go.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++){
		int a,b,tt;
		cin>>a>>b>>tt;
		c[a]=b;
		t[a]=tt; 
		maxi=max(maxi,tt);
	}
	dfs(0,k,0);
	cout<<maxx;
}
