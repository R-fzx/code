// #include <bits/stdc++.h>
// #define max(a, b) (a > b ? a : b)

// inline void r(int &s) {
//   s = 0;
//   int c(getchar());
//   while (c < 48 || c > 57) c = getchar();
//   while (c > 47 && c < 58) s = (s << 3) + (s << 1) + c - 48, c = getchar();
// }

// void w(int x) {
//   if (x > 9) w(x / 10);
//   putchar(x % 10 + 48);
// }

// const int MAXN = 1e3 + 5;

// int q[MAXN * MAXN];  //气
// int cnt = 0;
// short qp[MAXN][MAXN];  //棋盘
// short dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
// int n, x;

// struct bcj {
//   int f, h, q;
// } a[MAXN * MAXN];

// int Find(int x) {
//   if (a[x].f == x) {
//     return x;
//   }
//   a[x].f = Find(a[x].f);
//   return a[x].f;
// }

// void hb(int x, int y) {
//   if (a[x].h > a[y].h) {
//     a[y].f = x;
//     a[x].q += a[y].q;
//     a[y].q = 0;
//   } else {
//     a[x].f = y;
//     a[y].q += a[x].q;
//     a[x].q = 0;
//     a[y].h = max(a[y].h, a[x].h + 1);
//   }
// }

// void initbcj() {
//   for (int i = 1; i <= MAXN * MAXN; i++) {
//     a[i].f = i;
//   }
// }

// int ys(int x, int y) {
//   return x * 1000 + y;
// }

// void del(int x, int y, int c) {
//   int i = ys(x, y);
//   a[i].f = i, a[i].h = 0;
//   qp[x][y] = 0;
//   for (int i(0), nx, ny; i < 4; ++i) {
//     nx = x + dx[i], ny = y + dy[i];
//     if (qp[nx][ny] == c) {
//       del(nx, ny, c);
//     } else if (qp[nx][ny]) {
//       a[Find(ys(nx, ny))].q++;
//     }
//   }
// }

// int getqi(int x, int y, int c) {
//   int cnt = 0;
//   for (int i(0), nx, ny; i < 4; ++i) {
//     nx = x + dx[i], ny = y + dy[i];
//     if (qp[nx][ny]) {
//       if (qp[nx][ny] != c) {
//         a[Find(ys(nx, ny))].q--;
//         if (!a[Find(ys(nx, ny))].q) {
//           del(nx, ny, c);
//         }
//       }
//     }
//     if (!qp[nx][ny]) {
//       ++cnt;
//     }
//   }
//   return cnt;
// }

// int check(int x, int y, int c) {  //检查并入连通块
//   for (int i(0), nx, ny; i < 4; ++i) {
//     nx = x + dx[i], ny = y + dy[i];
//     if (qp[nx][ny] == c) {
//       hb(Find(ys(nx, ny)), Find(ys(x, y)));
//     }
//   }
//   return Find(ys(x, y));
// }

// bool checkill(int x, int y, int c) {
//   if (qp[x][y]) {
//     return 1;
//   }
//   for (int i(0), nx, ny; i < 4; ++i) {
//     nx = x + dx[i], ny = y + dy[i];
//     if (!qp[nx][ny] || qp[nx][ny] == c) {
//       return 0;
//     }
//   }
//   return 1;
// }

// bool checkwin(int x, int y, int c) {
//   int cnt1, cnt2, cnt3, cnt4;
//   for (int i)
// }

// int main() {
//   freopen("fir.in", "r", stdin);
//   freopen("fir.out", "w", stdout);
//   r(n), r(x);
//   ++n;
//   for (int i(1), x, y; i < n; ++i) {
//     r(x), r(y);
//     int c = (i % 2) + 1;
//     if (checkill(x, y, c)) {
//       putchar('i'),putchar('l'),putchar('l'),putchar('e'),putchar('g'),putchar('a'),putchar('l');
//       return 0;
//     }
//     qp[x][y] = c;
//     a[check(x, y, c)].q += getqi(x, y, c);

//   }
//   return 0;
// }