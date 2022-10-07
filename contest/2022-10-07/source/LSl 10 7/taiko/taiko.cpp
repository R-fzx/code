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
const int N=4e3+100;
int a[N],ans[N];
int k,n;
bool f,bj[N];
bool check(int x){
	memset(bj,0,sizeof(bj));
	for(int i=1;i<=x-k+1;i++){
		int sum=0;
		for(int j=i;j<=i+k-1;j++)sum=sum*2+a[j];
		if(bj[sum])return 0;
		bj[sum]=1;
	}
	return 1;
}
bool ok(){
	memset(bj,0,sizeof(bj));
	for(int i=1;i<=n-k+1;i++){
		int sum=0;
		for(int j=i;j<=i+k-1;j++)sum=sum*2+a[j];
		if(bj[sum])return 0;
		bj[sum]=1;
	}
	for(int i=n-k+2;i<=n;i++){
		int sum=0;
		for(int j=i,l=1;l<=k;j=j%n+1,l++)sum=sum*2+a[j];
		if(bj[sum])return 0;
		bj[sum]=1;
	}
	return 1;
}
void dfs(int x){
	if(x>n){
		if(ok()){
			for(int i=1;i<=n;i++)
			ans[i]=a[i];
			f=1;
		}
		return;
	}
	if(f)return;
	for(int i=0;i<=1;i++){
		a[x]=i;
		if(x<=k||check(x))dfs(x+1);
		a[x]=0;
		if(f)return;
	}
}
int main(){
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	k=read();n=1<<k;
	dfs(1);
	printf("%d ",n);
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	return 0;
} 
