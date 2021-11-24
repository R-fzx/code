#include <iostream>

using namespace std;
using LL = long long;

const int kH = 10, kN = 601;
const LL kM = 998244353;

int h, w, n, a[kH][kH], t[2][1 << kH][10];
LL f[kN][1 << kH], ans, *x;
char ch;

int main() {
  cin >> h >> w >> n;
  n <<= 1;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) cin >> ch, a[i][j] = ch - '0';
  for (int k = 0; k < 2; swap(h, w), ++k)
    for (int o = 0; o < 1 << h; ++o)
      for (int i = 0; i < h; ++i)
        if (o >> i & 1)
          for (int j = 0; j < w; ++j) k && (swap(i, j), 0), t[k][o][a[i][j]] |= 1 << (k ? i : j), k && (swap(i, j), 0);
  for (int i = (f[0][(1 << h) - 1] = 1, 0); i < n; ++i)
    for (int j = 0; j < 1 << (i & 1 ? w : h); ++j)
      for (int k = 1; k <= 9; ++k) x = &f[i + 1][t[i & 1][j][k]], *x = (*x + f[i][j]) % kM;
  for (int i = 1; i < 1 << h; ++i) ans = (ans + f[n][i]) % kM;
  cout << ans;
  return 0;
}