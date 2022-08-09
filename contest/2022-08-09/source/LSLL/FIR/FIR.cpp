#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int q[N][N];
int u[N],v[N],u2[N],v2[N];
int cnt,cnt2;
int n,x;
bool vis[N][N];
int d1[4]={1,0,-1,0},d2[4]={0,1,0,-1};
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	}
	return x*f;
}
void work(int xx,int yy,int color){
	bool f=0;
	queue<pair<int,int> >p;
	queue<pair<int,int> >jc;
	p.push(make_pair(xx,yy));
	jc.push(make_pair(xx,yy));
	memset(vis,0,sizeof(vis));
	vis[xx][yy]=1;
	while(!p.empty()){
		int xx2=p.front().first,yy2=p.front().second;
		p.pop();
		for(int i=0;i<4;i++){
			int xx3=xx2+d1[i],yy3=yy2+d2[i];
			if(q[xx3][yy3]==0){
				f=1;
				break;
			}
			if(q[xx3][yy3]==color&&!vis[xx3][yy3]){
				p.push(make_pair(xx3,yy3));
				jc.push(make_pair(xx3,yy3));
				vis[xx3][yy3]=1;
			}
		}
		if(f==1)break;
	}
	if(f==1)return;
	while(!jc.empty()){
		int xx2=jc.front().first,yy2=jc.front().second;
		jc.pop();
		q[xx2][yy2]=0;
	}
}
int check(int a,int b,int color){
	if(color==0)color+=2;
	if(q[a][b])return 0;
	q[a][b]=color;
	if(q[a-1][b]!=q[a][b]&&q[a-1][b]!=0){
		work(a-1,b,q[a-1][b]);
	}
	if(q[a+1][b]!=q[a][b]&&q[a+1][b]!=0){
		work(a+1,b,q[a+1][b]);
	}
	if(q[a][b-1]!=q[a][b]&&q[a][b-1]!=0){
		work(a,b-1,q[a][b-1]);
	}
	if(q[a][b+1]!=q[a][b]&&q[a][b+1]!=0){
		work(a,b+1,q[a][b+1]);
	}
	work(a,b,q[a][b]);
	if(q[a][b]!=0)return 1;
	return 0;
}
int left(int xx,int yy,int color){
	for(int i=xx,j=yy,k=0;k<x;k++){
		if(q[i][j+k]!=color)return 0;
	}
	return 1;
}
int down(int xx,int yy,int color){
	for(int i=xx,j=yy,k=0;k<x;k++){
		if(q[i+k][j]!=color)return 0;
	}
	return 1;
}
int ld(int xx,int yy,int color){
	for(int i=xx,j=yy,k=0;k<x;k++){
		if(q[i+k][j+k]!=color)return 0;
	}
	return 1;
}
int win(){
	for(int i=1;i<=cnt;i++){
		if(q[u[i]][v[i]]!=1)continue;
		if(left(u[i],v[i],1))return 1;
		if(down(u[i],v[i],1))return 1;
		if(ld(u[i],v[i],1))return 1;
	}
	return 0;
}
int win2(){
	for(int i=1;i<=cnt2;i++){
		if(q[u2[i]][v2[i]]!=2)continue;
		if(left(u2[i],v2[i],2))return 1;
		if(down(u2[i],v2[i],2))return 1;
		if(ld(u2[i],v2[i],2))return 1;
	}
	return 0;
}
int main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	n=read(),x=read();
	for(int i=1;i<=n;i++){
		int a=read(),b=read();
		if(check(a,b,i&1)){
			if(!(i&1)){
				u2[++cnt2]=a;
				v2[cnt2]=b;
				q[a][b]=2;
			}
			else{
				u[++cnt]=a;
				v[cnt]=b;
				q[a][b]=1;
			} 
		}
		else{
			puts("illegal");
			return 0;
		}
		if(win()){
			printf("ITer %d",i);
			return 0;
		}
		if(win2()){
			printf("Kitty %d",i);
			return 0;
		}
	}
	puts("draw");
	return 0;
}
/*
20 5
2 3
3 3
3 2
2 2
4 3
2 4
5 3
1 3
3 4
5 5
2 3
3 3
2 3
2 5
6 3
1 5
3 3
1 5
1 5
1 5

*/
