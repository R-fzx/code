#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;
using LL = long long;
using LD = long double;
using Pdd = pair<LD, LD>;

ifstream fin("chaser.in");
ofstream fout("chaser.out");

Pdd operator+(Pdd a, Pdd b) { return {a.first + b.first, a.second + b.second}; };
Pdd operator-(Pdd a, Pdd b) { return {a.first - b.first, a.second - b.second}; };
Pdd operator*(Pdd a, LD x) { return {a.first * x, a.second * x}; };
LD operator*(Pdd a, Pdd b) { return a.first * b.second - a.second * b.first; };
LD D(Pdd a, Pdd b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }

Pdd w1, w2, t1, t2, vw, vt, mw1, mw2, mw;
LD _vw, _vt, dl, du, tw, dw, dt, p, dist;

LD W(Pdd p1, Pdd p2) {                                    // 求线段[p1, p2]到t1的最近距离
  LD s = abs((t1 - p1) * (p2 - p1));                      // 平行四边形面积
  LD h = s / D(p1, p2);                                   // 高，垂线距离
  LD l = sqrt(pow(D(p1, t1), 2) - pow(h, 2));             // 底边长度
  return l <= D(p1, p2) ? h : min(D(p1, t1), D(p2, t1));  // 落在线段上则为高，否则为两点距离近的
}

LD C(Pdd p, Pdd q, LL len) {  // 起点p，线段位移q，偏离周期起点
  for (LL x = 0; len;) {
    Pdd _p = p + mw * len;              // 偏移周期
    if (W(_p, _p + q) < W(p, p + q)) {  // 距离更近
      p = _p, x += len;
      continue;
    }
    if (x - len >= 0) {  // 确保不会偏移到负
      Pdd _p = p - mw * len;
      if (W(_p, _p + q) < W(p, p + q)) {  // 距离更近
        p = _p, x -= len;
        continue;
      }
    }
    len /= 2;
  }
  return W(p, p + q);
}

int main() {
  while (fin >> w1.first >> w1.second >> w2.first >> w2.second >> _vw >> t1.first >> t1.second >> t2.first >> t2.second >> _vt >> dl >> du) {
    dw = D(w1, w2);                // 人距离
    vw = (w2 - w1) * (_vw / dw);   // 人速度向量
    dt = D(t1, t2);                // 风距离
    vt = (t2 - t1) * (_vt / dt);   // 风速度向量
    mw1 = (vw - vt) * (dt / _vt);  // 前半周期人相对位移向量
    mw2 = (vw + vt) * (dt / _vt);  // 后半周期人相对位移向量
    mw = mw1 + mw2;                // 周期人相对位移向量
    {
      LD s = abs((t1 - w1) * mw);                                       // t1,w1,t1 + mw平行四边形面积
      LD h = s / D({0, 0}, mw);                                         // 高，t1到人移动直线的距离
      LD d = sqrt(pow(D(t1, w1), 2) - pow(h, 2));                       // 底边长度
      LL len = d / D({0, 0}, mw);                                       // 逼近垂线的周期数量
      dist = min(C(w1, mw1, len), C(w1 + mw, (Pdd){0, 0} - mw2, len));  // 计算两类线段距离t1的最小值
    }
    if (dist < dl) {
      fout << "Dangerous\n";
    } else if (dist > du) {
      fout << "Miss\n";
    } else {
      fout << "Perfect\n";
    }
  }
  return 0;
}
