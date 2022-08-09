#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define db(x) cerr << #x << '=' << x << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg debug("*** Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

using namespace std;

using ull = unsigned long long;

const int kMaxN = 5e5 + 5;

unordered_map<ull, int> mp;
int n;
int a[kMaxN];
ull pw[kMaxN], hs[kMaxN], pp[kMaxN];

ull gethash(int l, int r) {
  return hs[r] - hs[l - 1] * pw[r - l + 1];
}

bool check(int x) {
  // db(x);
  mp.clear();
  int maxn = 0;
  for (int l = 1; l + x - 1 <= n; ++l) {
    int r = l + x - 1;
    ull hh = gethash(l, r) - a[l] * pp[x - 1];
    // db(hh);
    if (mp[hh]) maxn = max(maxn, l - mp[hh]);
    else mp[hh] = l;
  }
  // db(maxn);
  return maxn >= x;
}

int main() {
  freopen("snowman.in", "r", stdin);
  freopen("snowman.out", "w", stdout);
  cin >> n;
  pw[0] = 1; pp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pw[i] = pw[i - 1] * 13331;
    hs[i] = hs[i - 1] * 13331 + a[i];
    pp[i] = pp[i - 1] + pw[i];
  }
  int L = 0, R = n + 1, res = -1;
  while (L + 1 < R) {
    int mid = (L + R) >> 1;
    if (check(mid)) L = res = mid;
    else R = mid;
  }

  // db(gethash(1, 5));
  // db(1 * pw[0] + 2 * pw[1] + 3 * pw[2] + 4 * pw[3] + 5 * pw[4]);
  // db(gethash(6, 10) - a[6] * pp[4]);
  cout << res << endl;
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}