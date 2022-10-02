#include <iostream>

using namespace std;

int n, ans, len[22000001];
string s, _s;

void Extend() {
  n = _s.length() * 2 + 1, s = string(n, ' ');
  for (int i = 0; i < n; i++) {
    s[i] = i & 1 ? _s[i / 2] : '#';
  }
}

void CalcLen() {
  for (int k = 0, i, j = 0; k < n; k++) {
    if (k < j) {
      int l = len[i * 2 - k];
      if (k + l < j) {
        len[k] = l;
        continue;
      }
    } else {
      j = k;
    }
    for (i = k; j < n && j <= i * 2 && s[j] == s[i * 2 - j]; j++) {
    }
    len[k] = j - i;
  }
}

int main() {
  cin >> _s;
  Extend();
  CalcLen();
  for (int i = 0; i < n; i++) {
    ans = max(ans, len[i]);
  }
  cout << ans - 1;
  return 0;
}
