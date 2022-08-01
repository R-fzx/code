#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
int n,m;
int ans[maxn][maxn];
void getans(int l,int w,int x,int y){
	int t=min(l,w),c;
	for(int i=0;i<26;i++)
		if(i!=ans[x-1][y]&&i!=ans[x][y-1]){
			c=i;
			break;
		}
	for(int i=x;i<x+t;i++)
		for(int j=y;j<y+t;j++)
			ans[i][j]=c;
	if(l==w)return;
	if(l<w)getans(l,w-l,x,y+l);
	else if(l>w)getans(l-w,w,x+w,y);
}
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	memset(ans,-1,sizeof(ans));
	scanf("%d%d",&n,&m);
	getans(n,m,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c=(char)ans[i][j]+'A';
			cout<<c;
		}
		printf("\n");
	}
	return 0;
} 
