#include <bits/stdc++.h>
using namespace std;
int N, L, K, v[209];
double p[209];
int main() {
  freopen("guard.in", "w", stdout);  // freopen("guard.out", "w", stdout);
  int N(100);
  cout << N << ' ' << rand() % 10 << ' ' << rand() % 10 << '\n';
  for (int i(0); i < N; i++) cout << i << ' ';
  puts("");
  for (int i(0); i < N; i++) cout << (i % 2 ? 34 : -1) << ' ';
  return 0;
}