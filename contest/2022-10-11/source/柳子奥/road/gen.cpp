#include <bits/stdc++.h>

using namespace std;

int random(int x) {
  return llabs(rand() * rand()) % x + 1;
}

int main() {
  srand(114514);
  freopen("road.in", "w", stdout);
  int n = 5, m = 10, p = 1145140, q = 1919810;
  cout << n << ' ' << m << ' ' << p << ' ' << q << endl;
  for (int i = 1; i <= m; ++i) {
    int l = rand() % n + 1, r = rand() % n + 1, a = random(1000000000), b = random(1000000000); 
    cout << l << ' ' << r << ' ' << a << ' ' << b << endl;
  }
  return 0;
}