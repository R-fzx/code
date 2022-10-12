#include<stdio.h>
#include<stdlib.h>
long long i,j,k,l,n,m,e=10007,t;
long long fa[2000],gs[2000],son[2000][2],a[2000];
int b[1000000];
long long c(long long x,long long y){
	long long i,j=0,k=0,l,j1,k1,ans=1;
	for(i=2;i<=y;i++)if(!b[i]){
		l=y/i;j=l;
		while(l){
			l/=i;
			j+=l;
		}
		l=x/i;k=l;
		while(l){
			l/=i;
			k+=l;
		}
		j-=k;
		l=(y-x)/i;k=l;
		while(l){
			l/=i;
			k+=l;
		}
		j-=k;
		while(j){j--;
			ans*=i;
			ans%=e;
		}
	}
	return ans%e;
}
long long dfs(long x){
	long long  i,j,k,y=0,z=0;	
	if(!son[x][0] && !son[x][1]){
		return 1;		
	}
	if(son[x][0] && son[x][1]){
		y=dfs(son[x][0])%e;
		z=dfs(son[x][1])%e;
		j=gs[son[x][0]]+1;
		if(gs[son[x][1]]+1>j)j=gs[son[x][1]]+1;
		k=c(j ,gs[x])%e;
		return y*z%e*k%e;
	}
	if(son[x][0])return dfs(son[x][0])%e;
	if(son[x][1])return dfs(son[x][1])%e;	
}
void change(long x){
	gs[x]++;
	if(x!=1)change(fa[x]);
	return;
}
int main(){
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	for(i=4;i<=1000;i+=2)
		b[i]=1;
	for(i=3;i<=32;i+=2)if(b[i]==0){
		for(j=i*i;j<=1000;j+=2*i){b[j]=1;}
	}
	scanf("%lld",&t);
	while(t){t--;
		scanf("%lld",&n);
		for(i=1;i<=2000;i++){gs[i]=0;fa[i]=0;son[i][0]=son[i][1]=0;}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[0]);
			for(j=1;j<=a[0];j++){
				scanf("%lld",&a[j]);
				if(j>1){
					son[a[j-1]][1]=a[j];
					fa[a[j]]=a[j-1];
					change(a[j-1]);
				}else{
					son[i][0]=a[j];
					fa[a[j]]=i;
					change(i);
				}
			}
		}
		
		printf("%lld\n",dfs(1)%e);
	}
	
	return 0;
}
