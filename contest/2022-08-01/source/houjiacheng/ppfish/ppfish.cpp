# include <algorithm>
# include <stdio.h>
# include <math.h>

using namespace std;

struct Node{
  int cnt;
  int son[26];
} tree[4040];

int tot;
double p;
int c[300];
int b[300];
int x[300];
int sc[300];
double pw[300];
char s[300][20];
char str[1001000];
int n, len, K, scn;
double ans[1001000];
double op[300][1010];

double pow(double x, int y) {
  double re = 1.0;
  double now = x;
  while (y) {
    if (y & 1) {
      re *= now;
    }
    y >>= 1;
    now *= now;
  }
  return re;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    int now = 0;
    for (int j = 1; s[i][j]; j++) {
      if (tree[now].son[s[i][j] - 'a']) {
        now = tree[now].son[s[i][j] - 'a'];
      } else {
        now = tree[now].son[s[i][j] - 'a'] = ++tot;
      }
    }
    x[i] = now;
  }
  scanf("%s%lf%d", str + 1, &p, &K);
  pw[0] = 1.0;
  for (int i = 1; i <= K + 1; i++) {
    pw[i] = pw[i - 1] * p;
    // printf("%lf\n", pw[i]);
  }
  for (int i = 1; str[i]; i++) {
    int now = 0;
    for (int j = i; str[j]; j++) {
      if (tree[now].son[str[j] - 'a']) {
        now = tree[now].son[str[j] - 'a'];
        ++tree[now].cnt;
      } else {
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    c[i] = tree[x[i]].cnt;
    if (b[c[i]] == 0) {
      sc[++scn] = c[i];
    }
    ++b[c[i]];
  }
  sort(sc + 1, sc + 1 + scn);
  op[1][0] = 1.0;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= scn; j++) {
      for (int k = 0; k < i; k++) {
        // if (op[j - 1][k] < -0.5) continue;
        op[j][i] += op[j - 1][k] * pow(1.0 - pw[i - k], b[sc[j - 1]]);
        op[j][i] -= op[j][k];
      }
      if (op[j][i] < 0) {
        op[j][i] = 0;
      }
      printf("%.3f ", op[j][i]);
    }printf("\n");
  }
  for (int i = 1; i <= scn; i++) {
    ans[sc[i]] = 1.0;
    for (int j = 0; j < K; j++) {
      // if (op[i][j] < -0.5) continue;
      ans[sc[i]] += op[i][j] * pw[K - j];
      ans[sc[i]] -= op[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%.3f ", ans[c[i]]);
  }printf("\n");
}
/*

0.7
0.91
0.973

0.027

5
he
she
her
hers
his
hershe
0.30 5

*/