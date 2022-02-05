/*
ID: wsfxk.e1
LANG: C++
TASK: transform
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;
using _A = vector<char>;
using A = vector<_A>;

int n;
A a, b;

A R(A x) {
  A y = x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      y[j][n - i - 1] = x[i][j];
    }
  }
  return y;
/*
(0,0)->(0,n-1)
(0,1)->(1,n-1)
(0,i)->(i,n-1)
(2,1)->(1,n-1)
(2,2)->(2,n-1)
(2,3)->(3,n-1)
(1,i)->(i,n-2)
(i,j)->(j,n-i-1)
*/
}
A L(A x) {
  for (auto &i : x) {
    reverse(i.begin(), i.end());
  }
  return x;
}

int main() {
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  a = A(n, _A(n, ' ')), b = A(n, _A(n, ' '));
  for (auto &x : a) {
    for (auto &y : x) {
      cin >> y;
    }
  }
  for (auto &x : b) {
    for (auto &y : x) {
      cin >> y;
    }
  }
  if (R(a) == b) {
    cout << "1\n";
  } else if (R(R(a)) == b) {
    cout << "2\n";
  } else if (R(R(R(a))) == b) {
    cout << "3\n";
  } else if (L(a) == b) {
    cout << "4\n";
  } else if (L(R(a)) == b || L(R(R(a))) == b || L(R(R(R(a)))) == b) {
    cout << "5\n";
  } else if (a == b) {
    cout << "6\n";
  } else {
    cout << "7\n";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}