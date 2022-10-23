#include<bits/stdc++.h>
using namespace std;
const int N=1010,INF=1e9;
int n,ans,maxn,tot,maxi;
int a[N];
bool vis[N];
vector<int> tr[N];
void dfs(int cnt,int num){
//	tot++;
//	cout<<cnt<<" "<<num<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<vis[i]<<" ";
//	}
//	cout<<endl;
	if(maxn*(n-cnt)+num<=ans){
		return;
	}
	if(cnt>=n){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int x=0;
			for(int j=0;j<tr[i].size();j++){
				int y=tr[i][j];
				if(vis[y]){
					x=max(x,a[y]);
				}
			}
			vis[i]=true;
			dfs(cnt+1,num+x);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(maxn<a[i]) maxi=i;
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])==0){
//				cout<<i<<"--"<<j<<endl;
				tr[i].push_back(j);
				tr[j].push_back(i);
			}
		}
	}
	vis[maxi]=true;
	dfs(1,0);
//	dfs(0,0);
//	cout<<tot<<endl;
	cout<<ans;



	return 0;
}

