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
#define in_ long long
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
const int N=1010;
int n,ans,a[N],st[N],b[N];
pii p[N];
vector<int> v[N];
ifstream fin("graph.in");
ofstream fout("graph.out");
void check()
{
	memset(b,0,sizeof b);
	int cnt=0;
	for(int i=1,mx;i<=n;i++){
		b[a[i]]=1,mx=0;
		for(int x:v[a[i]]){
			if(b[x]) mx=max(mx,p[x].fir);
		}
		cnt+=mx;
	}
	ans=max(ans,cnt);
}
void dfs(int step)
{
	if(step==n+1){
		return check(),void();
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=1,a[step]=i;
		dfs(step+1);
		st[i]=0;
	}
}
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    fin>>n;
    for(int i=1;i<=n;i++){
    	fin>>p[i].fir,p[i].sec=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((p[i].fir&p[j].fir)==0) v[i].pb(j),v[j].pb(i);
		}
	}
	dfs(1);
	return fout<<ans<<endl,0;
}

