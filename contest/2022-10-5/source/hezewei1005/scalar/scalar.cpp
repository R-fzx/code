// scalar 二分图最小匹配
#include <algorithm>
#include <iostream>

using namespace std;

long long a[801], b[801], ans;
int n;

int main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] * b[i] + a[j] * b[j] > a[i] * b[j] + a[j] * b[i]) {
        swap(a[i], a[j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans += a[i] * b[i];
  }
  cout << ans;
  return 0;
}