#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')

using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=109;
struct edge{
	int to;
	double val;
	edge(int t,double v){to=t;val=v;}
};
struct node{
	int num;
	double dis;
	node(int nm,double d){num=nm;dis=d;}
};
int T,n,m,bx,by,ex,ey;
pair<int,int>spt[N*N];
double dis[N*N];
int sp[N][N],fx[5]={0,1,0,-1,0},fy[5]={0,0,1,0,-1},cnt,vis[N];
double l;
char s[N][N];
vector<edge>e[N];
priority_queue<node>q;
bool operator<(node x,node y){return x.dis>y.dis;}
int check(double v){
	for(int i=1;i<=cnt;i++)e[i].clear();
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#')continue;
			for(int k=1;k<=4;k++){
				if(s[i+fx[k]][j+fy[k]]=='#')continue;
				if(k==2||k==4)e[sp[i][j]].push_back(edge(sp[i+fx[k]][j+fy[k]],1));
				else e[sp[i][j]].push_back(edge(sp[i+fx[k]][j+fy[k]],v));
			}
		}
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[sp[ex][ey]]=0;
	q.push(node(sp[ex][ey],0));
	for(int i=1;i<=cnt;i++){
		int x;
		while(!q.empty()&&vis[q.top().num])q.pop();
		if(q.empty())break;
		x=q.top().num;q.pop();vis[x]=1;
		for(int j=0;j<e[x].size();j++){
			if(dis[e[x][j].to]>dis[x]+e[x][j].val){
				dis[e[x][j].to]=dis[x]+e[x][j].val;
				q.push(node(e[x][j].to,dis[e[x][j].to]));
			}
		}
	}
	if(dis[sp[bx][by]]==l)return 1;
	if(dis[sp[bx][by]]<l)return 0;
	return 2;
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	T=read();
	while(T--){
		scanf("%lf",&l);
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			string t;
			getline(cin,t);
			for(int j=1;j<=m;j++)s[i][j]=t[j-1];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(s[i][j]=='S')bx=i,by=j;
				if(s[i][j]=='E')ex=i,ey=j;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]!='#')spt[++cnt]=make_pair(i,j),sp[i][j]=cnt;
		double l=0,r=10,ans;
		while(l<r){
			double mid=(l+r)/2;
			if(check(mid)==1){ans=mid;break;}
			if(check(mid)==2)r=mid;
			else l=mid;
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}
/*
2
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#  ## #    #
#     #    #
############
*/
