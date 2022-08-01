#include<bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int>b[209];
double p,alive[209][1009],ans[209];
string s,a[209];
inline int kmp(string a,string b){
	int ans(0);
	for(int i(0);i<a.size();i++){
		int cnt(0);
		while(cnt<b.size()){
			if(a[i+cnt]!=b[cnt])break;cnt++;
		}
		ans+=(cnt==b.size());
	}
	return ans;
}
//alive[i][k]=alive[i][k-1]*p+(1-p)*alive[i-1][k]
int main(){
	freopen("ppfish.in","r",stdin),freopen("ppfish.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i(1);i<=n;i++)cin>>a[i];
	cin>>s;
	for(int i(1);i<=n;i++)b[i].first=kmp(s,a[i]),b[i].second=i;
	sort(b+1,b+n+1);
	cin>>p>>k;
	int w(b[1].first),o(1);
	for(int i(1);i<=n;i++){
		if(w!=b[i].first)w=b[i].first,o++;
		b[i].first=o;
	}
	for(int i(1);i<=o;i++)alive[i][0]=1;
	for(int j(1);j<=k;j++){
		for(int i(1);i<=o;i++){
			alive[i][j]=alive[i][j-1]*p+(1-p)*alive[i-1][j-1];
		}
	}
	for(int i(1);i<=n;i++)ans[b[i].second]=alive[b[i].first][k];
	for(int i(1);i<=n;i++)printf("%0.3f ",ans[i]);
	return 0;
}

