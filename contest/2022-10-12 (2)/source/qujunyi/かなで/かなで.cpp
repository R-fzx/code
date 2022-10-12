#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool b[10][10];
bool bb[10][10];
bool bbb[10];
bool a[10][10]; 
int sum = 0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void Dfs(int x,int y){
	bb[x][y]=1;
	for(int i = 0;i < 4;i++){
		int fx = x+dx[i];
		int fy = y+dy[i];
		if(b[fx][fy]==1&&bb[fx][fy]==0){
			Dfs(fx,fy);
		}
	}
}
void dfs(int x,int y, int k) {
  if (y == m + 1) {
    if(x==n){
      if(k!=0){
        return;
      }
      int xx,yy;
    	for(int i = 0;i <= 9;i++){
    		for(int j = 0;j <=9;j++){
    			bb[i][j]=0;
    			if(b[i][j]==1){
    				xx=i,yy= j;
				}
			}
		}
		Dfs(xx,yy);
    	for(int i = 0;i <= 9;i++){
    		for(int j = 0;j <=9;j++){
    			if(b[i][j]==1&&bb[i][j]==0){
    				return;
				}
			}
		}
      return;
    }
    dfs(x+1,1,k);
    return;
  }
  if (k > 0&&a[x][y]==1) {
    b[x][y] = 1;
    //cout << y << " "<< bb[y]<< endl;
    dfs(x,y + 1, k - 1);
  }
  //cout << y <<" "<< bb[1]<< endl;
  b[x][y] = 0;
  dfs(x,y + 1, k);
}
int main() {
	freopen("かなで.in","r",stdin);
	freopen("かなで.out","w",stdout);
  cin >> n >> m >> k;
  for(int i = 1;i <= n;i++){
  	for(int j = 1;j <= m;j++){
  		char c;
  		cin >> c;
  		a[i][j]=c-'0';
	  }
  }
  dfs(1,1, k);
  cout << sum;
  return 0;
}
