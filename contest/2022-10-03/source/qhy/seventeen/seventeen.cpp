#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const int kMaxN = 201;
const int kMaxM = kMaxN * kMaxN;

int n, ans;
int a[kMaxN];
struct sqr {
  int x, y;
} s[kMaxN];
bool f[kMaxN][kMaxM * 2];

void bag() {
  memset(f, 0, sizeof(f));
  f[0][kMaxM] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2 * kMaxM; j++) {
      (f[i - 1][j]) && (f[i][j - a[i]] = f[i][j + a[i]] = 1);
    }
  }
  for (int i = 0; i <= kMaxM; i++) {
    if (f[n][i + kMaxM]) {
      ans += i * i;
      return;
    }
  }
}

int main() {
  ifstream cin("seventeen.in");
  ofstream cout("seventeen.out");
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].x >> s[i].y;
    ans -= ((a[i] = s[i].x) * s[i].x + s[i].y * s[i].y);
  }
  bag();
  for (int i = 1; i <= n; i++) {
    a[i] = s[i].y;
  }
  bag();
  cout << fixed << setprecision(2) << ans / 2.00 << '\n';
  return 0;
}