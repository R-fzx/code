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
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <fstream>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

ofstream in("maze.in");

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  in << "1\n1000";
  int n = 100;
  in << ' ' << n << ' ' << n << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == 1 || j == 1 || i == n || j == n) {
        in << '#';
      } else if (i == 2 && j == 2) {
        in << 'S';
      } else if (i == n - 1 && j == n - 1) {
        in << 'E';
      } else {
        in << (rand() % 5 ? ' ' : '#');
      }
    }
    in << '\n';
  }
  return 0;
}