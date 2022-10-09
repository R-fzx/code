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
//#define int long long
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=205;
int x[N][4],y[N][4];
pair<int,int>dp[N][4],d[N][N];
int g[N][N],c[N][N];
int n;
void bb(int w,int f){
	int a=x[w][f],b=y[w][f];
	memset(g,0x3f,sizeof(g));
	memset(d,0,sizeof(d));
	g[0][0]=0;
	for(int i=1;i<w;i++){
		for(int j=w-1;j>=1;j--){
			int aa;
			for(int k=0;k<4;k++){
				if(g[i][j]>g[i-1][j-1]+c[i][k]){
					g[i][j]=g[i-1][j-1]+c[i][k];
					aa=k;
				}
			}
			d[i][j].first+=x[i][aa],d[i][j].second+=y[i][aa];
		}
	}
	dp[w][f].first=d[w-1][f].first,dp[w][f].second=d[w-1][f].second;
	c[w][f]=g[w-1][w-1]+a*dp[w-1][f].first+b*dp[w-1][f].second;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x[i][0]=read(),y[i][0]=read();
		x[i][1]=-x[i][0],y[i][1]=y[i][0];
		x[i][2]=-x[i][0],y[i][2]=-y[i][0];
		x[i][3]=x[i][0],y[i][3]=y[i][0];
	}
	dp[1][0].first=x[1][0],dp[1][0].second=y[1][0];
	dp[1][1].first=x[1][1],dp[1][1].second=y[1][1];
	dp[1][2].first=x[1][2],dp[1][2].second=y[1][2];
	dp[1][3].first=x[1][3],dp[1][3].second=y[1][3];
	c[1][0]=c[1][1]=c[1][2]=c[1][3]=0;
	for(int i=1;i<=n;i++){
		bb(i,0);bb(i,1);bb(i,2);bb(i,3);
	}
	cout<<min(min(c[n][0],c[n][1]),min(c[n][2],c[n][3]));
	return 9;
}
