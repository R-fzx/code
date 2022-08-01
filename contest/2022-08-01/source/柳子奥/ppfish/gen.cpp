#include <bits/stdc++.h>

using namespace std;

void randstr(int n) {
  for (int i = 1; i <= n; ++i) {
    putchar('a' + rand() * rand() % 26);
  }
  putchar('\n');
}

int main() {
  freopen("ppfish.in", "w", stdout);
  srand(time(NULL));
  int n = 20;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    randstr(20);
  }
  randstr(1000000);
  cout << "0.30" << ' ' << 5 << endl;
  return 0;
}