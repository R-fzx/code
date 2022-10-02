#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 7;

int n;

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
  cin >> n;
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = (ans * 2)  % MOD;
  }
  cout << ((ans - 1) % MOD + MOD) % MOD;
  return 0;
}