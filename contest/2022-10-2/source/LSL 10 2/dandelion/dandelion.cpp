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
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=4e4+100;
int a[N];
int sum[N];
int ys[N];
struct dl{
	int id,a;
}d[N];
bool cmp(dl x,dl y){
	return x.a<y.a;
}
int n,m,ans,cnt;
int work(int l,int r){
	memset(sum,0,sizeof(sum));
	int mx=-1,jl=0;
	for(int i=l;i<=r;i++){
		sum[a[i]]++;
	}
	for(int i=1;i<=cnt;i++){
		if(sum[i]>mx)mx=sum[i],jl=i;
	}
	return ys[jl];
}
int main(){
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)d[i].a=read(),d[i].id=i;
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(d[i].a!=d[i-1].a)cnt++,a[d[i].a]=cnt;
		else a[d[i].id]=cnt;
		ys[cnt]=d[i].a;
	}
	while(m--){
		int l=read(),r=read();
		l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		printf("%d\n",work(l,r));
	}
	return 0;
}
/*
6 3
10 20 30 20 10 20
1 5
3 6
1 5
*/
