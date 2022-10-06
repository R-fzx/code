#include <iostream>

using namespace std;

const int kMaxN = 1e9 + 9;

int n, m, a, b, line[200001];
long long ans;

struct Dot {
  int f;
  long long ans;
} d[200001];

int Find(int x) {
  if (d[x].f != x) {
    d[x].f = Find(d[x].f);
  }
  return d[x].f;
}

bool Check(int x, int y) {
  return Find(y) == Find(x);
}

void Add(int x, int y) {
  d[Find(y)].f = Find(x);
}

int main() {
  freopen("magician.in", "r", stdin);
  freopen("magician.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    d[i].f = i;
  }
  while (m--) {
    cin >> a >> b;
    if (Check(a, b)) {
      ans += d[Find(a)].ans + 1;
      ans %= kMaxN;
      d[Find(a)].ans *= 2;
      d[Find(a)].ans %= kMaxN;
      d[Find(a)].ans++;
      d[Find(a)].ans %= kMaxN;
    } else {
      Add(a, b);
    }
    cout << ans << endl;
  }
  return 0;
}