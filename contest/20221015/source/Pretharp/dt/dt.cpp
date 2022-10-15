#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//#include<vector>
//#include<queue>
//#include<map>
//#include<set>
#define ll long long
#define int long long
#define db long double
#define endl '\n'
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
using namespace std;
const int INF2=0x3f3f3f3f;
const int mod1=998244353;
const int mod2=1e9+7;
const ll INF1=1e18;
const int N=1e5+5;
int n,m,d[N],sum[N],ans;
vector<int> v[N];
bool st[N];
pii w[N];
bool cmp(const pii &x,const pii &y)
{
	return x.fir>y.fir;
}
signed main()
{
    freopen("dt.in","r",stdin);
    freopen("dt.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i].fir,w[i].sec=i;
    for(int i=1,x,y;i<=m;i++){
    	cin>>x>>y;
    	v[x].pb(y),v[y].pb(x);
    	d[x]++,d[y]++,sum[x]+=w[y].fir,sum[y]+=w[x].fir;
	}
	sort(w+1,w+1+n,cmp);
	for(int i=1;i<=n;i++){
		st[w[i].sec]=1;
		ans+=sum[w[i].sec],sum[w[i].sec]=0;
		//cout<<ans<<endl;
		for(int x:v[w[i].sec]){
			sum[x]=max(sum[x]-w[i].fir,0);
		}
	}
	return cout<<ans<<endl,0;
}

