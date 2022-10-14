#include <cstring>
#include <iostream>

using namespace std;

int n, Ans = 1e9 + 7, z[200001][21];
string a[21], s[200001];
short Used[200001][21];

int Change(string s) {
  int tmp = 0;
  for (int i = 0; i < s.length(); i++) {
    tmp <<= 1;
    tmp += (int)s[i] - 48;
  }
  return tmp;
}

int Find(string x, int ans, int Last) {
  if (x.length() == 0 || ans >= Ans) {
    Ans = min(ans, Ans);
    return 1;
  }
  int t = Change(x);
  if (Used[t][x.size()]) {
    return ans + z[t][x.size()];
  }
  Used[t][x.size()] = 1;
  for (int i = 0; i < n; i++) {
    if (i != Last) {
      bool b = 1;
      for (int j = 0; j < min(x.length(), a[i].length()) && b; j++) {
        if (x[j] != a[i][j]) {
          b = 0;
        }
      }
      if (b) {
        string tmp = "";
        if (x.length() > a[i].length()) {
          for (int j = min(x.length(), a[i].length()); j < max(x.length(), a[i].length()); j++) {
            tmp += x[j];
          }
        } else {
          for (int j = min(x.length(), a[i].length()); j < max(x.length(), a[i].length()); j++) {
            tmp += a[i][j];
          }
        }
        z[t][x.size()] = min(z[t][x.size()], Find(tmp, ans + min(x.length(), a[i].length()), i));
      }
    }
  }
  return z[t][x.size()] + 1;
}

int main() {
  freopen("codes.in", "r", stdin);
  freopen("codes.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    Used[Change(a[i])][a[i].size()] = z[Change(a[i])][a[i].size()] = 0;
    Find(a[i], 0, i);
  }
  cout << Ans;
  return 0;
}