#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 201;

int n, m;
string a[kN];
char ans[kN];
vector<int> l[kN];

bool C(string &s) {
  // cout << s << endl;
  for (int i = 1; i < n; ++i) {
    if (a[l[i][0]] != s.substr(0, i)) {
      swap(l[i][0], l[i][1]);
    }
    if (a[l[i][0]] != s.substr(0, i)) {
      return 0;
    }
    ans[l[i][0]] = 'P', ans[l[i][1]] = 'S';
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  m = n - 1 << 1;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    l[a[i].size()].push_back(i);
  }
  string s1 = a[l[n - 1][0]][0] + a[l[n - 1][1]], s2 = a[l[n - 1][1]][0] + a[l[n - 1][0]];
  C(s1) || C(s2);
  // for (int i = 1; i < n; ++i) {
  //   cout << l[i][0] << " " << l[i][1] << endl;
  // }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i];
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}