/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-11 10:14:28
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-11 10:56:21
 * @FilePath: \hezewei1011\painting\painting.cpp
 * Copyright (c) 2022 by error: git config user.name & please set dead value or install git, All Rights Reserved.
 */
#include <iostream>

using namespace std;

const int kMaxN = 1e9 + 7;

int n, m, k;
long long ans, temp = 1;

int main() {
  freopen("painting.in", "r", stdin);
  freopen("painting.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= min(m, k); i++, temp = 1) {
    for (int j = 0; j < i; j++) {
      temp *= (k - j);
      temp %= kMaxN;
    }
    for (int j = 0; j < i; j++) {
      temp *= (i - j) * (m - j);
      temp %= kMaxN;
    }
    for (int j = i + 1; j <= m; j++) {
      temp *= i;
      temp %= kMaxN;
    }
    ans += temp;
    ans %= kMaxN;
  }
  cout << ans << endl;
  return 0;
}