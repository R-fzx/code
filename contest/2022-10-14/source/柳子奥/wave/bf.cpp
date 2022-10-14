#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

int T, n, c;
int a[25];

int main() {
  freopen("wave.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
      a[i] = i;
    }
    do {
      if (a[1] == 1 && a[2] == 5 && a[3] == 3 && a[4] == 2 && a[5] == 6 && a[6] == 4) debug("????");
      for (int i = 2; i <= n - 1; ++i) {
        if (!(a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1])) goto FUCK;
      }
      --c;
      if(c<=10){
      for (int i = 1; i <= n; ++i) {
        cerr << a[i] << ' ';
      }
      cerr << endl;}
      if (!c) break ;
      FUCK:;
    } while (next_permutation(a + 1, a + 1 + n));
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}