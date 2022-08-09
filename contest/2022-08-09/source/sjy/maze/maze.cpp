#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <cstdio>
#include <time.h>
#define ll long long

using namespace std;

const int N = 25;
const int M = 1e5 + 5;
const int dx[] = {1, 0};
const int dy[] = {0, 1};

ll n, m, a[N][N], ans, f, dp[N][N][M];

inline void dep() {
  dp[1][1][a[1][1]] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 10000; k >= 0; --k) {
        dp[i + 1][j][k xor a[i + 1][j]] += dp[i][j][k];
        dp[i][j + 1][k xor a[i][j + 1]] += dp[i][j][k];
      }
    }
  }
  
  cout << dp[n][m][f] << '\n';
} 

inline void dfs(int x, int y, ll sum) {
  if (x > n || y > m || a[x][y] == 0) {
    return ;
  }
  
  if (x == n && y == m) {
    ans += (sum == f);
  }  
  
  for (int i = 0; i <= 1; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    dfs(x + dx[i], y + dy[i], sum xor a[nx][ny]);
  }
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> f;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  
  dfs(1, 1, a[1][1]);
  
  dep();
  return 0;
}
