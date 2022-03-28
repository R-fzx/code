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

LL a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  a ^= 9961, b ^= 9961;
  a += 17, b += 17;
  b += a;
  a *= 81, b *= 81;
  LL s = a + b;
  s -= 2 * 3;
  s += 2;
  s = s / 10 * 10 + 1;
  cout << s % 9;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
题目背景
万宝槌拥有强大的力量，比如——将事物放大、缩小或改变颜色。

题目描述
输出它们分别与九千九百六十一异或后，将它们分别加上十七，再将第
一个数加到第二个数上，再分别乘以八十一，再求出它们
的和，再将和减去二乘三，加上八的立方根，将其个位设为四十五度的
正切值并对九取模得到的值。

输入格式
依次输入两个三十二位无符号整数。

输出格式
输出少名针妙丸和鬼人正邪想要求的值。
*/