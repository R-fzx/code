// 狂狼电竞俱乐部 | 胖头鱼
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;
using Pdd = pair<double, double>;
using Vec = pair<Pdd, Pdd>;

const int kMaxN = 505, kInf = 1e3;

Pdd p[kMaxN] = {{}, {-kInf, kInf}, {-kInf, -kInf}, {kInf, -kInf}, {kInf, kInf}};  // 多边形顶点
Vec v[kMaxN];                                                                     // 向量
pair<Vec, Pdd> s[kMaxN];                                                          // 向量列表
int n, m, h, t;
double ans;
// 向量运算
Pdd operator-(Pdd i, Pdd j) { return {i.first - j.first, i.second - j.second}; }
Pdd operator+(Pdd i, Pdd j) { return {i.first + j.first, i.second + j.second}; }
Pdd operator*(Pdd i, double a) { return {i.first * a, i.second * a}; }
// 向量叉乘
double operator*(Pdd i, Pdd j) { return i.first * j.second - i.second * j.first; }
double operator*(Vec i, Vec j) { return (i.second - i.first) * (j.second - j.first); }
double operator*(Vec i, Pdd j) { return (i.second - i.first) * (j - i.first); }

bool Up(Pdd i) { return i.second < 0 || !i.second && i.first < 0; }  // 判断是否在上半平面

bool Com(Vec &i, Vec &j) {  // 向量比较器，先上下、再左旋、最后松紧
  double ui = Up(i.second - i.first), uj = Up(j.second - j.first), v = i * j;
  return ui == uj ? (v > 0 || !v && i * j.first < 0) : ui < uj;
}

Pdd Point(Vec &i, Vec &j) {  // 求交点
  double s = -(j * i.first), s2 = s / (s + j * i.second);
  return i.first + (i.second - i.first) * s2;
}

void Add() {  // 加入多边形
  p[0] = p[m];
  for (int i = 1; i <= m; i++) {
    v[++t] = {p[i - 1], p[i]};
  }
}

void Input() {
  m = 4, Add();  // 初始平面
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    for (int j = 1; j <= m; j++) {
      cin >> p[j].first >> p[j].second;
    }
    Add();
  }
  n = t;
}

int main() {
  Input();

  sort(v + 1, v + 1 + n, Com);

  s[h = t = 1].first = v[1];  // 初始化队列
  for (int i = 2; i <= n; i++) {
    if (v[i] * v[i - 1]) {                            // 不是平行向量
      for (; t > h && v[i] * s[t].second < 0; t--) {  // 尾部交点在新向量右边
      }
      ++t, s[t] = {v[i], Point(v[i], s[t - 1].first)};              // 加入新向量并求交点
      for (; t > h + 1 && s[t].first * s[h + 1].second < 0; h++) {  // 首部交点在新向量右边
      }
    }
  }
  for (; t > h + 1 && s[h].first * s[t].second < 0; t--) {  // 尾部交点不在首部向量右边
  }

  s[h].second = Point(s[h].first, s[t].first);  // 计算首尾向量的交点

  ans = s[t].second * s[h].second;
  for (int i = h; i < t; i++) {
    ans += s[i].second * s[i + 1].second;
  }
  cout << fixed << setprecision(3) << ans / 2;
  return 0;
}