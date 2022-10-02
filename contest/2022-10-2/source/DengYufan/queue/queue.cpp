#include <iomanip>
#include <iostream>

using namespace std;

int n, a[301], d[301];
bool b[301];
double k = 1, ans;

void S(int x) {
  if (x > n) {
    int c = n;
    for (int i = 1; i <= n; i++) {
      for (int j = i - 1; j >= 1 && a[d[j]] < a[d[i]]; j--, c++) {
      }
    }
    ans += double(c) * k;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      d[x] = i, b[i] = 1;
      S(x + 1);
      b[i] = 0;
    }
  }
}

int main() {
  freopen("queue.in", "r", stdin);
  freopen("queue.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    k /= double(i);
  }
  S(1);
  cout << fixed << setprecision(2) << ans;
  return 0;
}
