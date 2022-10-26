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
vector<int> v[kMaxN];

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

bool cmp1(Node a, Node b) {
  return a.y != b.y ? a.y > b.y : a.x < b.x;
}

int solve(int L, int R, int idx) {
  R = min(R, exi[s]);
  int l = lower_bound(exi + 1, exi + 1 + s, L) - exi, r = lower_bound(exi + 1, exi + 1 + s, R + 1) - exi - 1;
  if (L == R) return 0;
  int mid = lower_bound(exi + 1, exi + 1 + s, idx + 1) - exi;
  --mid;
  if (mid < l || mid + 1 > r) return 0;
  cerr << L << ' ' << R << ' ' << l << ' ' << r << ' ' << mid << endl;
  int t1 = 0, t2 = 0, ret = 0;
  for (int i = l; i <= mid; ++i) {
    tmp1[++t1] = p[i];
  }
  for (int i = mid + 1; i <= r; ++i) {
    tmp2[++t2] = p[i];
  }
  sort(tmp1 + 1, tmp1 + 1 + t1, cmp1), sort(tmp2 + 1, tmp2 + 1 + t2, cmp1);
/*************** 两个都小于等于min ***************/

//           1. y1 <= y2
  int kj = 1;
  for (int i = 1; i <= t1; ++i) {
    if (tmp1[i].y > a[idx]) continue ;
    for (; kj <= t2 && tmp2[kj].y >= tmp1[i].y; ++kj) upd(tmp2[kj].x + tmp2[kj].y, (tmp2[kj].y <= a[idx]));
    ret -= qry(tmp1[i].x + tmp1[i].y + k);
    // cerr << tmp1[i].x << ' ' << tmp1[i].y << ' ' << qry(tmp1[i].x + tmp1[i].y + k) << endl;
  }
  for (int i = 1; i < kj; ++i) upd(tmp2[i].x + tmp2[i].y, -(tmp2[i].y <= a[idx]));
//           2. y1 > y2
  kj = t2;
  for (int i = t1; i; --i) {
    if (tmp1[i].y > a[idx]) continue ;
    for (; kj && tmp2[kj].y < tmp1[i].y; --kj) upd(tmp2[kj].y - tmp2[kj].y + 2e5, (tmp2[kj].y <= a[idx]));
    ret -= qry(tmp1[i].x - tmp2[i].y + k + 2e5);
    // cerr << tmp1[i].x << ' ' << tmp1[i].y << ' ' << qry(tmp1[i].x - tmp2[i].y + k + 2e5) << endl;
  }
  for (int i = kj + 1; i <= t2; ++i) upd(tmp2[i].y - tmp2[i].y + 2e5, -(tmp2[i].y <= a[idx]));
  
  cerr << -ret << endl;
/*************** 右边的小于等于min ***************/

//           1. y1 <= y2
   kj = 1;
  for (int i = 1; i <= t1; ++i) {
    for (; kj <= t2 && tmp2[kj].y >= tmp1[i].y; ++kj) upd(tmp2[kj].x + tmp2[kj].y, (tmp2[kj].y <= a[idx]));
    ret += qry(tmp1[i].x + tmp1[i].y + k);
  }
  for (int i = 1; i < kj; ++i) upd(tmp2[i].x + tmp2[i].y, -(tmp2[i].y <= a[idx]));

//           2. y1 > y2
  kj = t2;
  for (int i = t1; i; --i) {
    for (; kj && tmp2[kj].y < tmp1[i].y; --kj) upd(tmp2[kj].y - tmp2[kj].y + 2e5, (tmp2[kj].y <= a[idx]));
    ret += qry(tmp1[i].x - tmp2[i].y + k + 2e5);
  }
  for (int i = kj + 1; i <= t2; ++i) upd(tmp2[i].y - tmp2[i].y + 2e5, -(tmp2[i].y <= a[idx]));

  cerr << ret << endl;
  // cerr << ret + 15 << endl;
/**************** 左边的小于等于min ****************/

//           1. y1 <= y2
   kj = 1;
  for (int i = 1; i <= t1; ++i) {
    if (tmp1[i].y > a[idx]) continue ;
    for (; kj <= t2 && tmp2[kj].y >= tmp1[i].y; ++kj) upd(tmp2[kj].x + tmp2[kj].y, 1);
    ret += qry(tmp1[i].x + tmp1[i].y + k);
  }
  for (int i = 1; i < kj; ++i) upd(tmp2[i].x + tmp2[i].y, -1);

//           2. y1 > y2
  kj = t2;
  for (int i = t1; i; --i) {
    if (tmp1[i].y > a[idx]) continue ;
    for (; kj && tmp2[kj].y < tmp1[i].y; --kj) upd(tmp2[kj].y - tmp2[kj].y + 2e5, 1);
    ret += qry(tmp1[i].x - tmp2[i].y + k + 2e5);
  }
  for (int i = kj + 1; i <= t2; ++i) upd(tmp2[i].y - tmp2[i].y + 2e5, -1);


  // cerr << "3 : " << ret << endl;
/***************** 两边都大于min *****************/
  for (int i = 1; i <= t2; ++i) {
    if (tmp2[i].y > a[idx]) upd(tmp2[i].x + tmp2[i].y, 1);
  }
  for (int i = 1; i <= t1; ++i) {
    if (tmp1[i].y <= a[idx]) continue ;
    int val = k + 2 * a[idx] + (tmp1[i].x - tmp1[i].y);
    if (val >= 1) ret += qry(val);
  }
  for (int i = 1; i <= t2; ++i) {
    if (tmp2[i].y > a[idx]) upd(tmp2[i].x + tmp2[i].y, -1);
  }
  cerr << ret << endl;
  return ret;
}

signed main() {
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i].x >> p[i].y, ++sum[p[i].x];
  prework();
  if (n <= 1000 && m <= 1000) {
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
            }
          } else if (p[i].y + p[j].y - mi + abs(p[j].x - p[i].x) - mi <= k) {
            ++ans;
          }
        }
      }
    }
    cout << ans << endl;
  } else {
    sort(p + 1, p + 1 + m, cmp);
    for (int i = 1; i <= 2e5; ++i) sum[i] += sum[i - 1];
    for (int i = 1; i <= m; ++i) {
      exi[++s] = p[i].x;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int L = 0, R = i + 1, resl = i;
      while (L + 1 < R) { 
        int mid = (L + R) >> 1;
        if (query(mid, i) == a[i]) R = resl = mid;
        else L = mid;
      }
      int resr = i;
      L = i, R = n + 1;
      while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (query(i + 1, mid) > a[i]) L = resr = mid;
        else R = mid;
      }
      ans += solve(resl, resr, i);
    }
    for (int i = 1; i <= m; ++i) {
      v[p[i].x].emplace_back(p[i].y);
    }
    for (int i = 1; i <= 2e5; ++i) {
      if (v[i].size() <= 1) continue ;
      v[i].emplace_back(1e9);
      for (int j = 0; j < (int)v[i].size() - 1; ++j) {
        int x = v[i][j];
        auto it = lower_bound(v[i].begin(), v[i].end(), x + k);
        if (*it > x + k) --it;
        if (*it > x + k) continue ;
        ans += it - (v[i].begin() + j);
      }
    }
    cout << ans << endl;    
  }

  return 0;
}