#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, q, sum;
int a[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool mp[N][N];
bool vis[N][N];

struct Node {
  int x, y;
} s[N];

void F1(int x, int y, int t) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && ny <= 1000 && ny >= 1 && ny <= 1000 && !vis[nx][ny]) {
      if (a[nx][ny] == t && a[nx][ny] > 0) {
        vis[nx][ny] = 1;
        F1(nx, ny, t);
      } else {
        if (!a[nx][ny]) {
          sum++;
        }
      }
    }
  }
}

void F2(int x, int y, int t) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && ny <= 1000 && ny >= 1 && ny <= 1000 && a[nx][ny] && a[nx][ny] == t) {
      a[nx][ny] = 0;
      mp[nx][ny] = 0;
      vis[nx][ny] = 0;
      F2(nx, ny, t);
    }
  }
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].x >> s[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      vis[s[j].x][s[j].y] = 0;
    }
    if (i & 1) {
      a[s[i].x][s[i].y] = 1;
      for (int j = 1; j < i; j++) {
        if (!(a[s[j].x][s[j].y] & 1) && !vis[s[j].x][s[j].y]) {
          sum = 0;
          vis[s[j].x][s[j].y] = 1;
          F1(s[j].x, s[j].y, a[s[j].x][s[j].y]);
          if (!sum) {
            int l = a[s[j].x][s[j].y];
            a[s[j].x][s[j].y] = 0;
            mp[s[j].x][s[j].y] = 0;
            vis[s[j].x][s[j].y] = 0;
            F2(s[j].x, s[j].y, l);
          }
        }
      }
      sum = 0;
      F1(s[i].x, s[i].y, a[s[i].x][s[i].y]);
      if (!sum || mp[s[i].x][s[i].y]) {
        cout << "illegal" << endl;
        return 0;
      }
      mp[s[i].x][s[i].y] = 1;
      for (int j = 1; j <= i; j++) {
        if (!(a[s[j].x][s[j].y] & 1)) {
          continue;
        }
        sum = 0;
        for (int k = s[j].y; k <= s[j].y + q - 1; k++) {
          if (k < 1 || k > 1000) {
            break;
          }
          if (a[s[i].x][k] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "ITer " << i;
          return 0;
        }
        sum = 0;
        for (int k = s[j].x; k >= s[j].x - q + 1; k--) {
          if (k < 1 || k > 1000) {
            break;
          }
          if (a[k][s[i].y] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "ITer " << i;
          return 0;
        }
        sum = 0;
        for (int e = s[j].x, r = s[j].y; e >= s[j].x - q + 1 && r >= s[j].y - q + 1; e--, r--) {
          if (e < 1 || e > 1000 || r < 1 || r > 1000) {
            break;
          }
          if (a[e][r] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "ITer " << i;
          return 0;
        }
        sum = 0;
        for (int e = s[j].x, r = s[j].y; e <= s[j].x + q - 1 && r >= s[j].y - q + 1; e++, r--) {
          if (e < 1 || e > 1000 || r < 1 || r > 1000) {
            break;
          }
          if (a[e][r] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "ITer " << i;
          return 0;
        }
      }
    } else {
      a[s[i].x][s[i].y] = 2;
      for (int j = 1; j < i; j++) {
        if ((a[s[j].x][s[j].y] & 1) && !vis[s[j].x][s[j].y]) {
          sum = 0;
          vis[s[j].x][s[j].y] = 1;
          F1(s[j].x, s[j].y, a[s[j].x][s[j].y]);
          if (!sum) {
            int l = a[s[j].x][s[j].y];
            a[s[j].x][s[j].y] = 0;
            mp[s[j].x][s[j].y] = 0;
            vis[s[j].x][s[j].y] = 0;
            F2(s[j].x, s[j].y, l);
          }
        }
      }
      sum = 0;
      F1(s[i].x, s[i].y, a[s[i].x][s[i].y]);
      if (!sum || mp[s[i].x][s[i].y]) {
        cout << "illegal" << endl;
        return 0;
      }
      mp[s[i].x][s[i].y] = 1;
      for (int j = 1; j <= i; j++) {
        if ((a[s[j].x][s[j].y]) & 1) {
          continue;
        }
        sum = 0;
        for (int k = s[j].y; k <= s[j].y + q - 1; k++) {
          if (k < 1 || k > 1000) {
            break;
          }
          if (a[s[i].x][k] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "Kitty " << i;
          return 0;
        }
        sum = 0;
        for (int k = s[j].x; k >= s[j].x - q + 1; k--) {
          if (k < 1 || k > 1000) {
            break;
          }
          if (a[k][s[i].y] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "Kitty " << i;
          return 0;
        }
        sum = 0;
        for (int e = s[j].x, r = s[j].y; e >= s[j].x - q + 1 && r >= s[j].y - q + 1; e--, r--) {
          if (e < 1 || e > 1000 || r < 1 || r > 1000) {
            break;
          }
          if (a[e][r] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "Kitty " << i;
          return 0;
        }
        sum = 0;
        for (int e = s[j].x, r = s[j].y; e <= s[j].x + q - 1 && r >= s[j].y - q + 1; e++, r--) {
          if (e < 1 || e > 1000 || r < 1 || r > 1000) {
            break;
          }
          if (a[e][r] == a[s[i].x][s[i].y]) {
            sum++;
          }
        }
        if (sum == q) {
          cout << "Kitty " << i;
          return 0;
        }
      }
    }
  }
  cout << "draw";
  return 0;
}