//#pragma GCC optimize("Ofast")
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
int a[N],n,q,t[N],idx;
ifstream fin("triangle.in");
ofstream fout("triangle.out");
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    fin>>n>>q;
    for(int i=1;i<=n;i++){
    	fin>>a[i];
	}
	while(q--){
		int l,r;
		fin>>l>>r;
		if(r-l+1<3){
			fout<<"No"<<endl;
			continue;
		}
		idx=0;
		for(int i=l;i<=r;i++) t[++idx]=a[i];
		sort(t+1,t+1+idx);
		bool f=0;
		for(int i=1;i<=idx-2;i++){
			if(t[i]+t[i+1]>t[i+2]){
				f=1,fout<<"Yes"<<endl;
				break;
			}
		}
		if(!f) fout<<"No"<<endl;
	}
	return 0;
}

