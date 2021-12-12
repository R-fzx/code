#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using LL = long long;

const int kMaxL = 1e6 + 1, kM = 998244353;

unordered_map<LL, int> p;
vector<int> l[kMaxL];
int f[kMaxL];
LL n, k, ans = 1;

int main() {
  freopen("G.in", "r", stdin);
  freopen("G.ans", "w", stdout);
  cin >> n >> k;
  for (LL i = 2; i < kMaxL; i++) {
    if (!f[i]) {
      for (int j = i; j < kMaxL; j += i) {
        f[j] = i;
      }
      for (LL j = (n - k) / i * i + i, v; j <= n; j += i) {
        l[j - n + k].push_back(i);
      }
    }
  }
  for (int i = 2; i <= k; i++) {
    for (int v = i; v > 1; v /= f[v]) {
      p[f[v]]--;
    }
  }
  for (LL i = max(2LL, n - k + 1); i <= n; i++) {
    LL v = i;
    for (int j : l[i - n + k]) {
      for (; v % j == 0; v /= j) {
        p[j]++;
      }
    }
    p[v] += v > 1;
  }
  for (auto i : p) {
    ans = ans * (i.second + 1) % kM;
  }
  cout << ans;
  return 0;
}