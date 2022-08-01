#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#define LL long long

using namespace std;

struct V {
  int p, d, s[26];
} v[2000001];
int n, m, k, c[201] = {1919810}, d[201], l[201], num[1001][1001];
double p, ans[201];
string s, t[201];
queue<int> q;

int Push(string s) {
  int p = 0;
  for (int j = 0; j < s.size(); j++) {
    if (!v[p].s[s[j] - 'a']) {
      v[p].s[s[j] - 'a'] = ++k;
    }
    p = v[p].s[s[j] - 'a'];
  }
  return p;
}

int main() {
  freopen("ppfish.in", "r", stdin);
  freopen("ppfish.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    l[i] = v[Push(t[i])].d = i;
  }
  cin >> s >> p >> m;
  Push(s);
  for (q.push(0); !q.empty(); q.pop()) {
    int x = q.front();
    for (int i = 0; i < 26; i++) {
      int y = v[x].s[i];
      if (y) {
        q.push(y);
        if (x) {
          int z = v[x].p;
          for (; z && !v[z].s[i]; z = v[z].p) {
          }
          v[y].p = v[z].s[i];
        }
      }
    }
  }
  for (int i = 0, p = 0; i < s.size(); i++) {
    p = v[p].s[s[i] - 'a'];
    for (int j = p; j; j = v[j].p) {
      c[v[j].d]++;
    }
  }
  sort(l + 1, l + n + 1, [](int i, int j) { return c[i] < c[j]; });
  for (int i = 1; i <= n; i++) {
    d[l[i]] = d[l[i - 1]] + (c[l[i]] != c[l[i - 1]]);
  }
  fill(&num[0][0], &num[0][1000] + 1, 1);
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      num[i][j] = num[i - 1][j - 1] + num[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ans[i] += pow(0.7, j - 1) * pow(0.3, m - j + 1) * num[j - 1][m];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(3) << ans[d[i]] << ' ';
  }
  return 0;
}
