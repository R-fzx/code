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
const int N=1e5+5;
int n,m,q,a[N],ans;
ifstream fin("section.in");
ofstream fout("section.out");
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    fin>>n>>m>>q;
    for(int i=1;i<=n;i++) fin>>a[i];
    while(q--){
    	int o,l;
    	fin>>o>>l;
    	if(o==1){
    		int r=l+m-1;
    		while(l<r){
    			swap(a[l],a[r]);
    			l++,r--;
			}
		}else{
			ans^=a[l];
		}
	}
	return fout<<ans<<endl,0;
}

