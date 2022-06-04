#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 13;

LL l, r, f[kN][10], kP[kN] = {1};
vector<int> n;
vector<LL> p;

LL D(int t, int x, bool z, bool l) {  // 有多少个t，填到了第x位，有没有前导零，是不是压在顶上
  if (!x) {                           // 数位枚举完了
    return 0;
  }
  if (!l && !z && ~f[x][t]) {
    return f[x][t];
  }
  LL ans = 0;
  for (int i = 0, m = l ? n[x] : 9; i <= m; ++i) {
    if (!i && z) {
      ans += D(t, x - 1, 1, l && i == m);
    } else if (i == t && l && i == m) {
      ans += D(t, x - 1, 0, 1) + p[x - 1] + 1;
    } else if (i == t) {
      ans += D(t, x - 1, 0, 0) + kP[x - 1];
    } else {
      ans += D(t, x - 1, 0, l && i == m);
    }
  }
  if (!l && !z) {
    f[x][t] = ans;
  }
  return ans;
}
LL S(LL x, LL t) {
  fill(&f[0][0], &f[kN - 1][9] + 1, -1);
  for (n.resize(1), p.resize(1); x; x /= 10) {
    n.push_back(x % 10), p.push_back(x % 10 * kP[p.size() - 1] + p.back());
  }
  return D(t, n.size() - 1, 1, 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    kP[i] = kP[i - 1] * 10;
  }
  cin >> l >> r;
  for (int i = 0; i < 10; ++i) {
    cout << S(r, i) - S(l - 1, i) << " ";
  }
  return 0;
}
/*
len=3
n=[0,3,2,1]
p=[0,3,23,123]
*/