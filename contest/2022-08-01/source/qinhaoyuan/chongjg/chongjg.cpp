#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

const int kMaxN = 1e3 + 1;

int n, m;

int main() {
  ifstream cin("chongjg.in");
  ofstream cout("chongjg.out");

  cin >> n >> m;
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      cout << ('A' + (i % 2));
    }
  } else if (m == 1) {
    for (int i = 0; i < n; i++) {
      cout << ('A' + (i % 2)) << endl;
    }
  }
  return 0;
}