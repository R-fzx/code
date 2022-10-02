#include<cstdio>
#define M 1000000007
#define P 78498
#define N 1000001
int n,p[P],v[N],f[P],tot;
int main(){
#ifndef ONLINE_JUDGE
	freopen("sakura.in","r",stdin);
	freopen("sakura.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=2,j=0;i<=n;++i,j=0){
		if(!v[i])p[tot]=i,v[i]=++tot;
		while(j<v[i]&&i*p[j]<=n)j=v[i*p[j]]=j+1;
	}
	for(int i=0,j=1;i<tot;++i,j=1)while((j*=p[i])<=n)f[i]+=n/j;
	long long ans=f[0]<<1|1;
	for(int i=1;i<tot;++i){
		ans*=f[i]<<1|1;
		if(ans>=M)ans%=M;
	}
	return!printf("%d",ans);
}
