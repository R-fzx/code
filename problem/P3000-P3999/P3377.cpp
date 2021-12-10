#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 1e5 + 1;

struct FibHeap {
  struct E {
    int v, d, l, r;
    vector<int> s;
  } e[kN];
  int c, rt, mn;

  int Create(int v) { return ++c, e[c] = {v, 0, c, c, {}}, c; }
  void Build() { mn = rt = Create(INT32_MAX); }
  void Merge(const FibHeap &o) {
    int lx = e[x].l, ly = e[y].l;
    e[lx].r = y, e[y].l = lx, e[x].l = ly, e[ly].r = x;
  }
  void Insert(int v) {Merge(rt, (Create(v), e[mn].v > v && (mn = c), c));}
};

int main() {
  less<int>()(1, 2);
  return 0;
}