#include <fstream>

using namespace std;

const int kMaxN = 2e5 + 1, kM = 1000000009;

ifstream fin("magician.in");
ofstream fout("magician.out");

int r[kMaxN], n, m, x, y, ans;

int R(int x) { return r[x] == x ? x : r[x] = R(r[x]); }

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    r[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    fin >> x >> y;
    x = R(x), y = R(y);
    if (x != y) {
      r[x] = y;
    } else {
      ans = (ans * 2 + 1) % kM;
    }
    fout << ans << '\n';
  }
  return 0;
}