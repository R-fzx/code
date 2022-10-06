#include <iostream>

using namespace std;

int n, m[11], ans[11], c[11], d[100001], prime[100001];
string l, r, s;

void M() {
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i] - '0'; j++) {
      
    }
  }
}

int main() {
  cin >> l >> r;
  for (int i = 2; i <= 100000; i++) {
    if (!prime[i]) {
      for (int j = 1; i * j <= 100000; j++) {
        !prime[i * j] && (prime[i * j] = i);
      }
    }
  }
  for (n = l.size() - 1; n >= 0 && l[n] == '0'; n--) {
    l[n] = '9';
  }
  l[n]--;
  s = l, M();
  copy(ans, ans + 11, m), fill(ans, ans + 11, 0);
  s = r, M();
  for (int i = 1; i < 11; i++) {
    cout << ans[i] - m[i] << ' ';
  }
  return 0;
}
