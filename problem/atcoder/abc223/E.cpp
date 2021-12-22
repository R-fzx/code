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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

LL x, y, a, b, c;

bool P(LL x, LL y, LL a, LL b, LL c = 0) {
  return y > 0 && (a + y - 1) / y + (b + y - 1) / y + (c + y - 1) / y <= x;
}
bool C(LL x, LL y) {
  return P(x, y, a, b, c) || P(y, x - (a + y - 1) / y, b, c) || P(y, x - (b + y - 1) / y, a, c) || P(y, x - (c + y - 1) / y, a, b);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> x >> y >> a >> b >> c;
  cout << (C(x, y) || C(y, x) ? "Yes" : "No");
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}