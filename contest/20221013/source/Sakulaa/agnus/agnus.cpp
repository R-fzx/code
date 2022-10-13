#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int ans, last = -1;
string s;

int main() {
  freopen("agnus.in", "r", stdin);
  freopen("agnus.out", "w", stdout);
  cin >> s;
  for (int i = 0; i + 4 < s.length(); i++) {
    if (s.substr(i, 5) == "agnus") {
      if (last != -1) {
        ans += (i - last) * (s.length() - i - 4); 
      } else {
        ans += (i + 1) * (s.length() - i - 4);
      }
    }
  }
  cout << ans;
  return 0;
}
