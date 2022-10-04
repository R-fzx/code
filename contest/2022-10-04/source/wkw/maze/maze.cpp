#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
inline int read(){
    int x=0;
    bool w=0;
    char c=getchar();
    while(!isdigit(c))  w|=c=='-',c=getchar();
    while(isdigit(c))   x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void print(int x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar('0'+x%10);
}
const int N=105;
const double eps=1e-7,INF=1e9;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int R,C,sx,sy,ex,ey,tot;
double L;
struct node{
	int now;
	double dis;
	bool operator<(const node &x) const{
		return dis>x.dis;
	}	
};
struct edge{
	int to,nxt;
	double dis;
}Edge[N*N*4];
char s[N][N];
int head[N*N];
double dis[N*N];
bool vis[N*N];
#define Num(x,y) (x-1)*C+y
inline void add(int u,int v,double w){
	Edge[++tot].to=v;
	Edge[tot].nxt=head[u];
	Edge[tot].dis=w;
	head[u]=tot;
}
inline void Init(){
	cin>>L;R=read(),C=read();
	for(register int i=1;i<=R;++i){
		string t;
		getline(cin,t);
		for(register int j=1;j<=C;++j)
			s[i][j]=t[j-1];
	}
//	cout<<"Array s:\n";
//	for(register int i=1;i<=R;++i){
//		for(register int j=1;j<=C;++j)
//			cout<<s[i][j];
//		cout<<endl;
//	}
	memset(head,0,sizeof(head));
	tot=0;
	for(register int i=1;i<=R;++i){
		for(register int j=1;j<=C;++j){
			if(s[i][j]=='S')	sx=i,sy=j;
			if(s[i][j]=='E')	ex=i,ey=j;
			if(s[i][j]!='#'){
				for(register int k=0;k<4;++k){
					int xx=dx[k]+i,yy=dy[k]+j;
					if(s[xx][yy]=='#' || xx<1 || yy<1 || xx>R || yy>C)	continue;
					if(k==2 || k==3){
//						cout<<Num(i,j)<<' '<<Num(xx,yy)<<' '<<-1<<endl;
						add(Num(i,j),Num(xx,yy),-1);
					}
					else{
//						cout<<Num(i,j)<<' '<<Num(xx,yy)<<' '<<1<<endl;
						add(Num(i,j),Num(xx,yy),1);
					}
				}
			}
		}
	}	
}
inline double dij(double W){
	priority_queue<node> q;
	q.push((node){Num(sx,sy),0});
	memset(vis,0,sizeof(vis));
	for(register int i=1;i<=R*C;++i)
		dis[i]=INF;
	dis[Num(sx,sy)]=0;
	while(!q.empty()){
		node tmp=q.top();q.pop();
		int x=tmp.now;
		if(vis[x])	continue;
//		cout<<x/C+1<<' '<<x%C<<' '<<dis[x]<<endl;
		vis[x]=1;
		for(register int i=head[x];i;i=Edge[i].nxt){
			int v=Edge[i].to;
//			cout<<v/C+1<<' '<<x%C<<" to\n";
			double w=Edge[i].dis;
			if(w==-1)	w=W;
			if(dis[x]+w<dis[v]){
				dis[v]=dis[x]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
//	cout<<W<<' '<<dis[Num(ex,ey)]<<" Dij\n";
	return dis[Num(ex,ey)];
}
inline void Solve(){
	double l=0,r=10.0,ans=0;
	while(l < r){
		double mid=(l+r)/2;
//		printf("%.7lf %.7lf %.7lf\n",l,r,mid);
		double res=dij(mid);
		if(res==L){
			ans=mid;
			break;
		}		
		if(res>L)	r=mid;
		else	l=mid;	
	}
	printf("%.5lf\n",ans);	
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout); 
	int T=read();
	while(T--){
		Init();
		Solve();
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
