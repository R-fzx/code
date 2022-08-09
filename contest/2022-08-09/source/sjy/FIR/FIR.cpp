#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e3 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, map[N][N], flag, vis[N][N];

inline void dfs(int x, int y, int f) {
  if (map[x][y] != f || !flag || vis[x][y]) {
    return ;
  }

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (map[nx][ny] == 0) {
      flag = 0;
      return ;
    }
    vis[x][y] = 1;
    dfs(nx, ny, f);
    vis[x][y] = 0;
  }
  
} 

inline void ql(int x, int y, int f) {
  if (map[x][y] != f){
    return ;
  }
  
  map[x][y] = 0;
  
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    vis[x][y] = 1;
    ql(nx, ny, f);
    vis[x][y] = 0;
  }
} 

inline int qf(int x) {
  return (x == 1 ? 2 : 1);
}

inline bool can_win(int x, int y, int f) {
  int sum = -1;
  int tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    --tx, ++sum;
  }
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    ++tx, ++sum;
  }
  if (sum >= m) {
    return 1;
  }
  
  sum = -1;
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    --ty, ++sum;
  }
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    ++ty, ++sum;
  }
  if (sum >= m) {
    return 1;
  }
  
  sum = -1;
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    --ty, --tx, ++sum;
  }
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    ++ty, ++tx, ++sum;
  }
  if (sum >= m) {
    return 1;
  }
  
  sum = -1;
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    --ty, ++tx, ++sum;
  }
  tx = x, ty = y;
  for (int i = 1; i <= m; ++i) {
    if (map[tx][ty] != f) {
      break;
    }
    ++ty, --tx, ++sum;
  }
  if (sum >= m) {
    return 1;
  }

  return 0;
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  cin >> n >> m;
  
  int f = 1, t = n;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (map[x][y] != 0) {
      cout << "illegal";
      return 0;
    } 
    
    map[x][y] = f;
    
    for (int i = 0; i < 4; ++i) {
      flag = 1;
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (map[nx][ny] == qf(f)) {
        dfs(nx, ny, qf(f)); 
        if (flag) {
          ql(nx, ny, qf(f));
        }
      }
      
    }
    
    dfs(x, y, f);
    if (flag) {
      cout << "illegal";
      return 0;
    }
    
    if (can_win(x, y, f)) {
      if (f == 1) {
        cout << "ITer " << n - t;
      } else {
        cout << "Kitty " << n - t; 
      }
      return 0;
    }
    
    f = qf(f);
    
//    for (int i = 1; i <= 10; ++i) {
//      for (int j = 1; j <= 10; ++j) {
//        cout << map[i][j];
//      }
//      cout << '\n';
//    }
  }
  
  cout << "draw";
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
1 5 */
