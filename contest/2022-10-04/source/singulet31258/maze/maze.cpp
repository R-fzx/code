#include<cstdio>
#include<queue>
#define N 101
#define N_SQR 10001
#define EPS 1e-8
#define hash(x,y) ((x-1)*c+y)
#define getx(x) ((x-1)/c+1)
#define gety(x) (x%c)
struct node{
	int x;
	double d;
	bool operator<(const node& n)const{return d>n.d;}
};
double l,v,dis[N_SQR];
int r,c,s,e,vis[N_SQR],xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
char g[N][N];
std::priority_queue<node>q;
int check(){
	while(!q.empty())q.pop();
	for(int i=0;i<r*c;++i)vis[i]=0,dis[i]=1e100;
	q.push({s,.0});dis[s]=.0;
	int now,x,y,nowx,nowy,to;
	double t;
	while(!q.empty()&&!vis[e]){
		now=q.top().x;q.pop();
		if(vis[now])continue;vis[now]=1;
		x=getx(now);y=gety(now);
		for(int i=0;i<4;++i){
			nowx=x+xx[i];nowy=y+yy[i];
			if(nowx<1||nowy<1||nowx>r||nowy>c||g[nowx][nowy]=='#')continue;
			t=i>1?v:1.0;
			to=hash(nowx,nowy);
			if(dis[now]+t<dis[to]){
				dis[to]=dis[now]+t;
				q.push({to,dis[to]});
			}
		}
	}
	return dis[e]<=l;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lf%d%d",&l,&r,&c);
		getchar();
		for(int i=1;i<=r;++i){
			gets(g[i]+1);
			for(int j=1;j<=c;++j){
				switch(g[i][j]){
				case'S':
					s=hash(i,j);
					break;
				case'E':
					e=hash(i,j);
					break;
				}
			}
		}
		double lower=.0,upper=10.0;
		while(lower<upper){
			v=(lower+upper)/2.0;
			if(check())lower=v+EPS;
			else upper=v-EPS;
		}
		printf("%.5lf\n",v);
	}
	return 0;
}
