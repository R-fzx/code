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
const int N=110,M=2010;
int n,k,m,f[2][N][N][M],mxt,ans;
struct S{
	int x,w,ti,id;
}a[N];
bool cmp(const S &x,const S &y)
{
	return x.x<y.x;
}
void mxs(int &x,int y)
{
	x=max(x,y);
}
signed main()
{
	freopen("go.in","r",stdin);
	freopen("go.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].w>>a[i].ti;
		a[i].id=i;
		mxt=max(mxt,a[i].ti);
	}
	sort(a+1,a+1+m,cmp);
	int tl=1,tr=m;
	memset(f,-0x3f,sizeof f);
	for(int i=0;i<=m;i++){
		for(int j=abs(k-a[i].x)+1;j<=mxt;j++){
			f[0][i][i][j]=0;
			f[1][i][i][j]=0;
		}
	}
	for(int i=m;i>=1;i--){
		if(a[i].x<=k && abs(k-a[i].x)+1<=a[i].ti){
			tl=i;break; 
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].x>k && abs(k-a[i].x)+1<=a[i].ti){
			tr=i;break;
		}
	}
	for(int i=1;i<=m;i++){
		if(abs(k-a[i].x)+1<=a[i].ti){
			for(int j=abs(k-a[i].x)+1;j<=mxt;j++){
				f[0][i][i][j]=a[i].w;
				f[1][i][i][j]=a[i].w;
			}
		}
	}
	for(int len=2;len<=m;len++){
		for(int i=1,j;(j=i+len-1)<=m;i++){
			for(int kk=0,t;kk<=mxt;kk++){
				t=a[j].x-a[j-1].x;
				if(t<kk && kk>a[j].ti){
					mxs(f[0][i][j][kk],f[0][i][j-1][kk-t]);
				}
				if(t<kk && kk<=a[j].ti){
					mxs(f[0][i][j][kk],f[0][i][j-1][kk-t]+a[j].w);
				}
				t=a[j].x-a[i].x;
				if(t<kk && kk>a[j].ti){
					mxs(f[0][i][j][kk],f[1][i][j-1][kk-t]);
				}
				if(t<kk && kk<=a[j].ti){
					mxs(f[0][i][j][kk],f[1][i][j-1][kk-t]+a[j].w);
				}
				t=a[i+1].x-a[i].x;
				if(t<kk && kk>a[i].ti){
					mxs(f[1][i][j][kk],f[1][i+1][j][kk-t]);
				}
				if(t<kk && kk<=a[i].ti){
					mxs(f[1][i][j][kk],f[1][i+1][j][kk-t]+a[i].w);
				}
				t=a[j].x-a[i].x;
				if(t<kk && kk>a[i].ti){
					mxs(f[1][i][j][kk],f[0][i+1][j][kk-t]);
				}
				if(t<kk && kk<=a[i].ti){
					mxs(f[1][i][j][kk],f[0][i+1][j][kk-t]+a[i].w);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int kk=0;kk<=mxt;kk++){
			ans=max({ans,f[0][i][i][kk],f[1][i][i][kk]});
		}
		for(int j=i+1;j<=m;j++){
			for(int kk=0;kk<=mxt;kk++){
				ans=max({ans,f[0][i][j][kk],f[1][i][j][kk]});
			}
		}
	}
	return cout<<ans<<endl,0;
}

