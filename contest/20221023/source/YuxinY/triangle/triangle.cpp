#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize("Ofast")

using namespace std;

const int N = 1e5 + 5;

long long n, q, a[N], b[N], l, r;

int main() {
  freopen("triangle.in", "r", stdin);
  freopen("triangle.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  while (q--) {
    bool f = 0;
    cin >> l >> r;
    sort(b + l, b + r + 1);
    if (r - l < 2) {
      cout << "No" << endl;
      continue;
    }
    for (int i = l; i <= r; i++) {
      for (int j = i + 1; j <= r; j++) {
        for (int k = j + 1; k <= r; k++) {
          if (b[k] >= b[i] + b[j]) {
            break;
          }
          cout << "Yes";
          f = 1;
          break;
        }
        if (f) {
          break;
        }
      } 
      if (f) {
        break;
      }
    }
    if (!f) {
      cout << "No";
    } 
    cout << endl;
    for (int i = l; i <= r; i++) {
      b[i] = a[i];
    }
  }
  return 0;
}
