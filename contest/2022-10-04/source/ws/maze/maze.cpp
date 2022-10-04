#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;

int n,m,mz[105][105];
double l;
int sx,sy,ex,ey;

double dis[10005];
int vis[10005];

int D(int x,int y){
	return (x-1)*m+y;
}
pair<int,int> E(int x){
	return make_pair((x-1)/m+1,(x-1)%m+1);
}
const int
	dx[4]={1,0,-1,0},
	dy[4]={0,1,0,-1};
bool check(double x){
	priority_queue<pair<double,int> >pq;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dis[D(i,j)]=1e18;
	memset(vis,0,sizeof vis);
	
	dis[D(sx,sy)]=0;
	pq.push(make_pair(0,D(sx,sy)));
	while(!pq.empty()){
		int u=pq.top().second,
			ux=E(u).first,
			uy=E(u).second;
		pq.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		if(ux==ex && uy==ey)
			return dis[u]<=l;
		for(int k=0,nx,ny;k<4;k++){
			nx=ux+dx[k],
			ny=uy+dy[k];
			if(
				nx<1 || nx>n
			||	ny<1 || ny>m
			||	vis[D(nx,ny)]
			||	mz[nx][ny]
			  )
			  	continue;
			double w=1;
			if(k==0 || k==2)
				w=x;
			if(dis[D(nx,ny)]-dis[u]>eps+w){
				dis[D(nx,ny)]=dis[u]+w;
				pq.push(make_pair(-dis[D(nx,ny)],D(nx,ny)));
			}
		}
	}
	return 0;
}

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		memset(mz,0,sizeof mz);
		string s;
		
		cin>>l>>n>>m;
		getline(cin,s);
		
		for(int i=1;i<=n;i++){
			getline(cin,s);
			
			for(int j=1;j<=m;j++){
				if(s[j-1]=='S')
					sx=i,sy=j;
				else if(s[j-1]=='E')
					ex=i,ey=j;
				else if(s[j-1]=='#')
					mz[i][j]=1;
			}
		}
		
		double l=0,r=10,mid;
		for(int o=1;o<=50;o++){
			mid=(l+r)/2;
			if(check(mid))
				l=mid;
			else
				r=mid;
		}
		cout<<fixed<<setprecision(5)<<l<<endl;
	}
	return 0;
}
