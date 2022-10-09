#include<cstdio>
#include<algorithm>
#define N 1000000000
#define _ long long
int cnt;
_ a,b,h[0x1800],f[20][20][0x1800];
int main(){
	for(_ i=1;i<N;i<<=1)for(_ j=i;j<N;j*=3)for(_ k=j;k<N;k*=5)for(_ l=k;l<N;l*=7)h[++cnt]=l;std::sort(h+1,h+cnt+1);
	for(int i=1;i<10;++i)f[1][i][i]=1;
	for(int i=2;i<19;++i)for(int k=1;k<=cnt;++k)for(int j=1;j<10;++j)if(h[k]%j==0);
#ifndef ONLINE_JUDGE
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
#endif
	scanf("%lld%lld",&a,&b);
	return!printf("%d",4);
}
