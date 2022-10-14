#include <algorithm>
#include <fstream>
#include <queue>
#include <unordered_map>

using namespace std;
using LL = long long;

ifstream fin("codes.in");
ofstream fout("codes.out");

const int kMaxN = 21, kInf = 1e9;

struct E {
  int s1, s2, l, i, j;
  bool operator<(const E &_e) const { return l > _e.l; }
} e;
unordered_map<long long, int> d;
string s[kMaxN], anss;
int n, ans = kInf;

bool C(string &p, int l, string &q) {
  int r = min(l + q.size(), p.size());
  return r <= l || p.substr(l, r - l) == q.substr(0, r - l);
}

LL V(E &e) {
  LL v = e.j;
  v = v << n | e.s1;
  v = v << n | e.s2;
  return v * n + e.i;
}

int W(string anss) {
  d.clear();
  priority_queue<E> h;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i].size() >= s[j].size() && i != j) {
        if (C(s[i], 0, s[j]) && C(anss, 0, s[i])) {
          h.push((E){1 << i, 1 << j, (int)s[i].size(), i, (int)s[j].size()});
        }
      }
    }
  }
  while (!h.empty() && h.top().l <= ans) {
    e = h.top(), h.pop();
    LL v = V(e);
    if (!d.count(v) || e.l < d[v]) {
      d[v] = e.l;
      if (e.j == s[e.i].size()) {
        return e.l;
      }
      for (int k = 0; k < n; k++) {
        if (!(e.s2 >> k & 1) && C(s[e.i], e.j, s[k]) && C(anss, e.l - s[e.i].size() + e.j, s[k])) {
          if (e.j + s[k].size() > s[e.i].size()) {
            h.push((E){e.s2 | 1 << k, e.s1, e.l + e.j + (int)s[k].size() - (int)s[e.i].size(), k, (int)s[e.i].size() - e.j});
          } else {
            h.push((E){e.s1, e.s2, e.l, e.i, e.j + (int)s[k].size()});
          }
        }
      }
    }
  }
  return kInf;
}

int main() {
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> s[i];
  }
  do {
    int a0 = W(anss + '0'), a1 = W(anss + '1');
    anss += a0 <= a1 ? '0' : '1';
    ans = min(ans, min(a0, a1));
  } while (anss.size() < ans);
  fout << ans << '\n';
  fout << anss;
  return 0;
}