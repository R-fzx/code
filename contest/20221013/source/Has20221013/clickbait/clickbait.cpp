// #pragma GCC optimize("Ofast")
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1001, D[3][2] = {{0, -1}, {1, 0}, {0, 1}};

struct S {
  int x1, y1, x2, y2, num;
  vector<int> e;
} v[N * N / 5];

char c[N][N];
int n, m, cnt;

void ZX(int f, int x1, int y1);

void ZB(int f, int x, int y, int fx) {
  while (1) {
    x = x + D[fx][0], y = y + D[fx][1];
    if (c[x][y] == '+') {
      if (fx != 1) {
        fx = 1;
      } else {
        if (y + 1 < m && c[x][y + 1] == '-') {
          fx = 2;
        } else {
          fx = 1;
        }
      }
    } else if (fx == 1 && c[x][y] == '-') {
      for (; c[x][y] == '-'; --x) {
      }
      ++x;
      ZX(f, x, y);
    }
  }
}

void ZX(int f, int x1, int y1) {
  int i, j;
  for (j = y1 + 1; c[x1][j] == '-' && j <= m; ++j) {
  }
  for (i = x1 + 1; c[i][y1] == '|' && i <= n; ++i) {
  }
  if (c[i][j] == '+' && c[x1][j] == '+' && c[i][y1] == '+') {
    int s = ++cnt;
    v[s].x1 = x1, v[s].x2 = i, v[s].y1 = y1, v[s].y2 = j;
    for (int i = v[s].x1; i <= v[s].x2; ++i) {
      for (int j = v[s].y1; j <= v[s].y2; ++j) {
        if (c[i][j] >= '0' && c[i][j] <= '9') {
          int num = 0;
          for (int k = j; c[i][k] >= '0' && c[i][k] <= '9'; ++k) {
            num = num * 10 + c[i][k] - '0';
          }
          v[s].num = num;
          if (f) {
            v[f].e.push_back(s);
          }
          break;
        }
      }
    }
    for (int i = v[s].x2; i >= v[s].x1; --i) {
      if (v[s].y1 > 1 && c[i][v[s].y1 - 1] == '-') {
        ZB(s, i, v[s].y1 - 1, 0);
      }
      if (v[s].y2 < m && c[i][v[s].y2 + 1] == '-') {
        ZB(s, i, v[s].y2 + 1, 2);
      }
    }
  }
}

void Dfs(int x) {
  for (auto i : v[x].e) {
    Dfs(i);
  }
  cout << v[x].num << '\n';
}

int main() {
  freopen("clickbait.in", "r", stdin);
  freopen("clickbait.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (c[i][j] == '+') {
        ZX(0, i, j);
        break;
      }
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    if (v[i].num == 1) {
      Dfs(i);
    }
  }
  return 0;
}