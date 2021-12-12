// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1;

Pii p[kMaxN * 2];
int l[kMaxN * 2], n;

Pii operator-(const Pii &a, const Pii &b) {         // 定义pair减法
  return {a.first - b.first, a.second - b.second};  // 向量减法
}

int operator*(const Pii &x, const Pii &y) {                           // 定义pair乘法
  long long v = 1LL * x.first * y.second - 1LL * x.second * y.first;  // 向量叉乘取正负
  return v < 0 ? -1 : v > 0;
}

bool C(int i, int j) {  // 判断线段交，互相横跨
  return ((p[i + n] - p[i]) * (p[j] - p[i])) * ((p[i + n] - p[i]) * (p[j + n] - p[i])) <= 0 &&
         ((p[j + n] - p[j]) * (p[i] - p[j])) * ((p[j + n] - p[j]) * (p[i + n] - p[j])) <= 0;
}

Pii F() {                                           // 寻找相交的线段
  set<Pii> s;                                       // 按照y排序的坐标和编号
  for (int i = 1; i <= 2 * n; i++) {                // 扫描每个点
    if (l[i] <= n) {                                // 左端点
      auto j = s.lower_bound({p[l[i]].second, 0});  // 上方邻点
      if (j != s.end() && C(l[i], j->second)) {
        return {l[i], j->second};
      }
      if (j != s.begin() && C(l[i], (--j)->second)) {  // 下方邻点
        return {l[i], j->second};
      }
      s.insert({p[l[i]].second, l[i]});                        // 插入集合
    } else {                                                   // 右端点
      s.erase({p[l[i] - n].second, l[i] - n});                 // 将左端点从集合中删除
      auto j = s.lower_bound({p[l[i] - n].second, 0}), k = j;  // 上方邻点
      if (j != s.end() && j != s.begin() && C(j->second, (--k)->second)) {
        return {j->second, k->second};
      }
    }
  }
  return {0, 0};
}

int W(int i) {                    // 计算线段相交数量
  int c = 0;                      // 初始化数量
  for (int j = 1; j <= n; j++) {  // 枚举其他线段
    c += i != j && C(i, j);       // 累加数量
  }
  return c;
}

int main() {
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second >> p[i + n].first >> p[i + n].second;
    if (p[i].first > p[i + n].first) {
      swap(p[i], p[i + n]);  // 将左端点调整到前面
    }
    l[i] = i, l[i + n] = i + n;  // 初始化编号
  }

  sort(l + 1, l + 1 + 2 * n, [](int i, int j) { return p[i] < p[j]; });

  Pii ans = F();
  if (ans.first > ans.second) {
    swap(ans.first, ans.second);  // 较小编号放前面
  }
  cout << (W(ans.second) > 1 ? ans.second : ans.first);
  return 0;
}