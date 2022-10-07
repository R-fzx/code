#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m,t,h[100005],l[100005],ans;
bool r,c;
inline void answer(int n,int a[])
{	int zjs=(n+1)/2,av=t/n;
	for(register int i=zjs;i<=zjs+n-1;++i)
	{	int now=i%n,nextt=(now+1)%n;
		if(now==0)now=n;
		if(nextt==0)nextt=n;
		int cz=av-a[now];
		a[now]+=cz;
		a[nextt]-=cz;
		ans+=abs(cz);
	}
	return ;
}
signed main()
{	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	n=read(),m=read(),t=read();
	for(register int i=1;i<=t;++i)
	{	int x=read(),y=read();
		h[x]++,l[y]++;
	}
	if(t%n==0)r=1;
	if(t%m==0)c=1;
	if(r==0&&c==0){cout<<"impossible";return 0;}
	else if(r==1&&c==0){cout<<"row";}
	else if(r==0&&c==1){cout<<"column";}
	else cout<<"both";
	if(r)answer(n,h);
	if(c)answer(m,l);
	cout<<' '<<ans;
	return 0;
} 
