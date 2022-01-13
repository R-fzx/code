#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 53;

map<char, int> t;
int n, m, c[kN], l[kN][kN];
pair<char, char> e[kN * kN];
char ch[kN];
Vl ans;

void D(int x) {
  for (int i = 1; i <= n; ++i) {
    if (l[x][i]) {
      --l[x][i], --l[i][x], D(i);
    }
  }
  ans.push_back(x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    char a, b;
    cin >> a >> b;
    t[a] = 0, t[b] = 0, e[i] = {a, b};
  }
  for (auto &i : t) {
    i.second = ++n, ch[n] = i.first;
  }
  for (int i = 1; i <= m; ++i) {
    int x = t[e[i].first], y = t[e[i].second];
    ++l[x][y], ++l[y][x], ++c[x], ++c[y];
  }
  int s = 1;
  for (int i = 1; i <= n; ++i) {
    if (c[i] & 1) {
      s = i;
      break;
    }
  }
  D(s);
  if (count_if(c + 1, c + n + 1, [](int i) { return i & 1; }) > 2 || ans.size() <= m) {
    cout << "No Solution";
  } else {
    for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
      cout << ch[*i];
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}