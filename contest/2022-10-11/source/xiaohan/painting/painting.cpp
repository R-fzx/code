#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m,k,s[2005][2005],jc[1000005],ans;
inline int ksm(int x,int y)
{	int res=1;
	while(y)
	{	if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1; 
	}
	return res;
}
inline int C(int x,int y)
{	return jc[x]*ksm(jc[x-y],mod-2)%mod*ksm(jc[y],mod-2)%mod;
}
signed main()
{	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	n=read(),m=read(),k=read();
	s[0][0]=1;
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=i;++j)
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j]%mod)%mod;
	jc[0]=1; 
	for(register int i=1;i<=1000000;++i)jc[i]=jc[i-1]*i%mod;
	for(register int i=0;i<=min(n,k);++i)
	{	for(register int j=0;j<=n-i&&k-i-j>=j;++j)	
			ans=(ans+C(k,i)*C(k-i,j)%mod*C(k-i-j,j)%mod*s[n][i+j]%mod*s[n][i+j]%mod*jc[i+j]%mod*jc[i+j]%mod*ksm(i,n*(m-2))%mod)%mod;//,cout<<i<<' '<<j<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

