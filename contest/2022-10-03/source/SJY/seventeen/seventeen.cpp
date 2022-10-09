#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2e2 + 5;

struct NODE {
  int x, y;
} a[N];

int n, ans;

int main() {
  freopen("seventeen.in", "r", stdin);
  freopen("seventeen.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    int sum = 0;
    for (int j = 1; j < i; ++j) {
      for (int k = min(a[i].x, a[j].x); k >= 0; --k) {
        for (int l = max(a[i].y, a[j].y); l >= 0; --l) {
          sum *= a[i].x * a[j].x;
        }
      }
    }
    cout << sum;
  }
}