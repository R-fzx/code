#include<cstdio>
#include<cstring>
#include<algorithm>
int n,p[51],f[51];
int calc(int x,int y){
	for(int i=1;i<=y-x+1;++i){
		for(int j=i;j<=y-x;++j)if(p[j+x]-p[j+x-i]>1)return i-1;
		if(std::abs(p[x+i-1]-p[y-i+1])<=1)return i-1;
	}return y-x+1;
}
int main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	while(~scanf("%d",&n)){
		memset(f,0,sizeof f);
		for(int i=1;i<=n;scanf("%d",p+i),++i);std::sort(p+1,p+n+1);
		for(int i=1;i<=n;++i)for(int j=0;j<i;++j)f[i]=std::max(f[i],f[j]+calc(j+1,i));
		printf("%d\n",f[n]);
	}return 0;
}
