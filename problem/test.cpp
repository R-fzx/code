#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int main() {
  vector<int> v{1, 2, 3, 4, 5};
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < 5; ++i) cout << v[i] << " ";
  return 0;
}