// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 1e5 + 1, kL = 100;

long long a[kMaxN], b[kMaxN];
int n, q, l, r;

bool C() {
  if (r - l > kL) {  // 数量足够多必然有解
    return 1;
  }
  copy(a + l, a + r + 1, b + l);       // 复制
  sort(b + l, b + r + 1);              // 排序
  for (int i = l; i < r - 1; i++) {    // 枚举相邻三个数
    if (b[i] + b[i + 1] > b[i + 2]) {  // 校验
      return 1;
    }
  }
  return 0;
}

int main() {
  freopen("triangle.in", "r", stdin);
  freopen("triangle.out", "w", stdout);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  while (q--) {
    scanf("%d %d", &l, &r);
    printf("%s\n", C() ? "Yes" : "No");
  }
  return 0;
}