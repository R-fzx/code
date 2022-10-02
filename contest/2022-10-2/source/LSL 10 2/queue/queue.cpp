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
const int N=305,mod=1e9+7;
int a[N];
int st[N],top;
double ans;
int n,jj=1;
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	n=read();for(int i=1;i<=n;i++)a[i]=read(),jj*=i,jj%=mod;a[0]=0x3f3f3f3f;
	if(n<=10){
		do{
			top=0;
			for(int i=n;i>=0;i--){
				ans+=top;
				while(top&&a[i]>st[top])top--;
				st[++top]=a[i];
			}
		}while(next_permutation(a+1,a+1+n));
		printf("%0.2lf",(double)(1.0*ans/jj));
		return 0;
	}
	else {
		int cas=0;
		srand(time(0));
		while(clock()<950){
			cas++;
			top=0;random_shuffle(a+1,a+1+n);
			for(int i=n;i>=0;i--){
				ans+=double(top);
				while(top&&a[i]>st[top])top--;
				st[++top]=a[i];
			}
		}
		printf("%0.2lf",(double)(1.0*ans/cas));
	}
	return 0;
}
/*
int sum=0;
			for(int i=n;i>=1;i--){
				int jl=0;
				for(int j=i-1;j>=0;j--)
				if(a[j]>=a[i]){jl=i-j;break;}
				sum+=jl;
			}
			ans+=sum;
*/
