#include <algorithm>
#include <iostream>
#include <queue>
#define LL long long
#define PLL pair<LL, LL>

using namespace std;

const LL kMaxN = 2e5 + 1;
LL n, m, k, a[kMaxN], d[kMaxN * 6], f[kMaxN];
PLL c, b[kMaxN];
priority_queue<PLL> q;

LL Read() {
  LL x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

void Add(LL x, LL y) {
  for (LL i = x + kMaxN * 3; i < kMaxN * 6; i += i & -i) {
    d[i] += y;
  }
}

LL Ask(LL x) {
  LL ans = 0;
  for (LL i = x + kMaxN * 3; i >= 1; i -= i & -i) {
    ans += d[i];
  }
  return ans;
}

int main() {
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  n = Read(), k = Read();
  for (LL i = 1; i <= n; i++) {
    a[i] = Read();
  }
  m = Read();
  for (LL i = 1; i <= m; i++) {
    b[i].first = Read(), b[i].second = Read();
  }
  sort(b + 1, b + m + 1);
  for (LL i = 1; i <= m; i++) {
    f[i] = f[i - 1] + Ask(k - b[i].first - b[i].second);
    Add(b[i].second - b[i].first - 2 * a[b[i].first], 1);
    q.push({a[b[i].first], i});
    for (; q.top().first > a[b[i].first];) {
      c = q.top(), q.pop(), q.push({a[b[i].first], c.second});
      Add(b[c.second].second - b[c.second].first - 2 * a[b[c.second].first], -1);
      Add(b[c.second].second - b[c.second].first - 2 * a[b[i].first], 1);
    }
  }
  cout << f[m];
  return 0;
}
