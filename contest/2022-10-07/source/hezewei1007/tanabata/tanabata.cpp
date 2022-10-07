#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

long long x, y, t, a, b;
vector<pair<long long, long long>> shop;

long long row() {
  list<long long> add;
  long long val[100001] = {0}, ans = 0;

  sort(shop.begin(), shop.end());
  for (long long i = 0; i < t; i++) {
    val[shop[i].first]++;
  }
  for (long long i = 1; i <= x; i++) {
    val[i] -= t / x;
    if (val[i] > 0) {
      add.push_back(i);
    }
  }
  for (long long i = 1; i <= x; i++) {
    if (val[i] < 0) {
      while (val[i] + val[add.front()] <= 0 && !add.empty()) {
        ans += val[add.front()] * (min(min(abs(i - add.front()), abs(i + x - add.front())), abs(i - x - add.front())));
        val[i] += val[add.front()];
        add.pop_front();
      }
      if (val[i] == 0 || val[add.front()] + val[i]) {
        ans += (-val[i]) * (min(min(abs(i - add.front()), abs(i + x - add.front())), abs(i - x - add.front())));
        val[add.front()] += val[i];
      }
    }
  }
  return ans;
}

long long column() {
  list<long long> add;
  long long val[100001] = {0}, ans = 0;

  sort(shop.begin(), shop.end(), [](pair<long long, long long> a, pair<long long, long long> b) { return a.second < b.second; });
  for (long long i = 0; i < t; i++) {
    val[shop[i].second]++;
  }
  for (long long i = 1; i <= y; i++) {
    val[i] -= t / y;
    if (val[i] > 0) {
      add.push_back(i);
    }
  }
  for (long long i = 1; i <= y; i++) {
    if (val[i] < 0) {
      while (val[i] + val[add.front()] <= 0 && !add.empty()) {
        ans += val[add.front()] * (min(min(abs(i - add.front()), abs(i + y - add.front())), abs(i - y - add.front())));
        val[i] += val[add.front()];
        add.pop_front();
      }
      if (val[i] == 0 || val[add.front()] + val[i]) {
        ans += (-val[i]) * (min(min(abs(i - add.front()), abs(i + y - add.front())), abs(i - y - add.front())));
        val[add.front()] += val[i];
      }
    }
  }
  return ans;
}

int main() {
  freopen("tanabata.in", "r", stdin);
  freopen("tanabata.out", "w", stdout);
  cin >> x >> y >> t;
  for (long long i = 0; i < t; i++) {
    cin >> a >> b;
    shop.push_back({a, b});
  }
  if (t % x == 0 && t % y == 0) {
    cout << "both" << ' ' << row() + column() << endl;
  } else if (t % x == 0) {
    cout << "row" << ' ' << row() << endl;
  } else if (t % y == 0) {
    cout << "column" << ' ' << column() << endl;
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}