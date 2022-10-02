#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxM = 5e4 + 5;

int n, m;
int ans1[kMaxM], ans2[kMaxM];

void check(int cs) {
  system("gen.exe");
  system("dandelion.exe");
  system("bf.exe");
  freopen("dandelion.in", "r", stdin);
  cin >> n >> m;
  fclose(stdin);
  freopen("dandelion.out", "r", stdin);
  for (int i = 1; i <= m; ++i) {
    cin >> ans1[i];
  }
  fclose(stdin);
  freopen("bf.out", "r", stdin);
  for (int i = 1; i <= m; ++i) {
    cin >> ans2[i];
  }
  fclose(stdin);
  for (int i = 1; i <= m; ++i) {
    if (ans1[i] != ans2[i]) {
      printf("Wrong Answer on #%d, LINE %d\n", cs, i);
      exit(0);
    }
  }
  printf("Accepted on #%d\n", cs);
}

int main() {
  int T = 10000;
  for (int i = 1; i <= T; ++i) {
    check(i);
  }
  return 0;
}