#include <iostream>
#include <queue>

using namespace std;

const int kInf = 1e9, kMove[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
struct A {
  int x, y, d;
  bool operator<(const A &a) const { return d > a.d; };
} c;
int n, sx, sy, ans, d[51][51];
char ch[51][51];
priority_queue<A> q;

void Update(int x, int y, int z) {
  if (x >= 1 && y >= 1 && x <= n && y <= n && ch[x][y] != 'X' && z < d[x][y]) {
    d[x][y] = z;
    q.push({x, y, z});
  }
}

int main() {
  freopen("desert.in", "r", stdin);
  freopen("desert.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> ch[i][j];
      if (ch[i][j] == '@') {
        sx = i, sy = j;
      }
    }
  }
  for (int i = 0, mn; i < 8; i++) {
    mn = kInf, fill(&d[0][0], &d[50][50] + 1, kInf);
    for (Update(sx, sy, 0); !q.empty();) {
      c = q.top(), q.pop();
      for (int j = 0; j < 8; j++) {
        Update(c.x + kMove[j][0], c.y + kMove[j][1], c.d + (i == j ? 3 : 1));
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (ch[j][k] == '*') {
          mn = min(mn, d[j][k]);
        }
      }
    }
    ans = max(ans, mn);
  }
  cout << ans;
  return 0;
}
