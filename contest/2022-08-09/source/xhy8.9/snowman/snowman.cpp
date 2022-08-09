#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define re register
#define gt getchar
using namespace std;
const int N=1e5;
int n,ans,x[N];

inline char gt() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
	register int x=0;
	register char ch;
	while(ch<48||ch>57)ch=gt();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
}
inline void write(register int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main()
{
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	n=read();
	for(re int i=1; i<=n; i++)
		x[i]=read();
		re int l1,l2,r1,r2,i;
	for(l1=1; l1<=n; l1++)
		for(l2=1; l2<=n; l2--)
			for(r1=n; r1>=l1+max(ans,1); r1--)
			{
				r2=l2+(r1-l1);
				re int t=x[0+l1]-x[0+l2];
				for(i=1; i<=r1-l1; i++)
				{
					if(x[i+l1]-x[i+l2]!=t)break;
					t=x[i+l1]-x[i+l2];
				}
				if(i>r1-l1)ans=max(ans,min(abs(l2-l1),r1-l1+1));
			}
	write(ans);
//	cerr<<clock();
	return 0;
}
