#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

const int kN = 1e6 + 1;
const LL kM = 998244353, kG = 3, kIG = 332748118;

int n, m, rt[kN << 1];
LL f[kN << 1], g[kN << 1];

LL P(LL b, LL e = kM - 2) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    (e & 1) && (s = s * b % kM);
  }
  return s;
}
void NTT(LL *f, )

int main() {

  return 0;
}