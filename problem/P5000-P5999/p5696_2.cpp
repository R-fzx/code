// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <iostream>

using namespace std;
using Pdd = pair<double, double>;
using Vec = pair<Pdd, Pdd>;  // 向量

const int kMaxN = 105, kInf = 10001;

Pdd p[kMaxN];             // 多边形顶点
Vec v[kMaxN];             // 向量
pair<Vec, Pdd> s[kMaxN];  // 向量列表
int n, m, h, t;
// 向量运算
Pdd operator+(Pdd i, Pdd j) { return {i.first + j.first, i.second + j.second}; }
Pdd operator-(Pdd i, Pdd j) { return {i.first - j.first, i.second - j.second}; }
Pdd operator*(Pdd i, double a) { return {i.first * a, i.second * a}; }
// 向量叉乘
double operator*(Pdd i, Pdd j) { return i.first * j.second - i.second * j.first; }
double operator*(Vec i, Vec j) { return (i.second - i.first) * (j.second - j.first); }
double operator*(Vec i, Pdd j) { return (i.second - i.first) * (j - i.first); }

bool Up(Pdd i) { return i.second < 0 || !i.second && i.first < 0; }  // 判断是否在上半平面

bool Com(Vec &i, Vec &j) {  // 向量比较器，先上下、再左旋、最后松紧
  double ui = Up(i.second - i.first), uj = Up(j.second - j.first), v = i * j;
  return ui != uj ? ui < uj : v > 0 || !v && i * j.first < 0;
}

Pdd Point(Vec &i, Vec &j) {  // 求交点
  double s = -(j * i.first), s2 = s / (s + j * i.second);
  return i.first + (i.second - i.first) * s2;
}

void Add(int n) {  // 加入多边形
  p[0] = p[n];
  for (int i = 1; i <= n; i++) {
    v[++m] = {p[i - 1], p[i]};
  }
}

bool Check() {
  sort(v + 1, v + 1 + n, Com);                        // 极角排序
  s[h = t = 1] = {v[1], {-1e12, v[1].first.second}};  // 初始化列表
  for (int i = 2; i <= n; i++) {
    if (v[i] * v[i - 1]) {                             // 不是平行向量
      for (; h <= t && v[i] * s[t].second < 0; t--) {  // 队尾交点不在新向量左边
      }
      if (h > t) {  // 删除了所有向量
        return 0;
      }
      ++t, s[t] = {v[i], Point(v[i], s[t - 1].first)};  // 添加向量，计算交点
    }
  }
  return 1;
}

int main() {
  for (int i = 1; cin >> n && n; i++) {
    p[1] = {-kInf, kInf}, p[2] = {-kInf, -kInf}, p[3] = {kInf, -kInf}, p[4] = {kInf, kInf}, p[0] = p[4];
    m = 0, Add(4);  // 加入初始平安
    for (int i = n; i >= 1; i--) {
      cin >> p[i].first >> p[i].second;
    }
    Add(n), n = m;  // 加入多边形
    cout << "Room #" << i << ":\n";
    cout << "Surveillance is " << (Check() ? "" : "im") << "possible.\n\n";
  }
  return 0;
}