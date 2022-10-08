#include <fstream>

using namespace std;

ifstream fin("rabbit.in");
ofstream fout("rabbit.out");

const int kMaxN = 1000;

int a[kMaxN][kMaxN], n, ans, t, b[kMaxN * kMaxN];

void S(int x) {
  for (int i  =1; i <= n; i++) {
    if (a[x][i]) {
      a[x][i]--, a[i][x]--;
      S(i);
      b[++t] = x;
    }
  }
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = (i != j) * 2;
    }
  }
  S(1);
  for (int i = 1; i <= t; i++) {
    fout << b[i] << ' ';
  }
  return 0;
}