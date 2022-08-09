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
const int N=2e3+5,M=1e4+5;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct node{
	int x,y;
}erase1[M],erase2[M],erase3[M];
bool vis[N][N],used[N][N],flag[N][N];
int mp[N][N];
int T,W,del1,del3;
inline bool check_eat(int x,int y){
	if(vis[x][y])	return 0;
	queue<node> q;
	q.push((node){x,y});
	int ans=0,del2=0;
	erase2[++del2]=(node){x,y};
	while(!q.empty()){
		node tmp=q.front();q.pop();
		int X=tmp.x,Y=tmp.y;vis[X][Y]=1;
		for(register int i=0;i<4;++i){
			int xx=X+dx[i],yy=Y+dy[i];
			if(mp[xx][yy]==0)	ans=1;
			else	if(mp[xx][yy]==mp[x][y] && !vis[xx][yy])
						q.push((node){xx,yy}),erase2[++del2]=(node){xx,yy};			
		}
	}
	for(register int i=1;i<=del2;++i){
		int xx=erase2[i].x,yy=erase2[i].y;
		if(!ans)	mp[xx][yy]=0;
		erase3[++del3]=(node){xx,yy};
	}
	return ans;
}
inline bool check_ill(int x,int y){
	queue<node> q;
	q.push((node){x,y});
	int ans=0;
	del1=0,del3=0;
	erase1[++del1]=(node){x,y};
	while(!q.empty()){
		node tmp=q.front();q.pop();
		int X=tmp.x,Y=tmp.y;used[X][Y]=1;
		for(register int i=0;i<4;++i){
			int xx=X+dx[i],yy=Y+dy[i];
			if(mp[xx][yy]==0)	ans=1;
			else	if(mp[xx][yy]==mp[x][y] && !used[xx][yy])
				q.push((node){xx,yy}),erase1[++del1]=(node){xx,yy};
			else{
				if(mp[xx][yy]!=mp[x][y])
					if(!check_eat(xx,yy))	ans=1;		
			}
		}		
	}
	for(register int i=1;i<=del1;++i){
		int X=erase1[i].x,Y=erase1[i].y;
		used[X][Y]=0;
	}	
	for(register int i=1;i<=del3;++i){
		int xx=erase3[i].x,yy=erase3[i].y;
		vis[xx][yy]=0;
	}
	return ans;
}
inline bool check_win(int x,int y){
	int res1=0,res2=0;
	for(register int i=x+1;i<x+W;++i)
		if(mp[i][y]==mp[x][y])	res1++;
		else	break;
	for(register int i=x-1;i>=x-W+1 && i;--i)
		if(mp[i][y]==mp[x][y])	res2++;
		else	break;
	if(res1+res2+1>=W)	return 1;
//	cout<<"one\n";
	res1=0,res2=0;
	for(register int i=y+1;i<y+W;++i)
		if(mp[x][i]==mp[x][y])	res1++;
		else	break;
	for(register int i=y-1;i>=y-W+1 && i;--i)
		if(mp[x][i]==mp[x][y])	res2++;
		else	break;
//	cout<<res1<<' '<<res2<<endl;
	if(res1+res2+1>=W)	return 1;
	res1=0,res2=0;
	for(register int i=1;i<W && min(x-i,y-i)>0;++i)
		if(mp[x-i][y-i]==mp[x][y])	res1++;
		else	break;
	for(register int i=1;i<W;++i)
		if(mp[x+i][y+i]==mp[x][y])	res2++;
		else	break;
	if(res1+res2+1>=W)	return 1;
	res1=0,res2=0;
	for(register int i=1;i<W && x-i>0;++i)
		if(mp[x-i][y+i]==mp[x][y])	res1++;
		else	break;
	for(register int i=1;i<W && y-i>0;++i)
		if(mp[x+i][y-i]==mp[x][y])	res2++;
		else	break;
	if(res1+res2+1>=W)	return 1;
	return 0;
}
#define illegal {puts("illegal");return 0;}
#define Win(rd) {cout<<((rd&1)?"Iter ":"Kitty ")<<rd;return 0;}
signed main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	T=read(),W=read();
	for(register int rd=1;rd<=T;++rd){
		int x=read(),y=read();
//		cout<<"OK\n";
		if(mp[x][y])	illegal;
//		cout<<"first\n";
		mp[x][y]=2-(rd&1);
		if(!check_ill(x,y))	illegal;
//		cout<<"second\n";
		if(check_win(x,y))	Win(rd);
//		cout<<"third\n";
//		for(register int i=1;i<=11;++i){
//			for(register int j=1;j<=11;++j)
//				cout<<mp[i][j]<<' ';cout<<endl;
//		}
	}
	puts("draw");
    return 0;
}


