#include <bits/stdc++.h>

#define aa 21

using namespace std;

int main() {
  freopen("maze.in", "w", stdout);
  cout << aa << ' ' << aa << ' ' << 3 << '\n';
  for (int i(0); i < aa; ++i) {
    for (int j(0); j < aa; ++j) {
      cout << (((i * i * i * i) % 1234 * aa) % 114514 + j * (j + 1)) % (aa * aa) << ' ';
    }
    cout << '\n';
  }
}