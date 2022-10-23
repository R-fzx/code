// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
using LL = long long;

const int kMaxN = 1e5 + 2, kD = 3, kInf = 1e6;

struct E {                                                      // 立方体
  int v[kD][2] = {{-kInf, kInf}, {-kInf, kInf}, {-kInf, kInf}};  // 三维坐标边界
} e[kMaxN], p[kMaxN], s[kMaxN];                                 // 列表、前缀交、后缀交

int n;
LL t, v;

E I(E &x, E &y) {  // 计算交
  E a;
  for (int i = 0; i < kD; i++) {                                                   // 枚举维度
    a.v[i][0] = max(x.v[i][0], y.v[i][0]), a.v[i][1] = min(x.v[i][1], y.v[i][1]);  // 求交
  }
  return a;
}

LL V(E x) {                       // 计算体积
  LL r = 1;                       // 初始化
  for (int i = 0; i < kD; i++) {  // 枚举维度
    r *= max(0, x.v[i][1] - x.v[i][0] + 1);
  }
  return r;
}

int main() {
  freopen("cube.in", "r", stdin);
  freopen("cube.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d %d %d", e[i].v[0], e[i].v[1], e[i].v[2], e[i].v[0] + 1, e[i].v[1] + 1, e[i].v[2] + 1);
    p[i] = I(p[i - 1], e[i]);  // 求前缀交
  }
  for (int i = n; i >= 1; i--) {
    s[i] = I(s[i + 1], e[i]);  // 求后缀交
  }
  v = V(p[n]);                          // 全部交
  for (int i = 1; i <= n; i++) {        // 枚举去掉的立方体
    t += V(I(p[i - 1], s[i + 1])) - v;  // 累加刚好包含n - 1次的点数
  }
  printf("%lld", t + v);
  return 0;
}