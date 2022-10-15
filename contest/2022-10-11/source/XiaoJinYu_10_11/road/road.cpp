#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

int n, m, P, Q;

struct Node {
  int v, a, b;
};

vector<Node> a[MAXN];

bool f[MAXN];

bool getree(int x, int y) {
  for (int i = 0; i <= n; ++i) {
    f[i] = 0;
  }
  f[1] = 1;
  queue<int> q;
  
}

bool check(int mid) {
  
}

int main() {
  cin >> n >> m >> P >> Q;
  for (int i = 0; i < m; ++i) {

  }
  return 0;
}