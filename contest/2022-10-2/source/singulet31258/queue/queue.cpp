#include<cstdio>
#include<algorithm>
#define N 300
int n,h[N],f[2];
int main(){
#ifndef ONLINE_JUDGE
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",h+i);
	std::sort(h,h+n);double t=n+1.0,ans=1.0/t;
	for(int i=1,j=0;i<n;++i,j^=1){
		if(h[i]==h[i-1])f[j]=f[j^1];else f[j]=i;
		ans+=1.0/(t-f[j]);
	}
	return!printf("%.2lf",ans*t);
}
