#include<bits/stdc++.h>
using namespace std;
struct su{
	int x,y;
	int d;
};
queue<su>q;
bool vis[55][55];
bool p[55][55];
bool grn[55][55];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
inline su makesu(int x,int y,int d){
	su v;v.x=x;v.y=y;v.d=d;
	return v;
}
int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	int n;cin>>n;
	int sx,sy;
	char c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>c;
			if(c=='X') p[i][j]=true;
			else if(c=='@') sx=i,sy=j;
			else if(c=='*') grn[i][j]=true;
		}
	for(int i=0;i<=n+1;i++)
		p[i][0]=p[i][n+1]=p[0][i]=p[n+1][i]=true;
	q.push(makesu(sx,sy,0));
	int x,y,xx,yy;
	su v;
	while(!q.empty()){
		v=q.front();q.pop();
		x=v.x;y=v.y;
		if(grn[x][y]){
			cout<<v.d<<endl;
			return 0;
		}
		for(int i=0;i<8;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(!p[xx][yy]&&!vis[xx][yy]){
				q.push(makesu(xx,yy,v.d+1));
				vis[xx][yy]=1;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
