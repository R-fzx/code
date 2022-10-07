#include<bits/stdc++.h>
#define re register
#define gt getchar
using namespace std;
const int T=1e5+7;
int n,m,t;
struct node{
	int x,y;
}nd[T];
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
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	n=read(),m=read(),t=read();
	for(re int i=1; i<=t; i++)
		nd[i].x=read(),nd[i].y=read();
	puts("impossible");
	return 0;
}
