#include <bits/stdc++.h>
using namespace std;
string s;
int sum;
int main() {
  freopen("agnus.in", "r", stdin);
  freopen("agnus.out", "w", stdout);
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i <= s.size() - 5 && s[i] == 'a' && s[i + 1] == 'g' && s[i + 2] == 'n' && s[i + 3] == 'u' && s[i + 4] == 's') {
      sum += (i + 1) * (s.size() - (i + 4));
    }
  }
  cout << sum;
  return 0;
}