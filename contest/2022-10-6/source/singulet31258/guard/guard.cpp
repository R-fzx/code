#include<cstdio>
#define N 201
#define N2 402
#define scan(i,a,b) for(int i=a;i<=b;++i)
#define travel(i,a,b) for(int i=a;i<b;++i)
int n,l,k,a[N];double p[N],ans,f[N][N][N2];
int main(){
	freopen("guard.in","r",stdin);freopen("guard.out","w",stdout);
	scanf("%d%d%d",&n,&l,&k);int t=N+k;if(t>=N2)t=N2-1;scan(i,1,n)scanf("%lf",p+i),p[i]/=100;scan(i,1,n)scanf("%d",a+i);f[0][0][t]=1;
	travel(i,0,n)travel(j,0,n)travel(k,1,N2){t=k+a[i+1];if(t>=N2)t=N2-1;f[i+1][j][k]+=f[i][j][k]*(1-p[i+1]);f[i+1][j+1][t]+=f[i][j][k]*p[i+1];}scan(i,l,n)travel(j,N,N2)ans+=f[n][i][j];
	return!printf("%.6lf",ans);
}
