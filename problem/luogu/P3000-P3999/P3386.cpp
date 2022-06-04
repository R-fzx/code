#include <iostream>
#include <vector>

using namespace std;

const int kN = 1001;

int n[2], m, p[kN], v[kN], _v, c;
vector<int> ne[kN];

bool F(int x) {
  if (v[x] ^ _v) {
    v[x] = _v;
    for (int i : ne[x]) {
      if (!p[i] || F(p[i])) {
        p[i] = x, p[x] = i;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n[0] >> n[1] >> m;
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    b += n[0], ne[a].push_back(b), ne[b].push_back(a);
  }
  for (int i = 1; i <= n[0]; ++i) {
    ++_v, c += F(i);
  }
  cout << c;
  return 0;
}