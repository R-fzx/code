#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<iterator>
#include<iostream>
#define oo 0x7fffffff
#define ll long long 
#define mod 1000000007
using namespace std;
ll N,M,K;
ll jc[1000001],c[2001][2001],njc[1000001];
ll f[2001];
ll ans=0;
inline ll ksm(ll &ds,int zs)
{
	int i,j,k;
	ll ret,dq;
	if(zs==0) return(1);
	if(zs==1) return(ds);
	dq=ksm(ds,zs>>1);
	if(zs%2==0)
	  ret=dq*dq%mod;
	else
	  ret=dq*dq%mod*ds%mod;
	return(ret);
}
int main()
{
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);/**/
	ll i,j,k,l;
	scanf("%I64d%I64d%I64d",&N,&M,&K);
	if(M==1)
	{
	  printf("%I64d\n",ksm(K,N));
	  return(0);
	  }
	jc[0]=1;
	njc[0]=1;
	for(i=1;i<=K;i++)
	{
	  jc[i]=jc[i-1]*i%mod;
	  if(i<=4000 || i>=K-4000)
	  njc[i]=ksm(jc[i],mod-2);
	  }
	for(i=1;i<=N;i++)
	  c[i][0]=c[i][i]=1;
	c[0][0]=1;
	for(i=1;i<=N;i++)
	  for(j=1;j<i;j++)
	    c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	f[0]=f[1]=1;
	for(i=2;i<=N;i++)
	{
	  f[i]=ksm(i,N);
	  for(j=1;j<i;j++)
	  {
		f[i]-=f[j]*c[i][j]%mod;
		if(f[i]<0) f[i]+=mod;
	    }
	  }
	for(i=0;i<=N;i++)
	{
	  ll cc1=ksm(i,N*(M-2))*njc[i]%mod*jc[K]%mod;
	  for(j=0;j<=N-i && j<=(K-i)/2;j++)
	  {
		ll dq=0;
		dq=f[i+j]*f[i+j]%mod*cc1%mod*njc[K-2*j-i]%mod*njc[j]%mod*njc[j]%mod;
	    ans=(ans+dq)%mod;
		}
	  }
	printf("%I64d\n",ans);
	return(0);	
}
