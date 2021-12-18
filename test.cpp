#include <map>
#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

int n, m, a[kN], v, s;
LL ans;
map<int, LL> p = {{0, 1}};

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == m) v = i;
  }
  for (int i = 1; i < v; ++i) {
    ++p[s += (a[i] > m ? -1 : 1)];
  }
  for (int i = v; i <= n; ++i) {
    s += (a[i] > m ? -1 : 1), ans += p[s] + p[s - 1];
  }
  printf("%lld", ans);
  return 0;
}