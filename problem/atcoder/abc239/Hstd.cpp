#include <iostream>
#include <unordered_map>

using namespace std;
using LL = long long;

const int kM = 1e9 + 7;

unordered_map<int, int> f;
int wn, w, n, m;

LL W(LL w) {
  LL r = 1;
  for (int i = 1; i <= kM - 2; i <<= 1) {
    if ((kM - 2) & i) {
      r = r * w % kM;
    }
    w = w * w % kM;
  }
  return r;
}

int C(int m) {
  if (f.count(m)) {
    return f[m];
  }
  LL r = 0;
  for (int i = 2, j; i <= min(m, n); i = j + 1) {
    j = min(n, m / (m / i));
    r = (r + LL(j - i + 1) * C(m / i)) % kM;
  }
  r = (r * wn + 1) % kM * w % kM;
  return f[m] = r;
}

int main() {
  cin >> n >> m;
  wn = W(n), w = n * W(n - 1) % kM;
  cout << C(m);
  return 0;
}