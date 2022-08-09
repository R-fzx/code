#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const int kK = 21;  // k 的上界

struct LCT {                      // LCT 板子
  static const int kN = 1e5 + 1;  // 最大节点数

  struct E {
    double v[kK], s[kK];
    int f, c[2], r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) {
    for (int i = 0; i < kK; ++i) {
      e[x].s[i] = e[e[x].c[0]].s[i] + e[e[x].c[1]].s[i] + e[x].v[i];
    }
  }
  void Pr(int x) { swap(e[x].c[0], e[x].c[1]), e[x].r ^= 1; }
  void Pd(int x) { e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), 0), e[x].r = 0; }
  void R(int x) {
    int y = e[x].f, z = e[y].f, u = W(x), w = e[x].c[u ^ 1];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[u] = w, e[x].c[u ^ 1] = y;
    if (w) {
      e[w].f = y;
    }
    e[y].f = x, e[x].f = z, Pu(y), Pu(x);
  }
  void S(int x) {
    static int st[kN];
    int y = x, z = 0;
    for (; nR(y); st[++z] = y, y = e[y].f) {
    }
    for (Pd(y); z; Pd(st[z--])) {
    }
    for (; nR(x); R(x)) {
      y = e[x].f;
      if (nR(y)) {
        R(W(x) == W(y) ? y : x);
      }
    }
  }
  void A(int x) {
    for (int y = 0; x; y = x, x = e[x].f) {
      S(x), e[x].c[1] = y, Pu(x);
    }
  }
  void M(int x) {
    A(x), S(x), Pr(x);
  }
  int F(int x) {
    A(x), S(x);
    for (; e[x].c[0]; Pd(x), x = e[x].c[0]) {
    }
    S(x);
    return x;
  }
  void S(int x, int y) {
    M(x), A(y), S(y);
  }
  void L(int x, int y) {
    M(x), e[x].f = y;
  }
  void C(int x, int y) {
    S(x, y), e[y].c[0] = e[x].f = 0, Pu(y);
  }
} t;
int n, q;

void S(int x, int o, double a, double b) {  // 修改
  double f = 1, ma = 1;
  t.S(x);        // 先旋到根节点
  if (o == 1) {  // sin(ax+b)
    double cb = cos(b), sb = sin(b);
    for (int i = 0; i < kK; f *= ++i, ma *= a) {
      t.e[x].v[i] = ((i & 1) ? cb : sb) * ((i & 2) ? -1 : 1) * ma / f;  // sin 的导数循环节为 sin,cos,-sin,-cos
    }
  } else if (o == 2) {  // exp(ax+b)
    double eb = exp(b);
    for (int i = 0; i < kK; f *= ++i, ma *= a) {
      t.e[x].v[i] = eb * ma / f;  // exp 导数不变
    }
  } else {  // ax+b
    t.e[x].v[0] = b, t.e[x].v[1] = a;
    for (int i = 2; i < kK; ++i) {
      t.e[x].v[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << scientific << setprecision(8);
  char _;
  cin >> n >> q >> _ >> _;
  for (int i = 1, o; i <= n; ++i) {
    double x, y;
    cin >> o >> x >> y;
    S(i, o, x, y);
  }
  for (int x, y; q--;) {
    string o;
    double a, b;
    cin >> o >> x >> y;
    ++x, ++y;
    if (o[0] == 'a') {  // Link
      t.L(x, y);
    } else if (o[0] == 'd') {  // Cut
      t.C(x, y);
    } else if (o[0] == 'm') {  // 修改
      --y;
      cin >> a >> b;
      S(x, y, a, b);
    } else {  // 查询
      cin >> a;
      if (t.F(x) != t.F(y)) {  // 判断无解
        cout << "unreachable\n";
      } else {
        t.S(x, y);
        double v = 1, s = 0;
        for (int i = 0; i < kK; ++i, v *= a) {
          s += t.e[y].s[i] * v;  // 计算答案
        }
        cout << s << '\n';
      }
    }
  }
  return 0;
}