# include <bits/stdc++.h>
# define ll unsigned long long
# define mod 
using namespace std;

struct Big_int {
  int p[17];
} c[100];
int p[50], pk;
bool vp[100];

void operator *= (Big_int &a, Big_int b) {
  for (int i = 1; i <= pk; i++) {
    a.p[i] += b.p[i];
  }
}

void operator /= (Big_int &a, Big_int b) {
  for (int i = 1; i <= pk; i++) {
    a.p[i] -= b.p[i];
  }
}

void F(ll a, Big_int &re) {
  for (int i = 1; i <= pk && p[i] <= a; i++) {
    while (a % p[i] == 0) {
      a /= p[i];
      re.p[i]++;
    }
  }
}

ll Z(Big_int &x) {
  ll re = 1;
  for (int i = 1; i <= pk; i++) {
    for (int j = 1; j <= x.p[i]; j++) {
      re *= p[i];
    }
  }
  return re;
}

int n, ans;
char in[100];
int s[100];
int vis[100];

ll work() {
  // for (int i = 1; i <= 9; i++) {
  //   printf("%d ", vis[i]);
  // }printf("\n");
  Big_int x;
  for (int i = 1; i <= 15; i++) {
    x.p[i] = 0;
  }
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    x /= c[vis[i]];
    cnt += vis[i];
  }
  x *= c[cnt];
  // for (int i = 1; i <= 10; i++) {
  //   printf("%d ", x.p[i]);
  // }printf("\n");
  return Z(x);
}

int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  for (int i = 2; i <= 50; i++) {
    if (vp[i] == 0) {
      for (int j = i + i; j <= 50; j += i) {
        vp[j] = 1;
      }
      p[++pk] = i;
      // printf("%d ", p[pk]);
    }
  }
  for (int i = 1; i <= 50; i++) {
    F(i, c[i]);
    c[i] *= c[i - 1];
    // for (int j = 1; j <= 15; j++) {
    //   printf("%d ", c[i].p[j]);
    // }printf("\n");
  }
  scanf("%s", in + 1);
  n = strlen(in + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = in[i] - '0';
    // printf("%d\n", s[i]);
    vis[s[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = (i == 1); j < s[i]; j++) {
      if (vis[j] <= 0) {
        continue;
      }
      vis[j]--;
      ans += work();
      vis[j]++;
    }
    vis[s[i]]--;
  }
  for (int i = 1; i <= n; i++) {
    vis[s[i]]++;
  }
  --vis[0];
  ans += work();
  printf("%llu", ans);
}// 1020
