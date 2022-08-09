#include<bits/stdc++.h>
using namespace std;
int chess[1015][1015],n,t;
int rubx[1005],ruby[1005],rcnt;
bool vis[1005][1005];
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void inrub(int x,int y){rubx[++rcnt]=x;ruby[rcnt]=y;}
void clr(bool iseat){
	//cerr<<"est : "<<iseat<<" cnt : "<<rcnt<<"  NOW:\n";
	while(rcnt){
		vis[rubx[rcnt]][ruby[rcnt]]=0;
		if(!iseat)chess[rubx[rcnt]][ruby[rcnt]]=0;
		//cerr<<rubx[rcnt]<<' '<<ruby[rcnt]<<endl;
		rcnt--;
}	}
bool check(int sx,int sy,int cl){
	queue<pair<int,int> >q;
	if(chess[sx][sy]==cl)q.push(make_pair(sx,sy)),vis[sx][sy]=1;
	bool iszero=0;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		inrub(x,y);
		//cerr<<"NNow:"<<x<<' '<<y<<endl;
		if(!chess[x-1][y] || !chess[x+1][y] || !chess[x][y-1] || !chess[x][y+1])iszero=1;
		for(int nx,ny,k=0;k<4;k++){
			nx=x+dx[k],ny=y+dy[k];
			if(!vis[nx][ny] && chess[nx][ny]==cl)q.push(make_pair(nx,ny)),vis[nx][ny]=1;
		}
	}
	return iszero;
}
bool winn(int x,int y,int cl){
	bool ok;
	for(int i=max(1,y-t+1);i<=y;i++){
		ok=1;
		for(int j=i;j<=i+t-1;j++)if(chess[x][j]!=cl){ok=0;break;}
		if(ok)return 1;
	}
	for(int i=max(1,x-t+1);i<=x;i++){
		ok=1;
		for(int j=i;j<=i+t-1;j++)if(chess[j][y]!=cl){ok=0;break;}
		if(ok)return 1;
	}
	for(int i=min(t,min(x,y));i;i--){
		ok=1;
		for(int j=1;j<=t;j++)if(chess[x-i+j][y-i+j]!=cl){ok=0;break;}
		if(ok)return 1;
	}
	if(x+y-1<t)return 0;
	for(int i=min(t,x);i && y+i-t;i--){
		ok=1;
		for(int j=1;j<=t;j++)if(chess[x-i+j][y+i-j]!=cl){ok=0;break;}
		if(ok)return 1;
	}
	return 0;
}
int main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	cin>>n>>t;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		int cl=(i&1)+1;
		//cerr<<endl<<endl<<i<<":1\n";
		if(chess[x][y])return cout<<"illegal",0;
		chess[x][y]=cl;
		clr(check(x-1,y,3-cl));clr(check(x+1,y,3-cl));
		clr(check(x,y-1,3-cl));clr(check(x,y+1,3-cl));
		//cerr<<endl<<i<<":2\n";
		if(!check(x,y,cl))return cout<<"illegal",0;clr(1);
		if(winn(x,y,cl))return cout<<(cl==2?"ITer ":"Kitty ")<<i,0;
		//cerr<<endl;
	}
	cout<<"draw";
	return 0;
}
