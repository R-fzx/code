#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxN = 1e6 + 5, kMod = 1e9 + 7;

int n, tot, ans = 1;
vector<int> p;
bool vis[kMaxN];

void getp() {
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      p.emplace_back(i);
    }
    for (int j = 2 * i; j <= n; j += i) {
      vis[j] = 1;
    }
  }
}

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
  cin >> n;
  getp();
  for (auto x : p) {
    int cnt = 0, cn = n;
    while (cn) {
      cn /= x, cnt += cn;
    }
    cnt *= 2;
    ans = 1ll * ans * (cnt + 1) % kMod;
  }
  cout << ans << endl;
  return 0;
}