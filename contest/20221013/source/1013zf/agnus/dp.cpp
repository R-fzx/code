#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s, s2 = "agnus";

struct STR {
  string str;
  int l, r;
  bool operator<(const STR &_s) const { return str < _s.str || (str == _s.str && l < _s.l); }
} s3;

set<STR> st;

int main() {
  // freopen("agnus.in", "r", stdin);
  // freopen("agnus.out", "w", stdout);
  for (int l = 0; l <= 2; l++) {
    for (int mid = 0; mid <= 2; mid++) {
      for (int mid2 = 0; mid2 <= 2; mid2++) {
        for (int r = 0; r <= 2; r++) {
          s = "";
          for (int i = 1; i <= l; i++) {
            s += 't';
          }
          s += "agnus";
          for (int i = 1; i <= mid; i++) {
            s += 't';
          }
          s += "agnus";
          for (int i = 1; i <= mid2; i++) {
            s += 't';
          }
          s += "agnus";
          for (int i = 1; i <= r; i++) {
            s += 't';
          }
          for (int i = 0; i < s.length(); i++) {
            for (int j = 5; i + j <= s.length(); j++) {
              s3.str = s.substr(i, j);
              s3.l = i, s3.r = i + j - 1;
              bool flag = 0;
              for (int k = 0; k + 5 <= s3.str.length(); k++) {
                if (s3.str.substr(k, 5) == s2) {
                  flag = 1;
                  break;
                }
              }
              if (flag) {
                st.insert(s3);
              }
            }
          }
          // for (STR str : st) {
          //   cout << str.str << '\n';
          // }
          cout << s << ' ' << st.size() << '\n';
          st.clear();
        }
      }
    }
  }
  return 0;
}