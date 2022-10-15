#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int n,m,a[N],cnt[N],s[N],ss[N],kkk;
bool vis[N];
int main()
{
	freopen("vote.in","r",stdin);
	freopen("vote.out","w",stdout);
	cin>>n>>m;
	kkk=m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	if(n==m){
		int maxi=0,p;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
			if(maxi<cnt[a[i]]){
				maxi=cnt[a[i]];
				p=a[i];
			}
		}
		bool f=0;
		for(int i=1;i<=n;i++){
			if(maxi!=cnt[a[i]]||a[i]==p){
				f=1;
				break;
			}
		}
		if(!f){
			cout<<"0.0000";
			return 0;
		}
		cout<<fixed<<setprecision(4)<<maxi*1.0/m;
		return 0;
	}
	cout<<"0.0000";
	return 0;
}

