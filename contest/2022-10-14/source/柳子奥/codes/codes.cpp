#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

int n, sz;
int t[25];
string s[25], ans, tmp[25];
map<string, bool> mp;

int main() {
  freopen("codes.in", "r", stdin);
  freopen("codes.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < (1 << n); ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (i >> (j - 1) & 1) {
        tmp[++cnt] = s[j], t[cnt] = cnt;
      }
    }
    do {
      string nw = "";
      for (int j = 1; j <= cnt; ++j) {
        nw += tmp[t[j]];
      }
      if (mp[nw]) {
        // ans = min(ans, nw);
        if (!sz || (int)nw.size() < sz) {
          sz = nw.size(), ans = nw;
        } else if ((int)nw.size() == sz && nw < ans) {
          ans = nw;
        }
      }
      mp[nw] = 1;
    } while (next_permutation(t + 1, t + 1 + cnt));
  }
  cout << sz << endl << ans << endl;
  return 0;
}