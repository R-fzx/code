#include <bits/stdc++.h>
using namespace std;
bool b[25];
int a[25];
int n;
int sum = 0;
bool c[25];
vector<string> v;
void dfs(int x) {
  if (x == n + 1) {
    for (int i = 2; i < n; i++) {
      if (!((a[i - 1] > a[i] && a[i + 1] > a[i]) || (a[i - 1] < a[i] && a[i + 1] < a[i]))) {
        return;
      }
    }
    string s;
    for (int i = 1; i <= n; i++) {
      s += (char)(a[i] + 'a');
    }
    v.push_back(s);
    return;
  }
  if (c[x] == 1) {
    for (int i = a[x - 1]; i <= n; i++) {
      if (b[i] == 0) {
        a[x] = i;
        b[i] = 1;
        dfs(x + 1);
        b[i] = 0;
      }
    }
  } else {
    for (int i = a[x - 1]; i >= 1; i--) {
      if (b[i] == 0) {
        a[x] = i;
        b[i] = 1;
        dfs(x + 1);
        b[i] = 0;
      }
    }
  }
}
int main() {
  freopen("wave.in", "r", stdin);
  freopen("wave.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    while (v.size() > 0) {
      v.pop_back();
    }
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      c[i] = 1;
    }
    for (int i = 2; i <= n; i += 2) {
      c[i] = 0;
    }
    a[0] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
      c[i] = 1;
    }
    for (int i = 1; i <= n; i += 2) {
      c[i] = 0;
    }
    a[0] = n;
    dfs(1);
    sort(v.begin(), v.end());
    for (int i = 0; i < v[m - 1].size(); i++) {
      cout << (int)(v[m - 1][i] - 'a') << " ";
    }
    cout << endl;
  }
}