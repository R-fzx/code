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
#define re register
#define int long long
using namespace std;
const int N=309;
int n,ans,h[N],b[N],f[N];
inline char gt() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
	re int x=0;
	re char ch=gt();
	while(ch<48||ch>57)ch=gt();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
} 
inline void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
	return;
}
inline void dfs(int x)
{
	if(x==1)
	{
		for(re int i=1; i<n; i++)
			if(h[i]>h[n])ans--;
		return;
	}
	for(re int i=n-x+1; i<=n; i++)
	{
		swap(h[n-x+1],h[i]);
		for(re int j=1; j<n-x+1; j++)
			if(h[j]<h[n-x+1])ans++;
		for(re int j=1; j<n; j++)
			if(h[j]<h[n])ans++;
		dfs(x-1);
		swap(h[n-x+1],h[i]);
	}
	return;
}
signed main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	n=read();
	for(re int i=1; i<=n; i++)
		h[i]=read(),h[i]=b[i]=i;
	ans=n*(n+1)/2;
	dfs(n);
	printf("%.2lf",1.0*ans/n); 
	return 0;
} 
