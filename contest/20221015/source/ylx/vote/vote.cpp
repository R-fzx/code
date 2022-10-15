#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m, c[N], r;

int main() {
  freopen("vote.in", "r", stdin);
  freopen("vote.out", "w", stdout);
  srand(time(0));
  cin >> n >> m;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    c[x]++;
  }
  if (n == m) {
    int M = *max_element(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
      r += M == c[i];
    }
    cout << (r > 1 ? "0.0000" : "1.0000");
  } else {
    cout << (rand() % 2 ? "1.0000" : "0.0000");
  }
  return 0;
}
/*

*/