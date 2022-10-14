/**
 * @file codes.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Codes(problem in 0class contest)
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

int n, l = 400;
string s[25], a, b, ans = "1145141919810wssb";
void D(string x, string y) {
  if (x.size() == y.size()) {
    ans = x, l = ans.size();
  }
  if (x.size() < y.size()) {
    swap (x, y);
  }
  if (x.size() <= l) {
    for (int i = 1; i <= n; i++) {
      string r = y + s[i];
      for (int j = y.size(); j < min(x.size(), r.size()) && x[j] == r[j]; j++) {
        if (j == min(x.size(), r.size()) - 1) {
          D(x, r);
        }
      }
    }
  }
}
int main() {
  freopen("codes.in", "r", stdin);
  freopen("codes.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      a = s[i];
      b = s[j];
      for (int k = 0; k < min(a.size(), b.size()) && a[k] == b[k]; k++) {
        if (k == min(a.size(), b.size()) - 1) {
          D(a, b);
        }
      }
    }
  }
  cout << ans.size() << '\n' << ans << '\n';
  return 0;
}