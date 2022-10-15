/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-11 08:30:19
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-11 08:49:20
 * @FilePath: \hezewei1011\assembly\assembly.cpp
 * Copyright (c) 2022 by error: git config user.name & please set dead value or install git, All Rights Reserved.
 */
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n, k, A, a, b;
vector<pair<double, double>> v;
double ans = 0;

double Count(double num, int dep, int alive) {
  if (dep == n) {
    return num / max(alive, 1);
  }
  return Count(num + v[dep].first / 100.000 * v[dep].second / (v[dep].second + A), dep + 1, alive + 1) + Count(num + A / (v[dep].second + A), dep + 1, alive);
}

void Find(int dep, int Last) {
  if (dep == k) {
    ans = max(ans, Count(0, 0, 0));
  }
  for (int i = Last; i < n; i++) {
    if (v[i].first < 100) {
      v[i].first += 10;
      Find(dep + 1, i);
      v[i].first -= 10;
    }
  }
}

int main() {
  freopen("assembly.in", "r", stdin);
  freopen("assembly.out", "w", stdout);
  cin >> n >> k >> A;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  Find(0, 0);
  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}