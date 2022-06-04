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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int t, r;
char o, c;
deque<char> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> o;
    if (o == '1') {
      cin >> c;
      if (r) {
        if (!q.empty() && q.front() == c) {
          q.pop_front();
        } else {
          q.push_front(c);
        }
      } else {
        if (!q.empty() && q.back() == c) {
          q.pop_back();
        } else {
          q.push_back(c);
        }
      }
    } else if (o == '2') {
      r ^= 1;
    } else {
      if (r) {
        for (int i = q.size() - 1; i >= 0; --i) {
          putchar(q[i]);
        }
      } else {
        for (int i = 0; i < q.size(); ++i) {
          putchar(q[i]);
        }
      }
      puts("");
    }
  }
  return 0;
}