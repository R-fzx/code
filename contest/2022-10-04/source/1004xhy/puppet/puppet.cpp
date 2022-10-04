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
const int N=109;
using namespace std;
short n,len;
char out[10009];
int f[N][N],p[N],g[N];
inline char gt()
{
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline void pt()
{fwrite(out,1,len,stdout),len=0;}
inline int read()
{
	re int x=0;
	re char ch=gt();
	while(ch<48||ch>57){if(ch==EOF)return -1;ch=gt();}
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
}
inline void write(re int x)
{
	if(x>9)write(x/10);
	out[len++]=x%10+48;
}
inline void init()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(re int i=1; i<=n; i++)
		p[i]=read();
	sort(p+1,p+1+n);
}
signed main()
{
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	while((n=read())!=-1)
	{
		init();
		for(re int i=1; i<=n; i++)
			for(re int j=i; j<=n; j++)
			{
				bool fl=false;
				for(re int k=1; k<=n; k++)
				{
					int l=i,r=i+k;
					for(; r<=j; l++,r++)
						if(p[r]-p[l]>1)fl=true;
					if(abs(p[l]-p[i+k-1])<=1)fl=true;
					if(fl){f[i][j]=k-1;break;}
				}
				if(!fl)f[i][j]=j-i+1;
			}
		for(re int i=1; i<=n; i++)
			for(re int j=0; j<i; j++)
				g[i]=max(g[i],g[j]+f[j+1][i]);
		write(g[n]),out[len++]=10;
	}
	pt();
	return 0;
}
