#include <iostream>
using namespace std;
int main() {
  freopen("test.in", "w", stdout);
  ios_base::sync_with_stdio(0), cout.tie(0);
  cout << 10000000 << '\n';
  for (int i = 1; i <= 10000000; ++i) {
    cout << i << '\n';
  }
  return 0;
}

