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
const int N=109,M=109,mod=1e9+7;
int n,m,du[N],u[M],v[M];
inline char gt()
{
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	int x=0;
	bool fl=1;
	char ch=gt();
	while(ch<48||ch>57){if(ch=='-')fl=0;ch=gt();}
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return fl?x:-x;
} 
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void print(int x)
{
	if(x<0){putchar('-'),x=-x;}
	write(x),putchar(10);
}
inline int solve(int x)
{
	int ans=0;
	for(re int i=1; i<=(1<<x)-1; i++)
	{
		memset(du,0,sizeof(du));
		for(re int j=i,k=1; j; j>>=1,k++)
			if(j&1)du[u[k]]++,du[v[k]]++;
		bool fl=1;
		for(re int j=i,k=1; j; j>>=1,k++)
			if(j&1)if(du[u[k]]==0||du[v[k]]==0||(du[u[k]]&1)||(du[v[k]]&1)){fl=0;break;}
		ans+=fl;
	}
	return ans;
}
signed main()
{
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	n=read(),m=read();
	for(re int i=1; i<=m; i++)
	{
		u[i]=read(),v[i]=read();
		print(solve(i));
	}
	return 0;
}
