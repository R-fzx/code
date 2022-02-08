#include <iostream>
#include <algorithm>

using namespace std;
using uLL = unsigned long long;

uLL x;
bool f = 0;

string ten2hex(uLL x) {
  string res;
  for (; x; x /= 16) {
    res += (x % 16 < 10 ? x % 16 + '0' : x % 16 - 10 + 'A');
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (char ch; cin >> ch;) {
    if (ch == '{') {
      cout << ch;
    } else if (ch == ',' || ch == '}') {
      if (f) {
        if (to_string(x).size() >= ten2hex(x).size() + 2) {
          cout << "0x" + ten2hex(x);
        } else {
          cout << x;
        }
      }
      x = 0;
      cout << ch;
    } else {
      x = x * 10 + ch - '0', f = 1;
    }
  }
  return 0;
}