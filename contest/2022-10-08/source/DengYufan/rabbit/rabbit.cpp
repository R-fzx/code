#include <iostream>

using namespace std;

int n;

int main() {
  freopen("rabbit.in", "r", stdin);
  freopen("rabbit.out", "w", stdout);
  cin >> n;
  cout << n * (n - 1) / 2 << '\n';
  return 0;
}
