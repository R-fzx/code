#include <fstream>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

ifstream fin("Castle.in");
ofstream fout("Castle.out");

const int kMaxN = 1001, kM = ~(1 << 31);

Pll l[kMaxN][kMaxN], d[kMaxN];
int b[kMaxN], n, m, x, y;
LL z, ans;

int main() {
  fin >> n >> m;
  fill(l[1], l[kMaxN], make_pair(1e16, 1));
  fill(d + 1, d + 1 + n, make_pair(1e16, 1));
  for (int i = 1; i <= m; i++) {
    fin >> x >> y >> z;
    if (z == l[x][y].first) {
      l[x][y].second++, l[y][x].second++;
    } else if (z < l[x][y].first) {
      l[x][y] = l[y][x] = {z, 1};
    }
  }
  d[1].first = 0;
  for (int i = 1; i <= n; i++) {
    int p = 0;
    for (int j = 1; j <= n; j++) {
      if (!b[j] && (!p || d[j].first < d[p].first)) {
        p = j;
      }
    }
    b[p] = 1;
    for (int j = 1; j <= n; j++) {
      if (d[p].first + l[p][j].first < d[j].first) {
        d[j] = {d[p].first + l[p][j].first, l[p][j].second};
      } else if (d[p].first + l[p][j].first == d[j].first) {
        d[j].second = (d[j].second + l[p][j].second) % kM;
      }
    }
  }
  ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * d[i].second % kM;
  }
  fout << ans;
  return 0;
}