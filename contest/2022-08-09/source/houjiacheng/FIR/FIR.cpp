# include <bits/stdc++.h>
# define N 1010
# define n 1000
# define pint pair <int, int>
# define f(x) cf[x.first][x.second]

using namespace std;

int q, k, Ans;
int ltx[5] = {0, 0, -1, 1};
int lty[5] = {-1, 1, 0, 0};
int chess[N][N];
int freesize[N][N]; // udlr
int freenum[N][N];
pint cf[N][N];

pint fi(pint x) {
  return f(x) == x ? x : f(x) = fi(f(x));
}

bool win(int x, int y) {
  int mid = chess[x][y];
  int l = 0, r = 0, u = 0, d = 0, lu = 0, ru = 0, ld = 0, rd = 0;
  while (chess[x][y - l] == mid) {
    l++;
  }
  while (chess[x][y + r] == mid) {
    r++;
  }
  while (chess[x - u][y] == mid) {
    u++;
  }
  while (chess[x + d][y] == mid) {
    d++;
  }

  while (chess[x - lu][y - lu] == mid) {
    lu++;
  }
  while (chess[x - ru][y + ru] == mid) {
    ru++;
  }
  while (chess[x + ld][y - ld] == mid) {
    ld++;
  }
  while (chess[x + rd][y + rd] == mid) {
    rd++;
  }
  return (l + r - 1 >= k || u + d - 1 >= k || ld + ru - 1 >= k || lu + rd - 1 >= k);
}

void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      freenum[i][j] = 1;
      freesize[i][j] = 4;
      cf[i][j] = make_pair(i, j);
    }
  }
}

void dlt(int x, int y) {
  cf[x][y] = make_pair(x, y);
  int mid = chess[x][y];
  chess[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    if (chess[x + ltx[i]][y + lty[i]] == mid) {
      continue;
    }
    if (++freesize[x + ltx[i]][y + lty[i]] == 1) {
      pint p = fi(make_pair(x + ltx[i], y + lty[i]));
      ++freenum[p.first][p.second];
    }
  }
  for (int i = 0; i < 4; i++) {
    if (chess[x + ltx[i]][y + lty[i]] == mid) {
      dlt(x + ltx[i], y + lty[i]);
    }
  }
  freenum[x][y] = (freesize[x][y] > 0);
}

void in(int x, int y, int c) {
  if (chess[x][y]) {
    printf("illegal\n");
    exit(0);
  }
  chess[x][y] = c;
  for (int i = 0; i < 4; i++) {
    if (--freesize[x + ltx[i]][y + lty[i]] == 0) {
      pint p = fi(make_pair(x + ltx[i], y + lty[i]));
      --freenum[p.first][p.second];
    }
    if (chess[x + ltx[i]][y + lty[i]] == c) {
      cf[x + ltx[i]][y + lty[i]] = make_pair(x, y);
      freenum[x][y] += freenum[x + ltx[i]][y + lty[i]];
    }
  }
  for (int i = 0; i < 4; i++) {
    pint p = fi(make_pair(x + ltx[i], y + lty[i]));
    if (chess[x + ltx[i]][y + lty[i]] && chess[x + ltx[i]][y + lty[i]] != c && freenum[p.first][p.second] == 0) {
      dlt(x + ltx[i], y + lty[i]);
    }
  }
  if (freenum[x][y] == 0) {
    printf("illegal\n");
    exit(0);
  }
  if (win(x, y)) {
    if (c == 1) {
      printf("ITer %d\n", Ans);
    } else {
      printf("Kitty %d\n", Ans);
    }
    exit(0);
  }
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  init();
  scanf("%d%d", &q, &k);
  for (Ans = 1; Ans <= q; Ans++) {
    int x, y;
    scanf("%d%d", &x, &y);
    in(x, y, 2 - (Ans & 1));
  }
  printf("draw\n");
}

/*

20 6
2 3
3 3
3 2
2 2
4 3
2 4
5 3
1 3
3 4
5 5
2 3
3 3
2 3
2 5
6 3
1 5
3 3
6 1
6 2
5 1

*/