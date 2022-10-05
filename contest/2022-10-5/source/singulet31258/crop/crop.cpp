#include<cstdio>
#define scan(i) for(int i=0;i<3;++i)
int n,A,B,C,D,M;long long x,y,f[3][3],ans;
int main(){
	freopen("crop.in","r",stdin);freopen("crop.out","w",stdout);
	scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&x,&y,&M);++f[x%3][y%3];
	while(--n)++f[(x=(A*x+B)%M)%3][(y=(C*y+D)%M)%3];
	scan(i)scan(j)ans+=f[i][j]*(f[i][j]-1)*(f[i][j]-2);ans/=6;
	scan(i)ans+=f[i][0]*f[i][1]*f[i][2]+f[0][i]*f[1][i]*f[2][i];
	return!printf("%lld",ans+f[0][0]*f[1][1]*f[2][2]);
}
