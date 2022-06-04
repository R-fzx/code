#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;

const int kN = 11;

struct P {
  /**
   * 2: MP, 1: ZP, 0: FP
   */
  int ty, hp, ne, pr;  // 身份，血量，下一个人，上一个人
  bool jp, sf, zg;         // 跳没跳，是否是类反猪，有没有猪哥连弩
  vector<char> l;
} a[kN];
int n, m;
vector<char> p;
string s;

char C() {
  char x = p.back();
  if (p.size() > 1) {
    p.pop_back();
  }
  return x;
}
void Force(int x, char p) {
  // TODO: 强制出牌
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    a[i] = {s == "MP" ? 2 : s == "ZP", 4, i % n + 1, (i + n - 2) % n + 1, i == 1}, a[i].l.resize(4);
    for (char &j : a[i].l) {
      cin >> j;
    }
  }
  p.resize(m);
  for (int i = m - 1; i >= 0; --i) {
    cin >> p[i];
  }
  for (int i = 1, d = 0; ; i = a[i].ne) {
    d = (i == 1 ? 0 : d + 1);
    a[i].l.push_back(C()), a[i].l.push_back(C());
    bool uk = 0;
    vector<char> _l;
    for (char j : a[i].l) {
      if (j == 'P') {
        if (a[i].hp < 4) {
          ++a[i].hp;
        } else {
          _l.push_back('P');
        }
      } else if (j == 'N' || j == 'W') {
        Force(i, j == 'N' ? 'K' : 'D');
      } else if (j == 'Z') {
        a[i].zg = 1;
      } else {
        if (a[i].ty == 2) {

        } else if (a[i].ty == 1) {

        } else {
          if (j == 'K') {
            
          }
        }
      }
    }
    a[i].l = _l;
  }
  cout << (a[1].hp ? 'M' : 'F') << "P\n";
  for (int i = 1; i <= n; ++i) {
    if (a[i].hp <= 0) {
      cout << "DEAD\n";
    } else {
      for (char j : a[i].l) {
        cout << j;
      }
      cout << '\n';
    }
  }
  return 0;
}