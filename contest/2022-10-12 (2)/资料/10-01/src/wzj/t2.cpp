#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long i,j,k,l,s,x,y,q;
long long g[100];
long long kf(long x,long y){
	long long i,j,k,l=0,r=x,z,mid,ll=0;
	while(l<r){
		ll=0;
		mid=(l+r)/2;
		z=1;
		for(i=1;i<=y;i++){
		   z*=mid;
		   if(z>x)ll=1;
	    }
		if(z>x ||ll)r=mid;
		else if(z==x)return mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	scanf("%lld%lld",&x,&y);
	while(x+y!=0){
		for(i=60;i>1;i--){
			g[i]=kf(y,i)-kf(x,i)+1;
			k=g[i];
			for(j=2;i*j<=60;j++)
			    k-=g[i*j];
			s+=k*i;
		}
		printf("%lld\n",s);
		scanf("%lld%lld",&x,&y);
	}
	return 0;
}
