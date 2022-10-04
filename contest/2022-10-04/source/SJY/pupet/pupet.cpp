#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 55;

int n, p[N], ans;

int main() {
  freopen("pupet.in", "r", stdin);
  freopen("pupet.out", "w", stdout);
  while (~scanf("%d", &n)) {
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
    } 
    
    sort(p + 1, p + n + 1);

    int t = 1;
    for (int i = 1; i <= n; ++i) {
      if (p[i] > p[t] + 1) {
        ++ans;
        t = i + 1;
      }
    }
    cout << ans << '\n';
  }
}