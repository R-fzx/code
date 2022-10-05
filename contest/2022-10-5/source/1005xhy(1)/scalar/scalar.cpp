#include<bits/stdc++.h>
#define re register
#define gt getchar
#define int long long
using namespace std;
const int N=1e3+9;
int n,ans,x[N],y[N];
struct node{
	int x,y;
}ndx[N],ndy[N];
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
}
inline bool cmp(int t1,int t2){return t1>t2;}
signed main()
{
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	n=read();
	for(re int i=1; i<=n; i++)x[i]=read();
	for(re int i=1; i<=n; i++)y[i]=read();
	sort(x+1,x+1+n);
	sort(y+1,y+1+n,cmp);
	for(re int i=1; i<=n; i++)
		ans+=x[i]*y[i];
	write(ans);
	return 0;
}
