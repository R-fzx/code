#include<bits/stdc++.h>
#define printen(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int m,n,X,mp[1009][1009],vis[1009][1009];
bool check_win(int x,int y){int cnt=0;
	for(int i=max(1,x-X+1);i<=x+X-1;i++){
		if(mp[i][y]==mp[x][y])cnt++;
		if(cnt==X)return 1;
		if(mp[i][y]!=mp[x][y])cnt=0;
	}cnt=0;
	for(int i=max(1,y-X+1);i<=y+X-1;i++){
		if(mp[x][i]==mp[x][y])cnt++;
		if(cnt==X)return 1;
		if(mp[x][i]!=mp[x][y])cnt=0;
	}int tmp=x-y;cnt=0;
	for(int i=max(1,x-X+1);i<=x+X-1;i++){
		if(mp[i][i-tmp]==mp[x][y])cnt++;
		if(cnt==X)return 1;
		if(mp[i][i-tmp]!=mp[x][y])cnt=0;
	}tmp=x+y,cnt=0;
	for(int i=max(1,x-X+1);i<=x+X-1;i++){
		if(mp[i][tmp-i]==mp[x][y])cnt++;
		if(cnt==X)return 1;
		if(mp[i][tmp-i]!=mp[x][y])cnt=0;
	}
	return 0;
}
int cnt,cx[5]={0,1,0,-1,0},cy[5]={0,0,1,0,-1};pair<int,int>del[1000009];bool b;
void do_fuck_son(int x,int y){
	vis[x][y]=1;del[++cnt]=(pair<int,int>){x,y};
	for(int i=1;i<=4;i++){
		int dx=x+cx[i],dy=y+cy[i];
		if(vis[dx][dy]||(mp[dx][dy]!=mp[x][y]&&mp[dx][dy]!=0))continue;
		if(mp[dx][dy]==0){b=1;return;}
		do_fuck_son(dx,dy);vis[dx][dy]=0;if(b==1)return;
	}
}
void check_eat(int x,int y){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=cnt;j++)del[j].first=del[j].second=0;
		memset(vis,0,sizeof(vis));b=0,cnt=0;
		if(mp[x+cx[i]][y+cy[i]]!=mp[x][y]&&mp[x+cx[i]][y+cy[i]]!=0)do_fuck_son(x+cx[i],y+cy[i]);
		if(!b)for(int j=1;j<=cnt;j++)mp[del[j].first][del[j].second]=0;
	}
	memset(vis,0,sizeof(vis));for(int i=1;i<=cnt;i++)del[i].first=del[i].second=0;
	b=0,cnt=0;do_fuck_son(x,y);if(!b)for(int i=1;i<=cnt;i++)mp[del[i].first][del[i].second]=0;
}
int main(){
	freopen("FIR.in","r",stdin);freopen("FIR.out","w",stdout);
	n=read(),X=read();m=n;
	while(n--){
		int x=read(),y=read();
		if(mp[x][y]){puts("illegal");return 0;}mp[x][y]=(n&1)?1:2;
		if(check_win(x,y)){printf((n&1)?"ITer ":"Kitty ");print(m-n);return 0;}
		check_eat(x,y);if(mp[x][y]==0){puts("illegal");return 0;}
	}puts("draw");
	return 0;
}
