#include <algorithm>
#include <fstream>
#include <iostream>
ll
using namespace std;
using ll = long long;

ll n, a[801], b[801];
ll ans;

int main() {
  ifstream cin("scalar.in");
  ofstream cout("scalar.out");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a, a + n), sort(b, b + n);
  for (int i = 0; i < n; i++) {
    ans += a[i] * b[n - 1 - i];
  }
  cout << ans << endl;
  return 0;
}