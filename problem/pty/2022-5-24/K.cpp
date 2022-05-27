#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

const int kN = 1e5 + 1;

int n, m, p[kN];
vector<int> e[kN], l;
bool v[kN];
char ch;

void S(int x) { l.push_back(x), p[x] ^= 1; }
void D(int x) {
  v[x] = 1, S(x);
  for (int j : e[x]) {
    if (!v[j]) {
      D(j), S(x);
      if (p[j]) {
        S(j), S(x);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> ch;
    p[i] = ch - '0';
  }
  D(1);
  if (p[1]) {
    S(e[1][0]), S(1), S(e[1][0]);
  }
  cout << l.size() << endl;
  for (int i : l) {
    cout << i << " ";
  }
  return 0;
}