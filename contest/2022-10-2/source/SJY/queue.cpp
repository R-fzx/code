#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e2 + 5;

int n, h[N], ans;
double p[N];

inline bool cmp(int a, int b) {
  return a < b;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }

  sort(h + 1, h + n + 1, cmp);
  int small = 1, sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (h[i] > h[i - 1]) {
      small += sum;
      sum = 0;
    }
    ++sum;
    int temp = (1 + small) * small / 2;
    cout << temp << ' ';
    p[i] = temp * 1.0 / small;
  }

  double ans = 1.0;
  for (int i = 1; i <= n; ++i) {
    ans += p[i];
    cout << p[i] << '\n';
  }
  cout << ans;
}