#include<cstdio>
#include<cstring>
#define N 1<<10
#define M 1<<10
int n,m,i,j,k,l,len,c,t[N][M],v[26];
int tile(int x,int y){
	if(t[x][y])return t[x][y];
	memset(v,0,sizeof(v));
	if(x)v[t[x-1][y]-65]=1;
	if(y)v[t[x][y-1]-65]=1;
	if(y<m-1&&t[x][y+1])v[t[x][y+1]-65]=1;
	for(k=0;v[k];++k);
	return k+65;
}
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		if(t[i][j])continue;
		c=tile(i,j);
		for(len=1;i+len<n&&j+len<m&&tile(i,j+len)==c;++len);
		for(k=i;k<i+len;++k)for(l=j;l<j+len;++l)t[k][l]=c;
	}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j)putchar(t[i][j]);
		putchar(10);
	} 
	return 0;
}
