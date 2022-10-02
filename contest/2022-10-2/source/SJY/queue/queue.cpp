#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#define re register

using namespace std;

const int N = 3e2 + 5;

long long n, q[N];
double ans;
long long s, t;

inline long long read() {
  int sum = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();

  }
  while (ch >= '0' && ch <= '9') {
    // cout << 1;
    sum = (sum << 1) + (sum << 3) + (ch ^ 48);
    ch = getchar();
  }
  return sum;
}

int main() {
  srand(time(NULL));
  freopen("queue.in", "r", stdin);
  freopen("queue.out", "w", stdout);
  n = read();
  for (re int i = 1; i <= n; ++i) {
    q[i] = read();
  } 

  while (clock() < 970) {
    ++t;
    random_shuffle(q + 1, q + n + 1);
    re int sum = 0;
    for (re int i = 1; i <= n; ++i) {
      ++s;
      re int j = i - 1;
      while (q[j] < q[i] && j > 0) {
        ++s;
        --j;
      }
    }
  }
  double temp = s * 1.0 / t;
  long long t = (long long)(temp * 100 + 0.5);
  cout << t / 100.0;
  return 0;
}