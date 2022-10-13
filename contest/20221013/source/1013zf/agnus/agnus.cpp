#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s, s2 = "agnus";
int l1, l2, cnt, pos[6005];
ll ans;

struct STR {
  string str;
  int l, r;
  bool operator<(const STR &_s) const { return str < _s.str || (str == _s.str && l < _s.l); }
} s3;

set<STR> st;

int main() {
  freopen("agnus.in", "r", stdin);
  freopen("agnus.out", "w", stdout);
  cin >> s;
  l1 = s.length(), l2 = s2.length();
  for (int i = 0; i < s.length(); i++) { // 枚举开始位置
    s3.str = s.substr(i, 4);
    s3.l = i, s3.r = i + 4 - 1;
    bool flag = 0;
    for (int j = 4; i + j < s.length(); j++) { // 枚举长度
      s3.str += s[i + j], s3.r++;
      if (!flag) {
        for (int k = 0; k + 5 - 1 < s3.str.length(); k++) { // 枚举是否满足要求
          if (s3.str.substr(k, 5) == s2) {
            flag = 1;
            break;
          }
        }
      }
      if (flag) {
        st.insert(s3);
      }
    }
  }
  cout << st.size();
  return 0;
}