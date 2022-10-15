#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 1e5 + 1;

int n, m, a[N], s[N];
double ans = 1;
unordered_set<int> st;

int main() {
  freopen("vote.in", "r", stdin);
  freopen("vote.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    s[a[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    st.insert(i);
  }
  while (1) {
    int maxx = 0, sum = 0;
    for (int i : st) {
      maxx = max(maxx, s[i]);
      sum += s[i];
    }
    bool f = 0;
    vector<int> v;
    for (int i : st) {
      if (s[i] != maxx) {
        v.push_back(i);
        f = 1;
      }
    }
    for (int i : v) {
      st.erase(i);
    }
    if (st.size() == 1) {
      cout << "1.0000";
      return 0;
    }
    if (!f) {
      cout << "0.0000";
      return 0;
    }
  }
  cout << "1.0000";
  return 0;
}