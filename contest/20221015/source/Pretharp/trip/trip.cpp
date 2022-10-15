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
const int N=5010;
#define pid pair<int,double>
#define pdi pair<double,int>
int n,m,T[N],b[N*10],idx,X[N],sta,ed,L,R,st[N*10];
vector<pid> v[N*10];
double dist[N*10];
double Max(double xx,double yy)
{
	return (xx>yy?xx:yy);
}
double Dijkstra(int mn)
{
	for(int i=1;i<=idx;i++) dist[i]=2000000000.0;
	memset(st,0,sizeof st);
	dist[sta]=0,st[sta]=0;
	priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
	pq.push({dist[sta],sta});
	while(pq.size()){
		pdi t=pq.top();
		pq.pop();
		if(st[t.sec]) continue;
		st[t.sec]=1;
		for(pid x:v[t.sec]){
			if(x.sec<mn) continue;
			if(dist[x.fir]>Max(dist[t.sec],x.sec)){
				dist[x.fir]=Max(dist[t.sec],x.sec);
				pq.push({dist[x.fir],x.fir});
			}
		}
	}
	return dist[ed];
}
bool check(int x)
{
	double d=Dijkstra(x);
	if(d>1000000000.0) return 0;
	else return R=ceil(d),1;
}
signed main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,x,y,w;i<=m;i++){
    	cin>>x>>y>>w;
    	v[x].pb({y,w}),v[y].pb({x,w});
	}
	for(int i=1;i<=n;i++){
		cin>>T[i];
		for(int j=1,x;j<=T[i];j++){
			cin>>x,b[x]=i;
			idx++;
		}
	}
	for(int i=1;i<=n;i++) cin>>X[i];
	cin>>sta>>ed;
	for(int i=1;i<=idx;i++){
		for(pid &x:v[i]){
			if(b[i]==b[x.fir]) x.sec*=(1.0*X[b[i]]/100.0);
			else x.sec*=(1.0*(X[b[i]]/100.0+X[b[x.fir]]/100.0)/2);
		}
	}
	int l=1,r=15001;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) L=mid,l=mid+1;
		else r=mid-1;
	}
	return cout<<L<<" "<<R<<endl,0;
}

