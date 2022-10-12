#include<stdio.h>
#include<stdlib.h>
long i,j,k,l,n,m,x,y,z,a[2000][2000],d[2000],f[2000],b[2000];
long long ans;
int main(){
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%ld%ld%ld",&x,&y,&z);
		if(a[x][y]==0 || a[x][y]>z){a[x][y]=z;a[y][x]=z;}
	}
	for(i=1;i<=n;i++){
		d[i]=100000000;
		f[i]=0;
		b[i]=0;
	}
	d[1]=0;
	d[0]=100000000;
	l=1;
	f[1]=1;
	k=1;
	while(k){
		k=0;
		for(i=1;i<=n;i++)
			if(d[i]<d[k] && !b[i]){
				k=i;
		}
		if(k){
			b[k]=1;
			for(i=2;i<=n;i++)if(!b[i] &&a[k][i])
				if( d[k]+a[k][i]<d[i]){
					d[i]=d[k]+a[k][i];
					f[i]=1;
			    }else if(d[k]+a[k][i]==d[i]){
					f[i]++;
				}
		}
	}
	ans=1;
	for(i=1;i<=n;i++){
		ans*=f[i];
		ans%=2147483647;
	}
	printf("%lld\n",ans);
	return 0;
}
