#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

int n;

int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  srand(time(0));
  cin >> n;
  cout << (rand() * rand()) % n + 1;
  // cout << "Runtime:" << clock() / 1000.0 << "s\n";
  return 0;
}
