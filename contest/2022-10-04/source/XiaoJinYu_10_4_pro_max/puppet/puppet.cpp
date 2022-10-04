#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int a[MAXN];

int main() {
  freopen("puppet.in", "r", stdin);
  freopen("puppet.out", "w", stdout);
  int n;
  while (cin >> n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int cnt1 = 1, cnt2 = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i - 1]) ++cnt2;
      ++cnt1;
      if (cnt1 > 2 && cnt2 > 1) {
        ++i;
        while (a[i] == a[i - 1] && i < n) ++i;
        if (a[i] - a[i - 1] < 2) {
          while (a[i + 1] == a[i] && i < n) ++i;
        }
        cnt1 = 1, cnt2 = 1;
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}