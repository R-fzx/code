#include<stdio.h>
#include<stdlib.h>
long i,j,k,l,n,m,s=0,a[300][300],b[300],c[300],zx[600],yx[600];

void dfs(long x){
	long i,j,k,l;
	if(x>n){
		s++;
		return;
	}
	for(i=1;i<=n;i++)if(!a[x][i]&& !b[i] && !zx[x-i+200] && !yx[x+i]){
		b[i]=1;zx[x-i+200]=1;yx[x+i]=1;
		c[x]=i;
		dfs(x+1);
		b[i]=0;zx[x-i+200]=0;yx[x+i]=0;
	}
	return;	
}
int main(){
	freopen("t3.in","r",stdin);
	freopen("t3.out","w",stdout);
	scanf("%ld",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%ld",&a[i][j]);
	}
	dfs(1);
	printf("%ld\n",s);
	return 0;
}
