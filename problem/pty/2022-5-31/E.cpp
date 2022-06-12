#include <iostream>

using namespace std;
using LL = long long;

const int kN = 201;

int n, m;
LL a[kN], b[kN], c[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= n + m; ++i) {
    cin >> c[i];
  }
  for (int i = m; i >= 0; --i) {
    b[i] = c[n + i] / a[n];
    for (int j = n; j >= 0; --j) {
      c[i + j] -= b[i] * a[j];
    }
  }
  for (int i = 0; i <= m; ++i) {
    cout << b[i] << " ";
  }
  return 0;
}