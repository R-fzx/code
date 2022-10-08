#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;

int S[201], E[201], num1, num2;
vector<int> line[201],F[201], ans, temp1, temp2;
int Move[201];

// int Find(int x, int color) {
//   if (Move[x]) {
//     return Move[x];
//   }
//   Move[x] = color;
//   for (int i = 0; i < line[x].size(); i++) {
//     Find(x, )
//   }
// }

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (!E[a]) {
      num1--;
    }
    if (!S[b]) {
      num2--;
    }
    E[a] = S[b] = 1;
    line[a].push_back(b);
    line[b].push_back(a);
  }
  // for (int i = 0; i < m; i++) {
  //   if (!S[i] && !E[i]) {
  //     ans.push_back(i);
  //   } else if (!S[i]) {
  //   }
  // }
  if (num1 > num2) {
    cout << num1 << endl;
    for (int i = 1; i <= n; i++) {
      if (!E[i]) {
        cout << i << ' ';
      }
    }
  } else {
    cout << num2 << endl;
    for (int i = 1; i <= n; i++) {
      if (!S[i]) {
        cout << i << ' ';
      }
    }
  }
  return 0;
}