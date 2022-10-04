#include <cstdio>
#include <iostream>

using namespace std;

int t, n, q, ans;
int l[101], p[101];

int main() {
  freopen("puppet.in", "r", stdin);
  freopen("puppet.out", "w", stdout);
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> q;
      l[q]++;
      p[q]++;
    }
    for (int i = 1; i <= 100; i++) {
      while (p[i]--) {
        if (l[i + 1]) {
          l[i + 1]--;
        } else if (l[i]) {
          l[i]--;
        } else if (l[i - 1]) {
          l[i - 1]--;
        } else {
          ans++;
        }
      }
    }
    for (int i = 1; i <= 100; i++) {
      p[i] = l[i] = 0;
    }
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}