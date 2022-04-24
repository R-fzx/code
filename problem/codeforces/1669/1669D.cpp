#include <iostream>

using namespace std;

int t, n;
string s;

bool C() {
  bool b[2] = {0, 0};  // 两种颜色有没有在这一段出现
  for (int i = 0, j = 0; i < n; j = ++i) {
    for (; i < n && s[i] != 'W'; ++i) {  // 根据 W 分割段
      if (s[i] == 'R') {
        b[0] = 1;
      } else if (s[i] == 'B') {
        b[1] = 1;
      }
    }
    if (b[0] ^ b[1]) {  // 若只出现了一种颜色
      return 0;         // 无法构造
    } else {
      b[0] = b[1] = 0;
    }
  }
  return 1;  // 否则可以构造
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    s += "W", ++n;  // 添加边界，方便处理
    cout << (C() ? "YES" : "NO") << endl;
  }
  return 0;
}