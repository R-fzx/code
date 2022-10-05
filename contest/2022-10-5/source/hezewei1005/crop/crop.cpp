// crop
#include <iostream>

using namespace std;

int n, a, b, c, d, x[100001], y[100001], m;

void build(int n) {
  for (int i = 1; i < n; i++) {
    x[i] = (a * x[i - 1] + b) % m;
    y[i] = (c * y[i - 1] + d) % m;
  }
}

int main() {
  freopen("crop.in", "r", stdin);
  freopen("crop.out", "w", stdout);
  cin >> n >> a >> b >> c >> d >> x[0] >> y[0] >> m;
  build(n);
  cout << 0 << endl;
  return 0;
}