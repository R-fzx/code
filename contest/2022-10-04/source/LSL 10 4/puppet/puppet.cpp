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
const int N=55;
int g[N][N],dp[N];
int a[N];
int n;
int main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		memset(g,0,sizeof(g));memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int len=j-i+1;
				bool fl=0;
				for(int k=1;k<=n;k++){
					int l=i,r=i+k;
					for(;r<=j;l++,r++)if(abs(a[r]-a[l])>1)fl=1;
					if(abs(a[l]-a[i+k-1])<=1)fl=1;
					if(fl){
						g[i][j]=k-1;
						break;
					}
				}
				if(!fl)g[i][j]=j-i+1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<i;j++){
				dp[i]=max(dp[i],dp[j]+g[j+1][i]);
			}
		printf("%d\n",dp[n]);
	}
	return 0;
}
