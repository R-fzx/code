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
const int N=510;
char c[N][N];
int n,m,sta,ed,dist[N*N];
vector<pii> v[N];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
bool st[N*N];
void SPFA()
{
	memset(dist,0x3f,sizeof dist);
	dist[sta]=0,st[sta]=1;
	queue<int> q;
	q.push(sta);
	while(q.size()){
		int t=q.front();
		q.pop(),st[t]=0;
		for(pii i:v[t]){
			if(dist[i.fir]>dist[t]+i.sec){
				dist[i.fir]=dist[t]+i.sec;
				if(!st[i.fir]) q.push(i.fir),st[i.fir]=1;
			}
		}
	}
}
signed main()
{
    freopen("portal.in","r",stdin);
    freopen("portal.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>c[i][j];
    		if(c[i][j]=='C') sta=(i-1)*m+j;
    		if(c[i][j]=='F') ed=(i-1)*m+j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=m;j++){
			x=(i-1)*m+j;
			for(int k=1,xx,yy;k<=4;k++){
				xx=i+dx[k],yy=j+dy[k];
				if(xx>=1 && xx<=n && yy>=1 && yy<=m && c[xx][yy]!='#') v[x].pb({(xx-1)*m+yy,1});
			}
			int cnt[5]={},mn=INF2,xxx[5]={},yyy[5]={};
			for(int k=1,xx,yy,cntt;k<=4;k++){
				xx=i+dx[k],yy=j+dy[k],cntt=0;
				while(xx>=1 && xx<=n && yy>=1 && yy<=m && c[xx][yy]!='#') xx+=dx[k],yy+=dy[k],cntt++;
				cnt[k]=cntt,mn=min(mn,cntt);
				xx-=dx[k],yy-=dy[k];
				xxx[k]=xx,yyy[k]=yy;
			}
			for(int k=1;k<=4;k++){
				cnt[k]=min(cnt[k],mn+1);
				v[x].pb({(xxx[k]-1)*m+yyy[k],cnt[k]});
			}
		}
	}
	SPFA();
	if(dist[ed]>INF2/2) return cout<<"nemoguce"<<endl,0;
	else return cout<<dist[ed]<<endl,0;
}

