#include<bits/stdc++.h>
using namespace std;
long long dp[21][21][17000];
int main(){
  freopen("maze.in","r",stdin);
  freopen("maze.out","w",stdout);
  int n,m,q;
  cin >> n >> m >> q;
  dp[1][0][0] = 1;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      int x;
      cin >> x;
      if(x!=0){
        for(int k = 0;k<= 17003;k++){
          dp[i][j][k^x]= dp[i-1][j][k]+dp[i][j-1][k];
        }
      }
    }
  }
  cout << dp[n][m][q];
}
  