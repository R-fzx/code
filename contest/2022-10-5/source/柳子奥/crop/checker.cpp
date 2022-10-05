#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

using namespace std;

void check(int cs) {
  system("gen.exe");
  system("crop.exe");
  system("bf.exe");
  long long ans1, ans2;
  freopen("crop.out", "r", stdin);
  cin >> ans1;
  fclose(stdin);
  freopen("bf.out", "r", stdin);
  cin >> ans2;
  fclose(stdin);  
  if (ans1 == ans2) printf("Accepted on #%d\n", cs);
  else {
    puts("Wrong Answer");
    exit(0);
  }
}

int main() {
  int T = 5000;
  for (int i = 1; i <= T; ++i) {
    check(i);
  }
  return 0;
}