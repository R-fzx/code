// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("section.in");
ofstream fout("section.out");

const int kMaxN = 1e6 + 1;

int a[kMaxN], b[kMaxN * 2];
int n, m, q, o, l, d, p = kMaxN, ans;

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  for (int i = 1; i <= m; i++) {  // 将最左区间加入队列
    b[p + i - 1] = a[i];
  }
  for (int i = 1; q > 0; q--) {
    fin >> o >> l;
    if (o == 1) {                              // 翻转操作
      for (; i < l; i++) {                     // 移动到操作区间
        if (d) {                               // 当前区间是反向
          a[i] = b[--p + m], b[p] = a[i + m];  // 队尾出队，新元素入队头
        } else {
          a[i] = b[p], b[p++ + m] = a[i + m];  // 队头出队，新元素入队尾
        }
      }
      d ^= 1;                                              // 翻转
    } else {                                               // 取值操作
      if (l < i || l >= i + m) {                           // 在当前区间外
        ans ^= a[l];                                       // 直接取值
      } else {                                             // 在当前区间内
        ans ^= d ? b[p + m - 1 - (l - i)] : b[p + l - i];  // 根据方向取值
      }
    }
  }
  fout << ans;
  return 0;
}