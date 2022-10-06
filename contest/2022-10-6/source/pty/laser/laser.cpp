#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("laser.in");
ofstream fout("laser.out");

const int kMaxN = 1e4 + 1, kMaxL = 20;

LL a[kMaxN], b[kMaxN], w[kMaxL] = {1};
int n, k;

bool F(LL v) {
  int p = lower_bound(b + 1, b + 1 + n, v) - b;
  return p <= n && a[p] <= v;
}

bool C1(int s) {
  for (int i = 1; i <= n; i++) {
    for (int v = a[i]; v <= b[i]; v++) {
      if (v / w[k] > a[i] / w[k]) {
        v += (b[i] / w[k] - v / w[k]) * w[k];
      }
      for (int j = 0; j < k; j++) {
        int p = v / w[j] % 10;
        if (s >> p & 1) {
          for (int q = 1; q <= 9; q++) {
            if ((s >> q & 1) && !F(v + (q - p) * w[j])) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

bool C2(int s) {
  bool o = b[1] / w[k] == a[1] / w[k];
  for (int i = k - 1; i >= 0; i--) {
    int l = a[1] / w[i] % 10, r = b[1] / w[i] % 10;
    if (o) {
      for (int p = 1; p <= 9; p++) {
        for (int q = 1; q <= 9; q++) {
          if ((s >> p & 1) && (s >> q & 1) && p >= l && p <= r && !(q >= l && q <= r)) {
            return 0;
          }
        }
      }
    } else {
      for (int p = 1; p <= 9; p++) {
        for (int q = 1; q <= 9; q++) {
          if ((s >> p & 1) && (s >> q & 1) && ((p >= l && q < l) || (p <= r && q > r))) {
            return 0;
          }
        }
      }
    }
    o &= a[1] / w[i] == b[1] / w[i];
  }
  return 1;
}

bool C(int s) { return (n == 1 && a[1] > 6000 && k != 1) ? C2(s) : C1(s); }

int main() {
  fin >> n >> k;
  for (int i = 1; i <= n; i++) {
    fin >> a[i] >> b[i];
  }
  for (int i = 1; i <= k; i++) {
    w[i] = w[i - 1] * 10;
  }
  for (int i = 1, _s = 0; i <= 9; i++) {
    if (!(_s >> i & 1)) {
      fout << i;
      int s = 1 << i;
      for (int j = i + 1; j <= 9; j++) {
        if (!(_s >> j & 1) && C(s | 1 << j)) {
          fout << j;
          s |= 1 << j;
        }
      }
      fout << '\n';
      _s |= s;
    }
  }
  return 0;
}