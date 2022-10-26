#include <iostream>

using namespace std;

string a, b;
int n;

void S(string &x) {
  for (int l = n; l < x.size(); l <<= 1) {
    for (int i = 0; i < x.size(); i += l << 1) {
      if (x.substr(i + l, l) < x.substr(i, l)) {
        for (int j = i; j < i + l; ++j) {
          swap(x[j], x[j + l]);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  if (a == b) {
    cout << "YES";
    return 0;
  }
  if (a.size() & 1) {
    cout << "NO";
    return 0;
  }
  for (n = a.size() >> 1; !(n & 1); n >>= 1) {
  }
  S(a), S(b);
  cout << (a == b ? "YES" : "NO");
  return 0;
}