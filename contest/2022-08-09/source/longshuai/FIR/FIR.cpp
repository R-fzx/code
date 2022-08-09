#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,k;
int g[maxn][maxn];
bool check_illegal(int x,int y){
	if(g[x][y]==-1)return 1;
	bool b=false;
	int tmp=g[x][y];
	g[x][y]=1-g[x][y];
	if(g[x-1][y]!=1-tmp)b|=check_illegal(x-1,y);
	if(g[x+1][y]!=1-tmp)b|=check_illegal(x+1,y);
	if(g[x][y-1]!=1-tmp)b|=check_illegal(x,y-1);
	if(g[x][y+1]!=1-tmp)b|=check_illegal(x,y+1);
	g[x][y]=tmp;
	return b;
}
void delet(int x,int y,int op){
	g[x][y]=-1;
	if(g[x-1][y]==op)delet(x-1,y,op);
	if(g[x+1][y]==op)delet(x+1,y,op);
	if(g[x][y-1]==op)delet(x,y-1,op);
	if(g[x][y+1]==op)delet(x,y+1,op);
}
bool eat(int x,int y){
	if(g[x-1][y]==1-g[x][y])
		if(!check_illegal(x-1,y)){
			delet(x-1,y,1-g[x][y]);
			return 1;
		}
	if(g[x+1][y]==1-g[x][y])
		if(!check_illegal(x+1,y)){
			delet(x+1,y,1-g[x][y]);
			return 1;
		}
	if(g[x][y-1]==1-g[x][y])
		if(!check_illegal(x,y-1)){
			delet(x,y-1,1-g[x][y]);
			return 1;
		}
	if(g[x][y+1]==1-g[x][y])
		if(!check_illegal(x,y+1)){
			delet(x,y+1,1-g[x][y]);
			return 1;
		}
	return 0;
}
bool win(int x,int y,int op){
	int t=1,stx=x,sty=y;
	while(g[stx-1][y]==op)t++,stx--;
	stx=x;
	while(g[stx+1][y]==op)t++,stx++;
	if(t>=k)return 1;
	t=1;
	while(g[x][sty-1]==op)t++,sty--;
	sty=y;
	while(g[x][sty+1]==op)t++,sty++;
	if(t>=k)return 1;
	t=1;stx=x;sty=y;
	while(g[stx-1][sty-1]==op)t++,stx--,sty--;
	stx=x;sty=y;
	while(g[stx+1][sty+1]==op)t++,stx++,sty++;
	if(t>=k)return 1;
	t=1;stx=x;sty=y;
	while(g[stx+1][sty-1]==op)t++,stx++,sty--;
	stx=x;sty=y;
	while(g[stx-1][sty+1]==op)t++,stx--,sty++;
	if(t>=k)return 1;
	return 0;
} 
int main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(g,-1,sizeof(g));
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(g[x][y]!=-1){
			printf("illegal\n");
			return 0;
		}
		g[x][y]=i%2;
		if(eat(x,y));
		else if(!check_illegal(x,y)){
			printf("illegal\n");
			return 0;
		}
		if(win(x,y,g[x][y])){
			if(i%2!=0)printf("ITer %d\n",i);
			else printf("Kitty %d\n",i);
			return 0;
		}
//		for(int i=1;i<=10;i++){
//			for(int j=1;j<=10;j++)
//				cout<<g[i][j]<<'\t';
//			cout<<endl;
//		}
	}
	printf("draw\n");
	return 0;
}
/*
20 5 
2 3 
3 3 
3 2 
2 2 
4 3
2 4 
5 3 
1 3 
3 4 
5 5 
2 3 
3 3 
2 3 
2 5 
6 3 
1 5 
3 3 
1 5 
1 5 
1 5
*/
