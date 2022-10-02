#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using ll = long long;
using ld = double;

const int kMaxN = 301;

int n, h[kMaxN];
ld a[kMaxN];
int ton[kMaxN];
ld ans;

void init() {
  a[0] = a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] * i;
  }
}

ld A(int n, int k) { return a[n] / a[n - k]; }

int main() {
  ifstream cin("queue.in");
  ofstream cout("queue.out");
  cin >> n;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    ton[h[i]]++;
  }
  sort(h + 1, h + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (h[i] == h[i - 1]) {
      continue;
    }
    ld tmp = 0.0;
    for (int j = 0; j < i; j++) {
      tmp += A(i - 1, j) / A(n, j + 1) * ld(j + 1);
    }
    for (int j = 0; j <= min(i - 1, n - 2); j++) {
      tmp += (j + 1) * A(i - 1, j) / a[n] * ld(n - i) * a[n - j - 2] *
             ld(n - j - 1);
    }
    ans += ton[i] * tmp;
  }
  cout << fixed << setprecision(2) << ans << endl;
  return 0;
}