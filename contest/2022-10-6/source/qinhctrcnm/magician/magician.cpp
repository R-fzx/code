#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

ifstream fin("magician.in");
ofstream fout("magician.out");

const int kMaxN = 2e5 + 1;
const int kM = 1e9 + 9;

int n, m;
int fa[kMaxN];
ll ans;

int find_fa(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find_fa(fa[x]);
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    fin >> x >> y;
    if (find_fa(x) == find_fa(y)) {
      ans = (ans * 2 + 1) % kM;
    } else {
      fa[find_fa(y)] = find_fa(x);
    }
    fout << ans << '\n';
  }
  return 0;
}