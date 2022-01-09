#include <iostream>
#define ASSERT(cond, msg) \
  ({                    \
    if (cond) {           \
      printf(msg);        \
      return;             \
    }                     \
  })

using namespace std;

const int kN = 17, kH = 21;
const int kD[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
const int kL[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

struct Q {
  int r, c, h;
} q[kN * kN * kH];

int n, hm, hr, hc, hx, hy, m, a[kN][kN], cnt, h, t;
bool f[kN][kN][kH], v[kN][kN][kH];
string op;

void IceBarrage(int r, int c, int d, int s) {
  int k = 0;
  for (int i = 0; i <= s && (r += kD[d][0], c += kD[d][1], min(r, c) >= 0 && max(r, c) < n && !f[r][c][0]); k += a[r][c] < 4, a[r][c] = min(a[r][c] + 1, 4), ++i) {
  }
  printf("CIRNO FREEZED %d BLOCK(S)", k);
}
void MakeIceBlock() {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      s += a[i][j] == 4, a[i][j] %= 4;
    }
  }
  printf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)", s, cnt += s);
}
bool InPlace(int r, int c, int h) {
  return r >= 0 && r < n && c >= 0 && c < n && h >= 0 && h <= hm;
}
bool CanPutIceBlock(int r, int c, int h) {
  bool _f = !h;
  for (int i = 0; i < 6; ++i) {
    if (InPlace(r + kL[i][0], c + kL[i][1], h + kL[i][2])) {
      _f |= f[r + kL[i][0]][c + kL[i][1]][h + kL[i][2]];
    }
  }
  return _f;
}
void PutIceBlock(int r, int c, int h) {
  ASSERT(!cnt, "CIRNO HAS NO ICE_BLOCK"), ASSERT(f[r][c][h] || !CanPutIceBlock(r, c, h), "BAKA CIRNO,CAN'T PUT HERE");
  --cnt, f[r][c][h] = 1;
  if (!h) a[r][c] = 0;
  if (r < hr || r > hr + hx - 1 || c < hc || c > hc + hy - 1)
    printf("CIRNO MISSED THE PLACE");
  else if (r > hr && r < hr + hx - 1 && c > hc && c < hc + hy - 1)
    printf("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE");
  else
    printf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)", cnt);
}

bool R(int r, int c, int h) {
  if (InPlace(r, c, h) && !v[r][c][h] && f[r][c][h]) {
    v[r][c][h] = 1, q[++t] = {r, c, h};
    if (!h) return 1;
  }
  return 0;
}

int _RemoveIceBlock(int r, int c, int h) {
  if (!f[r][c][h]) return -1;
  ++cnt, f[r][c][h] = 0;
  fill(&v[0][0][0], &v[n - 1][n - 1][hm] + 1, 0);
  int k = 0;
  for (int i = 0; i < 6; ++i) {
    bool _f;
    for (h = 1, t = 0, _f = R(r + kL[i][0], c + kL[i][1], h + kL[i][2]); h <= t; ++h)
      for (int j = 0; j < 6; ++j) _f |= R(q[h].r + kL[j][0], q[h].c + kL[j][1], q[h].h + kL[j][2]);
    if (!_f) {
      k += t;
      for (int i = 1; i <= t; ++i) f[q[i].r][q[i].c][q[i].h] = 0;
    }
  }
  return k;
}

void RemoveIceBlock(int r, int c, int h) {
  ASSERT(!f[r][c][h], "BAKA CIRNO,THERE IS NO ICE_BLOCK");
  printf("CIRNO REMOVED AN ICE_BLOCK");
  int k = _RemoveIceBlock(r, c, h);
  if (k) printf(",AND %d BLOCK(S) ARE BROKEN", k);
}

int Count(int h) {
  int s = 0;
  for (int i = hr; i < hr + hx; ++i) s += f[i][hc][h] + f[i][hc + hy - 1][h];
  for (int i = hc + 1; i < hc + hy - 1; ++i) s += f[hr][i][h] + f[hr + hx - 1][i][h];
  return s;
}

int MaxHeight() {
  for (int i = hm; i >= 0; --i)
    if (Count(i)) return i;
  return -1;
}

bool RoofBroken() {
  return 0;
}

void MakeRoof() {
  int wh = MaxHeight() + 1;
  ASSERT(!wh, "SORRY CIRNO,HOUSE IS TOO SMALL");
  ASSERT(Count(wh) + cnt < hx * hy, "SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF");
  ASSERT(wh < 2 || (hx - 2) * (hy - 2) * (wh - 1) < 2, "SORRY CIRNO,HOUSE IS TOO SMALL");
  for (int i = hr; i < hr + hx; ++i)
    for (int j = hc; j < hc + hy; ++j) cnt -= !f[i][j][wh], f[i][j][wh] = 1;
  int ck = 0;
  for (int i = hr + 1; i < hr + hx - 1; ++i)
    for (int j = hc + 1; j < hc + hy - 1; ++j)
      for (int k = 0; k < wh; ++k) {
        ck += f[i][j][k], _RemoveIceBlock(i, j, k);
        ASSERT(RoofBroken(), "SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS");
      }
  printf("%d ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED\n", ck), ck = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i < hr || i >= hr + hx || j < hc || j >= hc + hy)
        for (int k = wh + 1; k <= hm; ++k) {
          ck += f[i][j][k], _RemoveIceBlock(i, j, k);
          ASSERT(RoofBroken(), "SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS");
        }
  printf("%d ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED\n", ck);
}

int main() {
  freopen("P3693.in", "r", stdin);
  freopen("P3693.out", "w", stdout);
  cin >> n >> hm >> hr >> hc >> hx >> hy >> m;
  while (m--) {
    int r, c, h, s;
    cin >> op;
    if (op == "ICE_BARRAGE") {
      cin >> r >> c >> h >> s;
      IceBarrage(r, c, h, s);
    } else if (op == "MAKE_ICE_BLOCK") {
      MakeIceBlock();
    } else if (op == "PUT_ICE_BLOCK") {
      cin >> r >> c >> h;
      PutIceBlock(r, c, h);
    } else if (op == "REMOVE_ICE_BLOCK") {
      cin >> r >> c >> h;
      RemoveIceBlock(r, c, h);
    } else {
      MakeRoof();
    }
    printf("\n");
  }
  return 0;
}