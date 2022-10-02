#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define int long long
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=505;
map<int,int>dp[N][N];
vector<int>v[N][N];
int a[N][N],l[N][N],r[N][N];
bool bj[10000005];
int n;
signed main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	n=read();for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)l[i][j]=read();for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==n&&j==n)break;
			int x,y;
			if(j==n)x=i+1,y=1;
			else x=i,y=j+1;
			if(!v[i][j].size()){
				for(int k=l[i][j];k<=r[i][j];k++)v[i][j].push_back(k),dp[i][j][k]=a[i][j]*k;
			}
			memset(bj,0,sizeof(bj));
			for(int k=0;k<v[i][j].size();k++){
				for(int p=l[x][y];p<=r[x][y];p++){
					dp[x][y][p+v[i][j][k]]=max(dp[x][y][p+v[i][j][k]],dp[i][j][v[i][j][k]]+p*a[x][y]);
					if(!bj[p+v[i][j][k]+5000000])v[x][y].push_back(p+v[i][j][k]),bj[p+v[i][j][k]+5000000]=1;
				}
			}
		}
	cout<<dp[n][n][0];
	return 0;
}
