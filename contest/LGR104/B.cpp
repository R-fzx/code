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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

LL n, a, b, c;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b >> c;
  cout << min(c + n + abs(n - c - 1), n + n - 1 + b - a + 1);
  return 0;
}
/*
A A A A A
A B B B T
A B B B A
A B B B A
A B B B A
S B B B A
*/