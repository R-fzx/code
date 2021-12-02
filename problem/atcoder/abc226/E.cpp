#include <iostream>
#include <vector>

using namespace std;

const int kN = 2e5 + 1, kM = 998244353;

int n, m, c = 1, _c[2];
vector<int> e[kN];
bool v[kN];

void S(int x) {
  if (v[x]) return;
  v[x] = 1, ++_c[0];
  for (int i : e[x]) ++_c[1], S(i);
}

int main() {
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (!v[i]) _c[0] = _c[1] = 0, S(i), c = 1LL * c * ((_c[0] << 1 == _c[1]) << 1) % kM;
  cout << c;
  return 0;
}