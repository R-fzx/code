#include<bits/stdc++.h>
using namespace std;
int n,mini=1e9;
map<string,int>dp;
string s[25],ans;
bool vis[25];
void dfs(int pos,string _s,int cnt){
	if(pos==n+1)return;
	if(cnt>=mini)return;
//	dp[_s]++;
	if(dp[_s]>=2){
		if(mini>=cnt){
			mini=cnt;
//			cout<<"Test: "<<_s<<'\n';
			if(ans==""||ans.size()>_s.size())ans=_s;
			else ans=min(ans,_s);
		}
//		mini=min(mini,cnt);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			dp[_s+s[i]]+=dp[_s];
			dfs(pos+1,_s+s[i],cnt+s[i].size());
			vis[i]=0;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	dp[""]=1;
	dfs(1,"",0);
	cout<<mini<<'\n'<<ans;
	return 0;
}

