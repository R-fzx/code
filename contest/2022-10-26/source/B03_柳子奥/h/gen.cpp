#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 5;

int main() {
  mt19937 rnd(time(0));
  srand(time(0));
  freopen("h.in", "w",stdout);
  int n = 6, k = 9;
  cout << n << ' ' << k << endl;
  uniform_int_distribution<> gen(1, 100000), fuck(1, n);
  int a[kMaxN];
  for (int i = 1; i <= n; ++i) cout << (a[i] = rand() %6 + 1) << ' ';
  cout << endl;
  k = 10;
  cout << k << endl;
  for (int i = 1; i <= k;++i) {
    int x = rand() % n + 1;
    cout << x << ' ' << rand() % a[x] + 1 << endl;
  }
  return 0;
}