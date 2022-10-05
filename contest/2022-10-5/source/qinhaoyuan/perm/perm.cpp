#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

string s;
int ton[10], cnt;
int f[51];
ll sumn, ans;

ll A(int n) {
  ll ans = 1;
  for (int i = 2; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

int main() {
  ifstream cin("perm.in");
  ofstream cout("perm.out");
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--) {
    ton[s[i] - '0']++;
    int tmp = 0;
    for (int j = 0; j < s[i] - '0'; j++) {
      tmp += (bool)ton[j];
    }
    ans += (ll)tmp * A(s.size() - i - 1);
  }
  // sumn = A(s.size());
  // for (int i = 1; i <= 9; i++) {
  //   sumn /= A(ton[i]), cnt += ton[i];
  // }
  // f[cnt] = sumn;
  // for (int i = cnt + 1; i < s.size(); i++) {
  //   f[i] = f[i - 1] * (i - 1);
  // }
  cout << ans << endl;
  return 0;
}