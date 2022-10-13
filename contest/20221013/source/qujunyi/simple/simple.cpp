#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
} a[1000005];
int main() {
   freopen("simple.in","r",stdin);
   freopen("simple.out","w",stdout);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
    }
    while (m--) {
      long long x, y;
      cin >> x >> y;
      long long sum = 0;
      for (int i = 1; i <= n; i++) {
        sum += max(abs(a[i].x - x), abs(a[i].y - y));
      }
      cout << sum << endl;
    }
  }
}