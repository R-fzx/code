#include<cstdio>
int d[0x38],p,cnt[10];long long C[0x38][0x38],ans,t;
int main(){
	for(int i=0;i<0x38;++i)C[i][0]=1;for(int i=1;i<0x38;++i)for(int j=1;j<=i;++j)C[i][j]=C[i-1][j]+C[i-1][j-1];
	freopen("perm.in","r",stdin);freopen("perm.out","w",stdout);
	while((d[p++]=getchar()&0xf)!=('\n'&0xf));--p;
	for(int i=0;i<p;++i)++cnt[d[i]];
	for(int i=0;i<p;--cnt[d[i]],++i)for(int j=0;j<d[i];++j){if(!cnt[j])continue;t=1;for(int k=0,s=0;k<10;++k)t*=C[s+(k==j?cnt[k]-1:cnt[k])][s],s+=(k==j?cnt[k]-1:cnt[k]);ans+=t;}
	return!printf("%lld",ans);
}
