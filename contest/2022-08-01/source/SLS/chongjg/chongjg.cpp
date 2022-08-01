#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N];
int n,m,j11,j22;
int s,t;
int check(){
	for(int i=1;i<=j11;i++){
		for(int j=1;j<=j22;j++){
			if(!a[i][j])return 0;
		}
	}
	return 1;
}
void print(int x,int y,int aa,int b,int w){
	for(int i=x;i<=aa;i++){
		for(int j=y;j<=b;j++){
			a[i][j]=w;
		}
	}
}
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	scanf("%d%d",&n,&m);
	j11=n,j22=m;
	s=1,t=1;
	while(!check()){
		int mi=min(a[s-1][t],a[s][t-1]);
		int ma=max(a[s-1][t],a[s][t-1]);
		int g=min(n,m);
		if(n>m)n-=g;
		else m-=g;
		if(g==0)break;
		if(s==1&&t==1){
			print(s,t,s+g-1,t+g-1,1);
		}
		else if(s==1&t!=1){
			if(a[s][t-1]!=1)
			print(s,t,s+g-1,t+g-1,1);
			else print(s,t,s+g-1,t+g-1,2);
		}
		else if(t==1&&s!=1){
			if(a[s-1][t]!=1)
			print(s,t,s+g-1,t+g-1,1);
			else print(s,t,s+g-1,t+g-1,2);
		}
		else if(mi==1&&ma==2){
			print(s,t,s+g-1,t+g-1,3);
		}
		else if(mi==1&&ma==3||mi==1&&ma==1){
			print(s,t,s+g-1,t+g-1,2);
		}
		else if(mi!=1){
			print(s,t,s+g-1,t+g-1,1);
		}
		if(s+g-1==j11)t+=g;
		else if(t+g-1==j22)s+=g;
		
	}
	for(int i=1;i<=j11;i++){
		for(int j=1;j<=j22;j++){
			if(a[i][j]==1)putchar('A');
			if(a[i][j]==2)putchar('B');
			if(a[i][j]==3)putchar('C');
		}
		puts("");
	}
	return 0;
}
