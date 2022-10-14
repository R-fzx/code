#include<bits/stdc++.h>
using namespace std;
int m,n,ans[25];
long long cnt,c;
bool vis[25];
bool flg;
void dfs(int pos){
	if(pos>=4&&(ans[pos-1]>ans[pos-2]&&ans[pos-2]>ans[pos-3]||ans[pos-1]<ans[pos-2]&&ans[pos-2]<ans[pos-3]))return;
	if(pos==n+1){
		++cnt;
//		cout<<cnt<<'\n';
//		cout<<"Test: "<<cnt<<"  ans: ";
//		for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
//			cout<<'\n';
		if(cnt==c){
//	cout<<pos<<'\n';
			flg=1;
			for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
			cout<<'\n';
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			ans[pos]=i;
			vis[i]=1;
			dfs(pos+1);
			if(flg==1)return;
			vis[i]=0;
			ans[pos]=0;
		}
	}
}
int main(){
	cin>>m;
	while(m--){
		memset(vis,0,sizeof(vis));
		cin>>n>>c;
		flg=0;
		cnt=0;
		dfs(1);
		cout<<cnt<<'\n';
//		for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
//		cout<<'\n';
	}
	return 0;
}

