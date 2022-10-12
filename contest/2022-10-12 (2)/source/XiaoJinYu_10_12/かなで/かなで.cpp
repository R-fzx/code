#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

bool a[MAXN][MAXN];
bool f[MAXN][MAXN];
int n, m, k, nm;
set<unsigned long long> anss;

unsigned long long fuck() { //¾­?Áü°Ü?»êº¸¾å³ÑÖõ??
  bool b[MAXN][MAXN];
  int minx = 114514, miny = 114514;
  unsigned long long x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j]) {
        if (minx > i) minx = i;
        if (miny > j) miny = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      b[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j]) {
        b[i - minx][j - miny] = 1;
      }
    }
  }
  x = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j]) {
        x += 1 << (i * nm + j);
      }
    }
  }
  return x;
}

unsigned long long fucku(unsigned long long x) { //¾­?Áü²ò?Öõ°Ü?»êº¸¾å³ÑºÆ??
  bool b[MAXN][MAXN], c[MAXN][MAXN];
  int minx = 114514, miny = 114514;
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      c[i][j] = x & 1;
      x >>= 1;
    }
  }
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      if (c[i][j]) {
        if (minx > i) minx = i;
        if (miny > j) miny = j;
      }
    }
  }
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      b[i][j] = 0;
    }
  }
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      if (c[i][j]) {
        b[i - minx][j - miny] = 1;
      }
    }
  }
  x = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j]) {
        x += 1 << (i * nm + j);
      }
    }
  }
  return x;
}

unsigned long long fz(unsigned long long x) {//ËÝ?
  bool c[MAXN][MAXN];
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      c[i][j] = x & 1;
      x >>= 1;
    }
  }
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j * 2 < nm; ++j) {
      swap(c[i][j], c[i][m - j - 1]);
    }
  }
  x = 0;
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      if (c[i][j]) {
        x += 1 << (i * nm + j);
      }
    }
  }
  return fucku(x);
}

unsigned long long xz(unsigned long long x) { //Àû?90ÅÙ
  bool c[MAXN][MAXN], d[MAXN][MAXN];
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      c[i][j] = x & 1;
      x >>= 1;
    }
  }
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      d[i][j] = c[j][i];
    }
  }
  x = 0;
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      if (d[i][j]) {
        x += 1 << (i * nm + j);
      }
    }
  }
  return fucku(x);
}

bool ck(unsigned long long &x) {
  return anss.find(x) != anss.end();
}

bool check(unsigned long long &x) {
  unsigned long long x1 = x, x2 = xz(x), x3 = xz(xz(x)), x4 = xz(xz(xz(x)));
  if (ck(x1) || ck(x2) || ck(x3) || ck(x4)) {
    return 0;
  }
  x1 = fz(x1), x2 = fz(x2), x3 = fz(x3), x4 = fz(x4);
  if (ck(x1) || ck(x2) || ck(x3) || ck(x4)) {
    return 0;
  }
  return 1;
}

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool check2(int x, int y) {
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx > -1 && ny > -1 && nx < n && ny < m && f[nx][ny]) {
      return 1;
    }
  }
  return 0;
}

void dfs(int y) {
  if (y == k) {
    unsigned long long x = fuck();
    if (check(x)) {
      anss.insert(x);
    }
    return;
  }
  ++y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] && !f[i][j] && check2(i, j)) {
        f[i][j] = 1;
        dfs(y);
        f[i][j] = 0;
      }
    }
  }
}

void wcnm(unsigned long long x) {
  bool aa;
  for (int i = 0; i < nm; ++i) {
    for (int j = 0; j < nm; ++j) {
      aa = x & 1;
      x >>= 1;
      cout << aa << ' ';
    }
    putchar(10);
  }
  putchar(10);
}

int main() {
  freopen("¤«¤Ê¤Ç.in", "r", stdin);
  freopen("¤«¤Ê¤Ç.out", "w", stdout);
  int c;
  cin >> n >> m >> k;
  nm = n > m ? n : m;
  c = getchar();
  for (int i = 0; i < n; ++i) {  
    while(c < 48 || c > 49) c = getchar();
    for (int j = 0; j < m; ++j) {
      a[i][j] = c == 49;
      c = getchar();
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        f[i][j] = 1;
        dfs(1);
        f[i][j] = 0;
      }
    }
  }
  cout << anss.size();
  // for (auto x : anss) {
  //   wcnm(x);
  //   cout << x << '\n';
  // }
  return 0;
}