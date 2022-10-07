#include<bits/stdc++.h>
#define re register
#define gt getchar
#define int long long
using namespace std;
int T,a,b,k;
int m,r;
double t;
string s,s1,s2;
inline int read()
{
	re int x=0;
	re bool fl=true;
	re char ch=gt();
	while(ch<48||ch>57){if(ch=='-')fl=0;ch=gt();}
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return fl?x:-x;
} 
inline void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void print(re int x)
{
	if(x<0){putchar('-'),x=-x;}
	write(x),putchar(10);
}
signed main()
{
	freopen("kubi.in","r",stdin);
	freopen("kubi.out","w",stdout);
	T=read();
	while(T--)
	{
		a=read(),b=read(),k=read();
		puts("0 0");
	}
	return 0;
}
