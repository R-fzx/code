#include <iostream>
#include <queue>

using namespace std;

struct P {
  int x, y;
  bool b;
} p[2][401][401];
struct V {
  int s[2];
  bool b;
} v[401];
int n, m, r, d[2][401][401];
string s;
queue<P> q;

void Build(int &p, int x) {
  !p && (p = ++m);
  if (x < s.size()) {
    Build(v[p].s[s[x] == '1'], x + 1);
  } else {
    v[p].b = 1;
  }
}

void Update(int _x, int _y, bool _b, int x, int y, int s, bool b) {
  if (!d[b][x][y]) {
    d[b][x][y] = d[b][y][x] = s;
    p[b][x][y] = {_x, _y, _b};
    q.push({x, y, b});
  }
}

void Print(int x, int y, bool b) {
  P c = p[b][x][y];
  if (c.x || c.y || c.b) {
    Print(c.x, c.y, c.b);
  }
  if (x != 1 && y != 1) {
    cout << (v[c.x].s[1] == x);
  }
}

int main() {
  freopen("codes.in", "r", stdin);
  freopen("codes.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    Build(r, 0);
  }
  for (Update(0, 0, 0, r, r, 1, 0); !q.empty(); q.pop()) {
    P c = q.front();
    if (c.x == r && c.y == r && c.b) {
      cout << d[c.b][c.x][c.y] - 1 << '\n';
      Print(c.x, c.y, c.b);
      break;
    }
    if (v[c.x].b && v[c.y].b) {
      Update(c.x, c.y, c.b, r, r, d[c.b][c.x][c.y], c.b);
    }
    if (v[c.x].b) {
      Update(c.x, c.y, c.b, r, c.y, d[c.b][c.x][c.y], c.b);
    }
    if (v[c.y].b) {
      Update(c.x, c.y, c.b, c.x, r, d[c.b][c.x][c.y], c.b);
    }
    for (int i = 0; i < 2; i++) {
      if (v[c.x].s[i] && v[c.y].s[i]) {
        Update(c.x, c.y, c.b, v[c.x].s[i], v[c.y].s[i], d[c.b][c.x][c.y] + 1, c.b || v[c.x].s[i] != v[c.y].s[i]);
      }
    }
  }
  return 0;
}
