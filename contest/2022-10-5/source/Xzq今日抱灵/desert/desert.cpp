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
struct edge{
	int to,val;
	edge(int t,int v){to=t;val=v;}
};
struct node{
	int num,dis;
	node(int nm,int d){num=nm;dis=d;}
};
int n,cnt=INT_MAX,ans,tot,totg,gl[59*59],bx,by,nm[59][59],vis[59*59],dis[59*59];
int fx[9]={0,1,0,-1,0,1,1,-1,-1};
int fy[9]={0,0,1,0,-1,1,-1,-1,1};
char mp[59][59];
vector<edge>e[59*59];
priority_queue<node>q;
bool operator<(node x,node y){return x.dis>y.dis;}
int Dij(int wd){
	memset(dis,0x7f,sizeof(dis));
	memset(gl,0,sizeof(gl));
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	for(int i=1;i<=tot;i++)e[i].clear();
	tot=0,totg=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='X')continue;
			nm[i][j]=++tot;
			if(mp[i][j]=='*')gl[++totg]=tot;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='X')continue;
			for(int k=1;k<=8;k++){
				int dx=i+fx[k],dy=j+fy[k];
				if(mp[dx][dy]=='X'||dx<=0||dy<=0||dx>n||dy>n)continue;
				if(k==wd)e[nm[i][j]].push_back(edge(nm[dx][dy],3));
				else e[nm[i][j]].push_back(edge(nm[dx][dy],1));
			}
		}
	dis[nm[bx][by]]=0;
	q.push(node(nm[bx][by],0));
	for(int i=1;i<=tot;i++){
		int x;
		while(!q.empty()&&vis[q.top().num])q.pop();
		if(q.empty())break;
		x=q.top().num;
		vis[x]=1;q.pop();
		for(int j=0;j<e[x].size();j++){
			int y=e[x][j].to,v=e[x][j].val;
			if(dis[y]>dis[x]+v){
				dis[y]=dis[x]+v;
				q.push(node(y,dis[y]));
			}
		}
	}
	int ikun=0x7f7f7f7f;
	for(int i=1;i<=totg;i++)ikun=min(ikun,dis[gl[i]]);
	return ikun;
}
signed main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='@')bx=i,by=j;
		}
	for(int i=1;i<=8;i++){
		cnt=Dij(i);
		if(cnt==0x7f7f7f7f){puts("-1");return 0;}
		ans=max(ans,cnt);
	}
	print(ans);
	return 0;
}
/*
3
- - *
@ - *
X - - 
*/
