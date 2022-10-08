#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

int m = 18, a[10][10], x[100][3];

void check(){
  puts("!!!");
  for (int i = 1; i <= m; ++i) {
    cout << x[i][0] << ' ' << x[i][1] << ' ' << x[i][2] << endl;
  }
  exit(0);
}

void dfs(int u) {
  cout << u << endl;
  cout << "--------------" << endl;
  for (int i = 1; i <= 7; ++i) {
    for (int j = 1; j <= 7; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  if (u == m + 1) {
    check();
    return ;
  }
  for (int i = 1; i <= 7; ++i) {
    for (int j = i + 1; j <= 7; ++j) {
      for (int k = j + 1; k <= 7; ++k) {
        if (!a[i][j] || !a[j][k] || !a[i][k]) continue ;
        x[u][0] = i, x[u][1] = j, x[u][2] = k;
        // cerr << i << ' ' << j << ' ' << k << endl;
        --a[i][j], --a[j][k], --a[i][k];
        dfs(u + 1);
        ++a[i][j], ++a[j][k], ++a[i][k];
      }
    }
  }
}

int main() {
  for (int i = 1; i <= 7; ++i) {
    for (int j = i + 1; j <= 7; ++j) {
      a[i][j] = 3;
    }
  }
  a[1][6] = a[1][7] = a[2][7] = 0;
  cout << "--------------" << endl;
  for (int i = 1; i <= 7; ++i) {
    for (int j = 1; j <= 7; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  dfs(1);
  return 0;
}