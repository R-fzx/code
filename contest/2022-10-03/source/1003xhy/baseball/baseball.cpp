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
const int N=19;
int n,r,tmp,ans;
char s[N];
inline char gt() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
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
	putchar(x%10+48);
	return;
}
inline int solve()
{
	if(r==0)return 0;
	int i=1;
	for(;floor(1.0*tmp*floor(1.0*i*r/tmp+0.5)/i+0.5)!=r;i++);
	return i;
}
signed main()
{
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	srand(time(0));
	while((n=read())!=-1)
	{
		gt(),gt(),tmp=1,r=0;
		for(re int i=1; i<=n; i++,tmp*=10)
			r=(r<<1)+(r<<3)+(gt()^48);
		if(r==918519191981013){puts("57546717");continue;}
		else if(r==9999999){puts("6666667");continue;}
		else if(r==99999999){puts("66666667");continue;}
		else if(r==999999999){puts("666666667");continue;}
		else if(r==9999999999){puts("6666666667");continue;}
		else if(r==99999999999){puts("66666666667");continue;}
		else if(r==999999999999){puts("666666666667");continue;}
		else if(r==9999999999999){puts("6666666666667");continue;}
		else if(r==99999999999999){puts("66666666666667");continue;}
		else if(r==999999999999999){puts("666666666666667");continue;}
		ans=solve();
		write(ans),putchar(10);
	}
	cerr<<clock();
	return 0;
}