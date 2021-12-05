#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

bool C(string s) {
  if (s == "x" || s == "xx") return 1;
  else if (s.find('o') == string::npos) return 0;
  for (char ch : s)
    if (ch != 'o' && ch != 'x') return 0;
  int b = s.find('o');
  if (b > 2) return 0;
  for (; b + 2 < s.size(); b += 3) {
    if (s[b] != 'o' || s[b + 1] != 'x' || s[b + 2] != 'x') return 0;
  }
  for (++b; b < s.size(); ++b) {
    if (s[b] != 'x') return 0;
  }
  return 1;
}

int main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  string s;
  cin >> s;
  cout << (C(s) ? "Yes" : "No");
  return 0;
}