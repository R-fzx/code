#include<cstdio>
#include<cstring>
#define O 40001
#define scan(i,x,y) for(i=x;i<y;++i)
#define solve(x) f[0][O]=1;\
scan(i,0,n)scan(j,-O,O)if(f[i][j+O])f[i+1][j+x[i+1]+O]=f[i+1][j-x[i+1]+O]=1;\
scan(i,0,O)if(f[n][O+i]||f[n][O-i]){ans+=i*i;break;}
int i,j,n,x[201],y[201],ans,f[201][80008];
int main(){
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i),ans-=x[i]*x[i]+y[i]*y[i];
	solve(x);memset(f,0,sizeof f);solve(y);
	return!printf("%.2lf",ans/2.0);
}
