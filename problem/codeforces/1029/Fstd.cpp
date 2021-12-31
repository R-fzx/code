#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 1000 * 1000;

int lens[N];
int k;

li solve(li a, li b) {
  k = 0;
  for (li i = 1; i * i <= b; ++i)
    if (b % i == 0)
      lens[k++] = i;

  li ans = 2 * (a + b) + 2;
  li x = a + b;
  int l = 0;
  for (li i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      while (l + 1 < k && lens[l + 1] <= i)
        ++l;
      if (b / lens[l] <= x / i)
        ans = min(ans, (i + x / i) * 2);
    }
  }

  return ans;
}

int main() {
  li a, b;
  scanf("%lld%lld", &a, &b);
  printf("%lld\n", min(solve(a, b), solve(b, a)));
  return 0;
}