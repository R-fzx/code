// luogu-judger-enable-o2
#include <cstdio>

int n, m, num, _x, _y, _x1, _y1;
char c[3];

struct BIT {
  int tree[2050][2050];

  int lowbit(int x) { return x & -x; }

  void add(int x, int y, int num) {
    for (int i = x; i <= n; i += lowbit(i))
      for (int j = y; j <= m; j += lowbit(j))
        tree[i][j] += num;
  }

  int query(int x, int y) {
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
      for (int j = y; j >= 1; j -= lowbit(j))
        res += tree[i][j];
    return res;
  }
} A, Ai, Aj, Aij;

int read() {
  int sign = 1, res = 0;
  char c;
  while ((c = getchar()) < 48 || c > 57)
    if (c == '-')
      sign = -1;
  if (sign)
    res = c - 48;
  while ((c = getchar()) >= 48 && c <= 57)
    res = res * 10 + c - 48;
  return res * sign;
}

int Ans(int x, int y) {
  fprintf(stderr, "Query(%d, %d)\n", x, y);
  return A.query(x, y) * (x * y + x + y + 1) -
         Ai.query(x, y) * (y + 1) -
         Aj.query(x, y) * (x + 1) +
         Aij.query(x, y);
}

void Add(int x, int y, int num) {
  fprintf(stderr, "Add(%d, %d, %d)\n", x, y, num);
  A.add(x, y, num);
  Ai.add(x, y, num * x);
  Aj.add(x, y, num * y);
  Aij.add(x, y, num * x * y);
}

int main() {
  scanf("X %d %d", &n, &m);
  while (~scanf("%s", &c)) {
    scanf("%d%d%d%d", &_x, &_y, &_x1, &_y1);
    if (c[0] == 'L') {
      scanf("%d", &num);
      Add(_x, _y, num);
      Add(_x, _y1 + 1, -num);
      Add(_x1 + 1, _y, -num);
      Add(_x1 + 1, _y1 + 1, num);
    } else {
      printf("%d\n", Ans(_x1, _y1) - Ans(_x - 1, _y1) - Ans(_x1, _y - 1) + Ans(_x - 1, _y - 1));
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fprintf(stderr, "%d ", A.tree[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fprintf(stderr, "%d ", Ai.tree[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fprintf(stderr, "%d ", Aj.tree[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      fprintf(stderr, "%d ", Aij.tree[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
  return 0;
}
