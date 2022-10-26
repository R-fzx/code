#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("c.in");
ofstream fout("c.out");

const int kMaxN = 1e5 + 1;

LL a[kMaxN];
int n, ans;

int C(LL x) {
  int r = 0;
  for (; x; x ^= x & -x) {
    r++;
  }
  return r;
}

int C1(int ans) {
  for (int v = 1; v <= 500; v++) {
    int _ans = 0;
    for (int j = 1; j <= n; j++) {
      _ans += C(a[j] + v);
    }
    ans = min(ans, _ans);
  }
  return ans;
}

int C2(int ans) {
  for (LL i = 1; i <= a[1]; i <<= 1) {
    int _ans = 0;
    for (int j = 1; j <= n; j++) {
      _ans += C(a[j] + i);
    }
    if (_ans < ans) {
      ans = _ans;
      for (int j = 1; j <= n; j++) {
        a[j] += i;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = a[n] - a[i];
    ans += C(a[i]);
  }
  fout << min(C1(ans), C2(ans));
  return 0;
}