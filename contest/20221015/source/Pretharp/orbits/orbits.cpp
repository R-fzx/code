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
const int N=114,mod=10007;
int n,m,k,a[N],ans,tt;
void work()
{
	int sum=1;
	for(int i=1;i<=n;i++) sum*=a[i];
	if(sum%k || sum<k) return;
	sum/=k;
	if(__gcd(sum,k)==1) (ans+=1)%=mod;
}
void dfs(int step)
{
	if(step==n+1) return work(),void();
	for(int i=1;i<=m;i++){
		a[step]=i;
		dfs(step+1);
	}
}
signed main()
{
    freopen("orbits.in","r",stdin);
    freopen("orbits.out","w",stdout);
    cin>>n>>m>>k;
    dfs(1);
	return cout<<ans<<endl,0;
}

