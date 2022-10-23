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
int n,f,ans;
struct S{
	int xa,ya,za,xb,yb,zb;
}a[N];
ifstream fin("cube.in");
ofstream fout("cube.out");
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    fin>>n;
    for(int i=1;i<=n;i++){
    	fin>>a[i].xa>>a[i].ya>>a[i].za>>a[i].xb>>a[i].yb>>a[i].zb;
    	if(a[i].za || a[i].zb) f=1;
	}
	if(f){
		for(int i=-50;i<=50;i++){
			for(int j=-50;j<=50;j++){
				for(int k=-50;k<=50;k++){
					int cnt=0;
					for(int l=1;l<=n;l++){
						if(i>=a[l].xa && i<=a[l].xb && j>=a[l].ya && j<=a[l].yb && k>=a[l].za && k<=a[l].zb) cnt++;
					}
					if(cnt>=n-1) ans++;
				}
			}
		}
	}
	return fout<<ans<<endl,0;
}

