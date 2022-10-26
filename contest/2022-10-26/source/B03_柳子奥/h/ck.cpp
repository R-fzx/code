#include <bits/stdc++.h>

#define int long long

using namespace std;

const int kMaxN = 2e5 + 5;

struct Node {
  int x, y;
} p[kMaxN], tmp1[kMaxN], tmp2[kMaxN];

int n, k, m, s;
int a[kMaxN], exi[kMaxN], f[kMaxN][22], lg[kMaxN], sum[kMaxN];
int sum1[kMaxN << 2], sum2[kMaxN << 2];
int c[kMaxN << 2]; // 树状数组

void upd(int x, int v) {
  for (; x <= 6e5; x += x & -x) {
    c[x] += v;
  }
}

int qry(int x) {
  if (!x) return 0;
  int ret = 0;
  for (; x; x -= x & -x) {
    ret += c[x];
  }
  return ret;
}

void prework() {
  lg[0] = -1;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = a[i], lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i <= lg[n]; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
    }
  }
}

int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}

bool cmp(Node a, Node b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}

signed main() {
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i].x >> p[i].y, ++sum[p[i].x];
  prework();
  int ans = 0, sm = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      if (p[i].x == p[j].x) {
        if (abs(p[i].y - p[j].y) <= k) ++ans;
      } else {
        int yy = p[i].x, yyy = p[j].x;
        if (yy > yyy) swap(yy, yyy);
        int mi = query(yy, yyy);
        if (p[i].y <= mi || p[j].y <= mi) {
          if (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= k) {
            ++ans;
            if(p[i].y <= mi && p[j].y <=mi) ++sm;
          }
        } else if (p[i].y + p[j].y - mi + abs(p[j].x - p[i].x) - mi <= k) {
          ++ans;
        }
      }
    }
  }
  cerr << sm<< endl;
  cout << ans << endl;
  return 0;
}