#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;
using Pii = pair<int, int>;
const int kN = 2e5 + 5;
ifstream fin("x.in");
ofstream fout("x.out");

Pii p[kN];
int n, a, q;
int main() {
  ios ::sync_with_stdio(false);
  fin.tie(0), fout.tie(0);

  fin >> n;
  for (int i = 1, x, y; i <= n; i++) {
    fin >> x >> y;
    p[i] = {x + y, x - y};
  }
  sort(p + 1, p + n + 1);
  a = 1, q = p[1].first;
  for (int i = 2; i <= n; i++) {
    if (p[i].second > q) {
      a++;
      q = p[i].first;
    }
  }
  fout << a << '\n';
  return 0;
}