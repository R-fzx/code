#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;
using Pdii = pair<double, pair<int, int>>;

ifstream fin("maze.in");
ofstream fout("maze.out");

const int kMaxN = 101, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int a[kMaxN][kMaxN], t, n, m, sx, sy, ex, ey;
double d[kMaxN][kMaxN], limit, le, ri, mi;
char ch;

bool C() {
  fill(d[1], d[n + 1], 1e18);
  priority_queue<Pdii> h;
  for (h.push({0, {sx, sy}}); !h.empty();) {
    int x = h.top().second.first, y = h.top().second.second;
    double l = h.top().first;
    h.pop();
    if (l < d[x][y]) {
      d[x][y] = l;
      for (int i = 0; i < 4; i++) {
        int nx = x + kD[i][0], ny = y + kD[i][1];
        if (nx > 0 && ny > 0 && nx <= n && ny <= m && a[nx][ny]) {
          h.push({l + (i <= 1 ? mi : 1), {nx, ny}});
        }
      }
    }
  }
  return d[ex][ey] <= limit;
}

int main() {
  for (fin >> t; t; t--) {
    fin >> limit >> n >> m;
    for (int i = 1; i <= n; i++) {
      fin.get();
      for (int j = 1; j <= m; j++) {
        ch = fin.get();
        a[i][j] = ch != '#';
        if (ch == 'S') {
          sx = i, sy = j;
        } else if (ch == 'E') {
          ex = i, ey = j;
        }
      }
    }
    for (le = 0, ri = 10; ri - le > 1e-7;) {
      mi = (le + ri) / 2;
      if (C()) {
        le = mi;
      } else {
        ri = mi;
      }
    }
    fout << fixed << setprecision(5) << le << '\n';
  }
  return 0;
}
