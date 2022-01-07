#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const LL kN = 1e6 + 1, kM = 998244353;

LL x, y, f[kN] = {1}, vf[kN] = {1};

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    (e & 1) && (s = s * b % kM);
  }
  return s;
}
LL F(LL x, LL y) {
  if (x < y) {
    return 0;
  }
  if (x == y) {
    return y;
  }
  LL s = 1;
  for (LL i = 2; i <= y; ++i) {
    s = s * P(i, f[x - i - 1] * vf[y - i] % kM * vf[x - y - 1] % kM) % kM;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    vf[i] = P(f[i] = f[i - 1] * i % kM, kM - 2);
  }
  for (int _ = 1; _ <= 20; ++_) {
    ifstream in("data/" + to_string(_) + ".in");
    ofstream out("data/" + to_string(_) + ".out");
    in >> x >> y;
    out << F(x, y);
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
F_0(x,y)=
*/