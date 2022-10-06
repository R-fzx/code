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
//#define double long double 
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=2e2+100;
double dp[N][N],f[N][N][N];
double p1[N],p2[N],p[N];
int n,a[N],cnt1,cnt2;
int l,K;
double ans;
int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read(),l=read(),K=read();
	for(int i=1;i<=n;i++)scanf("%lf",p+i),p[i]=1.0*p[i]/100;
	for(int i=1;i<=n;i++){
		int x=read();
		if(x==-1)p1[++cnt1]=p[i];
		else p2[++cnt2]=p[i],a[cnt2]=x;
	}
	dp[0][0]=f[0][0][0]=1;
	for(int i=1;i<=cnt1;i++){
		dp[i][0]=dp[i-1][0]*(1-p1[i]);
		for(int j=1;j<=i;j++)
		dp[i][j]=dp[i-1][j-1]*p1[i]+dp[i-1][j]*(1-p1[i]);
	}
	for(int i=1;i<=cnt2;i++){
		f[i][0][0]=f[i-1][0][0]*(1-p2[i]);
		for(int j=i;j>=1;j--){
			for(int k=a[i];k<=n;k++){
				f[i][j][k]=f[i-1][j-1][k-a[i]]*p2[i]+f[i-1][j][k]*(1-p2[i]);
			}
		}
	}
	for(int i=0;i<=cnt2;i++)
	for(int j=n;j>=0;j--)
	f[cnt2][i][j]+=f[cnt2][i][j+1];
	for(int i=l;i<=n;i++){
		for(int j=0;j<=i;j++){
			int fp=i-j;
			ans+=dp[cnt1][j]*f[cnt2][fp][max(0,j-K)];
		}
	}
	printf("%0.6lf",ans);
	return 0;
}
