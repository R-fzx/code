#include <cmath>
#include <iostream>
using namespace std;

int n, a, num[1001][64], Max, tmp[1001];

int Find(int next[], int dep, int ans) {
  int tmp = 0, Min;
  if (dep >= Max) {
    bool z = 1;
    for (int i = 0; i < n; i++) {
      z = z && !next[i];
    }
    return ans + !z * (1e9 + 7);
  }
  int a[10001];
  for (int i = 0; i < n; i++) {
    a[i] = next[i];
  }
  for (int i = 0; i < n; i++) {
    tmp += ((num[i][dep] && !next[i]) || (next[i] && !num[i][dep]));
    a[i] = (next[i] || num[i][dep]);
  }
  Min = Find(a, dep + 1, tmp + ans);
  tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp += ((!num[i][dep] && !next[i]) || (next[i] && num[i][dep]));
    a[i] = (next[i] && num[i][dep]);
  }
  return min(Min, Find(a, dep + 1, tmp + ans));
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
  } else {
    for (int i = 0, t = 0; i < n; Max = max(Max, t), i++, t = 0) {
      cin >> a;
      while (a) {
        num[i][t] = a % 2;
        a /= 2;
        t++;
      }
    }
    cout << Find(tmp, 0, 0) << '\n';
  }
  return 0;
}