#include<cstdio>
#include<algorithm>
#define scan for(int i=0;i<n;++i)
int n,x[800],y[800];long long ans;
int main(){
	freopen("scalar.in","r",stdin);freopen("scalar.out","w",stdout);
	scanf("%d",&n);scan scanf("%d",x+i);scan scanf("%d",y+i);std::sort(x,x+n);std::sort(y,y+n);
	scan ans+=x[i]*y[n-1-i];
	return!printf("%lld",ans);
}
