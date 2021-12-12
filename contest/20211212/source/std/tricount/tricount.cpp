// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;
using Pii = pair<LL, LL>;

const int kMaxN = 1e5 + 1;

Pii p[kMaxN];
LL n, ans;

bool U(Pii &i) {  // 是否在[0, pi)
  return i.second < 0 || !i.second && i.first < 0;
}

LL M(Pii &i, Pii &j) {  // 叉乘
  return i.first * j.second - i.second * j.first;
}

bool C(Pii &i, Pii &j) {                              // 极角排序
  return U(i) < U(j) || U(i) == U(j) && M(i, j) > 0;  // 先判半平面，再判左右
}

int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  sort(p, p + n, C);

  for (int i = 0, j = 0; i < n; i++) {                                   // 枚举点
    for (j = max(j, i + 1); j % n != i && M(p[i], p[j % n]) > 0; j++) {  // 调整左右边界
    }
    LL c = j - i - 1;                                        // 左边点数
    ans += c * (c - 1) / 2 + (n - 1 - c) * (n - 2 - c) / 2;  // 累加三角形数量
  }
  cout << n * (n - 1) * (n - 2) / 6 - ans / 2;
  return 0;
}