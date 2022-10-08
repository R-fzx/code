#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

const int kMaxN = 1005;

int n, ans;
int cnt[kMaxN][kMaxN];

int main() {
  freopen("rabbit.in", "r", stdin);
  freopen("rabbit.out", "w", stdout);
  cin >> n;
  ans = n * (n - 1) / 2;
  cout << ans << endl;
  return 0;
}