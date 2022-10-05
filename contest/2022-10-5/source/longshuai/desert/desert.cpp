#include<bits/stdc++.h>
using namespace std;
const int maxn=50*50+5;
const int dir[9][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int n;
int g[55][55];
int wind[maxn],t[maxn],dis=maxn*2;
int x,y;
int ans=maxn*2;
void get_wind(int tx,int ty,int lax,int lay,int len){
	if(len>=dis)return;
	if(g[tx][ty]==2){
		for(int i=1;i<=len;i++)
			wind[i]=t[i];
		dis=len;
		return;
	}
	for(int i=1;i<=8;i++){
		int vx=tx+dir[i][0],vy=ty+dir[i][1];
		if((vx!=lax||vy!=lay)&&g[vx][vy]){
			t[len+1]=i;
			get_wind(vx,vy,tx,ty,len+1);
			t[len+1]=0;
		}
	}
}
void get_ans(int tx,int ty,int lax,int lay,int len,int step){
	if(len>=ans)return;
	if(g[tx][ty]==2){
		ans=len;
		return;
	}
	for(int i=1;i<=8;i++){
		int vx=tx+dir[i][0],vy=ty+dir[i][1];
		if((vx!=lax||vy!=lay)&&g[vx][vy]){
			if(i==wind[step])get_ans(vx,vy,tx,ty,len+3,step+1);
			else get_ans(vx,vy,tx,ty,len+1,step+1);
		}
	}
}
int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char c;
			cin>>c;
			if(c!='X')g[i][j]=1;
			if(c=='*')g[i][j]=2;
			if(c=='@')x=i,y=j;
		}
	get_wind(x,y,-1,-1,0);
	if(dis==maxn*2){
		printf("-1\n");
		return 0;
	}
//	cout<<dis<<endl;
//	for(int i=1;i<=dis;i++)
//		cout<<wind[i]<<endl;
	get_ans(x,y,-1,-1,0,1);
	printf("%d\n",ans);
	return 0;
}
