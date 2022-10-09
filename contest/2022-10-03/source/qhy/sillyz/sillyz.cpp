#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;
using ll = long long;

const int kMaxN = 1e6 + 1;

int a, b, maxn, ans;
map <int, int> f;

void work(int x) {
  int ans = x;
  for (int i = x; i; i /= 10) {
    ans *= i % 10;
  }
  if () {
    f[ans]++; 
  }
}

int main() {
  ifstream cin("sillyz.in");
  ofstream cout("sillyz.out");
  cin >> a >> b;
  for (maxn = 10; maxn < b; maxn *= 10) {
  }
  for (int i = 1; i <= maxn; i++) {
    work(i);
  }
  for (int i = a; i <= b; i++) {
    ans += f[i];
  }
  cout << ans << endl;
  return 0;
}