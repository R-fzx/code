/**
 * @file agnus.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief agnus (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

string s;
int l, p;
long long ans;
bool t[int(3e4 + 5)];
int main() {
  freopen("agnus.in", "r", stdin);
  freopen("agnus.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> s, l = s.size ();
  for (int i = 0; i < l - 4; i++) {
    if (s[i] == 'a' && s[i + 1] == 'g' && s[i + 2] == 'n' && s[i + 3] == 'u' && s[i + 4] == 's') {
      t[i] = t[i + 1] = t[i + 2] = t[i + 3] = t[i + 4] = true;
    }
  }
  for (int i = 0; i < l; i++) {
    if (t[i]) {
      i += 4;
      ans += (p + 1) * (l - i);
      p = 4;
    } else {
      p++;
    }
  }
  cout << ans << '\n';
  return 0;
}