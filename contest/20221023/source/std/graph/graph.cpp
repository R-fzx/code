// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 2001;

struct V {   // 点
  bool b;    // 树中标记
  int a, d;  // 权值、距离
} v[kMaxN];
int n;
long long ans;

int main() {
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].a;
    ans -= v[i].a;    // 减去点权
    v[i].d = v[i].a;  // 初始化到根的距离
  }
  for (int i = 1; i <= n; i++) {                 // 不断选点
    int p = 0;                                   // 初始化选点编号
    for (int j = 1; j <= n; j++) {               // 枚举点
      if (!v[j].b && (!p || v[j].d > v[p].d)) {  // 找到距离更大的点
        p = j;                                   // 记录
      }
    }
    ans += v[p].d;                              // 累加答案
    v[p].b = 1;                                 // 标记入树
    for (int j = 1; j <= n; j++) {              // 枚举点
      if (!v[j].b && !(v[p].a & v[j].a)) {      // 不在树中且有边相连
        v[j].d = max(v[j].d, v[p].a + v[j].a);  // 更新点到树的距离
      }
    }
  }
  cout << ans;
  return 0;
}