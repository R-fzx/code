/*
ID: wsfxk.e1
LANG: C++
TASK: wormhole
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using Pii = pair<int, int>;

const int kN = 13;

int n, s, p[kN], r[kN];
Pii a[kN];

bool C(int x) {
  int i = x;
  do {
    i = r[p[i]];
  } while (i && i != x);
  return i;
}
void S(int x) {
  if (x > n) {
    bool f = 0;
    for (int i = 1; i <= n; ++i) {
      f |= C(i);
    }
    s += f;
    return;
  }
  if (p[x]) {
    S(x + 1);
    return;
  }
  for (int i = x + 1; i <= n; ++i) {
    if (!p[i]) {
      p[i] = x, p[x] = i, S(x + 1), p[i] = p[x] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i].first >> a[i].second;
  }
  a[0].first = INT32_MAX;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i].second == a[j].second && a[i].first < a[j].first && a[j].first < a[r[i]].first) {
        r[i] = j;
      }
    }
  }
  S(1);
  fout << s << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}