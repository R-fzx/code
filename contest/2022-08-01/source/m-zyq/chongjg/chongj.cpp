#include<bits/stdc++.h>

using namespace std;
const int tx[2]={0,-1},ty[4]={1,0};
int n,m,a[109][109];
inline int read(){
	int r(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	return r;
}
inline int f(int x,int y){
	int i(0);
	for(;i<y&&a[x][y]==a[x][y-i];)i++;
	return i;
}
inline void fl(int x,int y,int d,int c){
	for(int i(x);i<=x+d;i++)for(int j(y);j<=y+d;j++)a[i][j]=c;
}
inline void work(){
	for(int i(1);i<=n;i++){
		for(int j(1);j<=m;j++){
			if(a[i][j])continue;
			bool b[5]={0};
			for(int k(0);k<2;k++)b[a[i+tx[k]][j+ty[k]]]=true;
			for(int k(1);k<5;k++){
				if(b[k])continue;
				if(k==a[i][j-1]){
					if(k==a[i-1][j-1])continue;
					int cur(f(i,j-1));
					if(cur+i<=n){
						fl(i,j-cur,cur,k);	
						break;
					} 
				}else{
					a[i][j]=k;
					break;
				}
			}
		}
	}
}
signed main(){
	freopen("chongjg.in","r",stdin),freopen("chongjg.out","w",stdout);
	n=read(),m=read();
	work();
	for(int x(1);x<=n;x++){
		for(int y(1);y<=m;y++){
			putchar((char)('A'+a[x][y])-1); 
		}puts(""); 
	}
	return 0;
}

