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

const int kN = 1e5 + 1;

string s;
int q;
LL t, k;

int F(int x, LL t, LL k) {
  if (!t) {
    return x;
  }
  return (1LL << t - 1) < k ? F((x + 2) % 3, t - 1, k - (1LL << t - 1)) : F((x + 1) % 3, t - 1, k);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s >> q;
  s = " " + s;
  while (q--) {
    cin >> t >> k;
    int l = 1;
    for (; 1LL << l < k; ++l) {
    }
    // 1<<l >= k
    if (t > l) {
      t = l + (t - l) % 3;
    }
    int i = 1;
    for (; k > 1LL << t; k -= 1LL << t, ++i) {
    }
    cout << char(F(s[i] - 'A', t, k) + 'A') << endl;
  }
  return 0;
}
/*
A->BC
B->CA
C->AB

A
BC
CAAB
ABBCBCCA
BCCACAABCAABABBC
CAAB
*/