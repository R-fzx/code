#include<stdio.h>
#include<stdlib.h>
long double x=0,y;
double s;
long i,j,k,l,x1,y1,x2,y2,lie[200][200],han[200][200];
double mian[200][200];
void dfs(double a,long b,long c,long d){
	long i,j,k,l,ans=0;
	if(a<1){
		
		return;
	}
	if(d==1){
		for(i=1;i<=a;i++)
			lie[b+100][c+i]=1;
		dfs(a/3.0,b,c+a*2.0/3.0,1);
		dfs(a/3.0,b,c+a*2.0/3.0,2);
		dfs(a/3.0,b,c+a*2.0/3.0,4);
		return;
	}
	if(d==2){
		for(i=1;i<=a;i++)
			han[c][b+100-i+1]=1;
		dfs(a/3.0,b-a*2.0/3.0,c,1);
		dfs(a/3.0,b-a*2.0/3.0,c,3);
		dfs(a/3.0,b-a*2.0/3.0,c,2);
	}
	if(d==3){
		for(i=1;i<=a;i++)
			lie[b+100][c-i+1]=1;
		dfs(a/3.0,b,c-a*2.0/3.0,3);
		dfs(a/3.0,b,c-a*2.0/3.0,2);
		dfs(a/3.0,b,c-a*2.0/3.0,4);
	}
	if(d==4){
		for(i=1;i<=a;i++)
			han[c][b+100+i]=1;
		dfs(a/3.0,b+a*2.0/3.0,c,1);
		dfs(a/3.0,b+a*2.0/3.0,c,4);
		dfs(a/3.0,b+a*2.0/3.0,c,3);
	}
	return ;
}
int main(){
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
	y=1;
	//printf(");
	for(i=1;i<=30;i++){
		y=y*2.0/3.0;
		x+=y;
	}
	x/=2.0;
	if(y1<0){
		printf("0.0\n");
		return 0;
	}
	if(y2<0)y2=-1;
	if(y1>81)y1=82;
	if(y2>81){
		printf("0.0\n");
		return 0;
	}
	if(x1<-27)x1=-28;
	if(x2<-27){
		printf("0.0\n");
		return 0;
	}
	if(x1>27){
		printf("0.0\n");
		return 0;
	}
	if(x2>27)y2=28;
	dfs(81,0,0,1);
	s=0;
	for(i=x1;i<=x2;i++){
		for(j=y1+1;j<=y2;j++)
		   s+=lie[i+100][j];
	}
	for(i=y2;i<=y1;i++){
		for(j=x1+1;j<=x2;j++)
		   s+=han[i][j+100];
	}
	printf("%0.1lf\n",s);
	return 0;
}
