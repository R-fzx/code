#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

const int kMove[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const double kEps = 1e-6, kInf = 114514191981.0;
struct A {
  int x, y;
  double z;
  bool operator<(const A &a) const { return z - a.z > kEps; }
} c;
int t, n, m, sx, sy, tx, ty;
bool a[101][101];
double k, l, r, d[101][101];
string s;
priority_queue<A> q;

void Update(int x, int y, double z) {
  if (x >= 1 && y >= 1 && x <= n && y <= m && !a[x][y] && d[x][y] - z > kEps) {
    d[x][y] = z;
    q.push({x, y, z});
  }
}

double S(double x) {
  fill(&d[0][0], &d[100][100] + 1, kInf);
  for (Update(sx, sy, 0); !q.empty();) {
    c = q.top(), q.pop();
    for (int i = 0; i < 4; i++) {
      Update(c.x + kMove[i][0], c.y + kMove[i][1], d[c.x][c.y] + (i < 2 ? 1.0 : x));
    }
  }
  return d[tx][ty];
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> k >> n >> m;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
      getline(cin, s);
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[j - 1] == '#';
        if (s[j - 1] == 'S') {
          sx = i, sy = j;
        } else if (s[j - 1] == 'E') {
          tx = i, ty = j;
        }
      }
    }
    l = 0, r = 10;
    while (abs(l - r) > kEps) {
      double mid = (l + r) / 2.0;
      if (k - S(mid) > kEps) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << fixed << setprecision(5) << l << '\n';
  }
  return 0;
}
