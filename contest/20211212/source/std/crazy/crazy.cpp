// 湖南师范大学附属中学 | 狂狼电竞俱乐部
#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1001;
const Pii kP = {1, 1e6 + 1};

Pii operator-(const Pii &x, const Pii &y) {         // 定义pair减法
  return {x.first - y.first, x.second - y.second};  // 两个数分别相减
}

int operator*(const Pii &x, const Pii &y) {                           // 定义pair乘法
  long long v = 1LL * x.first * y.second - 1LL * x.second * y.first;  // 向量叉乘取正负
  return v < 0 ? -1 : v > 0;
}

struct E {     // 线段
  bool b;      // 处理标记
  Pii p0, p1;  // 端点
} e[kMaxN];

struct C {                             // 点
  array<bool, kMaxN> b;                // 被多边形包含的标记
  Pii p;                               // 坐标
  bool operator<(const C &_c) const {  // 按照包含标记排序
    return b < _c.b;
  }
} c[kMaxN];

int n, m, ans;

bool C(Pii x, Pii y, Pii p, Pii q) {  // 判断xy和pq是否有交
  return ((y - x) * (p - x)) * ((y - x) * (q - x)) < 0 && ((q - p) * (x - p)) * ((q - p) * (y - p)) < 0;
}

int F(int x) {  // 寻找x接着的线段
  for (int i = 1; i <= n; i++) {
    if (i != x) {                // 不能接自己
      if (e[x].p1 == e[i].p1) {  // 交点在p1
        swap(e[i].p0, e[i].p1);  // 交换到p0
      }
      if (e[x].p1 == e[i].p0) {  // 有交点
        return i;                // 返回
      }
    }
  }
  return 0;
}

void W(int s) {                                      // 处理s开始的多边形
  for (int i = s; !e[i].b; i = F(i)) {               // 遍历每条边
    e[i].b = 1;                                      // 标记线段已处理
    for (int j = 1; j <= m; j++) {                   // 计算线段与所有点的交
      c[j].b[s] ^= C(c[j].p, kP, e[i].p0, e[i].p1);  // 有交点则切换奇偶性
    }
  }
}

int main() {
  freopen("crazy.in", "r", stdin);
  freopen("crazy.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> e[i].p0.first >> e[i].p0.second >> e[i].p1.first >> e[i].p1.second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i].p.first >> c[i].p.second;
  }
  for (int i = 1; i <= n; i++) {  // 寻找多边形
    if (!e[i].b) {                // 新的多边形
      W(i);
    }
  }
  sort(c + 1, c + 1 + m);
  for (int i = 2, s = 1; i <= m; i++) {    // 遍历所有点
    s = c[i].b == c[i - 1].b ? s + 1 : 1;  // 包含标记相同则在同一个多边形中
    ans = max(ans, s);
  }
  cout << ans;
  return 0;
}
