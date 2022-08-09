#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;

int ch[1000003][26] = {{0}};
int fail[1000003];
int last[1000003];
int val[1000003] = {0};
int tot = 0;
char zan[1000003];

char cun[201][23];

void insert(char s[], int z) {
  int l1 = strlen(s);
  int u = 0;
  for (int i = 0; i < l1; i++) {
    int c = s[i] - 'a';
    if (!ch[u][c]) {
      ch[u][c] = ++tot;
      fail[tot] = 0;
      last[tot] = 0;
    }
    u = ch[u][c];
  }
  val[u] = z;
}

int dui[1000003];
int head, tail;
void create() {
  head = 0;
  tail = 0;
  for (int i = 0; i <= 25; i++) {
    if (ch[0][i]) {
      dui[tail++] = ch[0][i];
    }
  }
  for (; head < tail;) {
    int r = dui[head++];
    for (int c = 0; c <= 25; c++) {
      int u = ch[r][c];
      if (!u) continue;
      dui[tail++] = u;
      int orz = fail[r];
      for (; orz && !ch[orz][c];) orz = fail[orz];
      fail[u] = ch[orz][c];
      last[u] = val[fail[u]] ? fail[u] : last[fail[u]];
    }
  }
}

void scanff() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", cun[i]);
    insert(cun[i], i);
  }
}

struct words {
  int bian;
  int sum;
  friend bool operator<(const words s1, const words s2) {
    return s1.sum < s2.sum;
  }
} word[201];
void work1() {
  for (int i = 1; i <= n; i++) {
    word[i].bian = i;
  }
  scanf("%s", zan);
  int l1 = strlen(zan);
  int u = 0;
  for (int i = 0; i < l1; i++) {
    if (i == 218) {
      i++;
      i--;
    }
    int c = zan[i] - 'a';
    for (; u && !ch[u][c];) {
      u = fail[u];
    }
    u = ch[u][c];
    if (val[u]) {
      word[val[u]].sum++;
    }
    int orz = u;
    for (; val[last[orz]];) {
      orz = last[orz];
      word[val[orz]].sum++;
    }
  }
}

int zong = 0;
int bian[201];

double f[1003][1003] = {{0}};
double ans[1003] = {0};
void work2() {
  sort(word + 1, word + n + 1);
  for (int i = 1; i <= n;) {
    zong++;
    int j;
    for (j = i; j <= n && word[j].sum == word[i].sum; j++) bian[word[j].bian] = zong;
    i = j;
  }
  int k;
  double p;
  scanf("%lf%d", &p, &k);

  p = 1 - p;  //���ǵĸ���

  //	for(int i=1;i<=k;i++)f[i][0]=1;
  f[0][0] = 1;
  for (int i = 1; i <= k; i++) f[i][0] = f[i - 1][0] * (1 - p);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= i; j++) {
      f[i][j] = f[i - 1][j - 1] * p + f[i - 1][j] * (1 - p);
    }
  }

  for (int i = 1; i <= zong; i++) {
    for (int j = 0; j < i; j++) {
      ans[i] += f[k][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%.3lf ", ans[bian[i]]);
  }
}

int main() {
  // freopen("ppfish.in","r",stdin);
  // freopen("ppfish.out","w",stdout);
  scanff();
  create();
  work1();
  work2();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
