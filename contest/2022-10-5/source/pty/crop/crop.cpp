#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("crop.in");
ofstream fout("crop.out");

LL t[3][3], ans;

void I() {
  LL n, a, b, c, d, x, y, m;
  fin >> n >> a >> b >> c >> d >> x >> y >> m;
  for (int i = 1; i <= n; i++) {
    t[x % 3][y % 3]++;
    x = (a * x + b) % m;
    y = (c * y + d) % m;
  }
}

int main() {
  I();
  for (int ax = 0; ax < 3; ax++) {
    for (int ay = 0; ay < 3; ay++) {
      for (int bx = 0; bx < 3; bx++) {
        for (int by = 0; by < 3; by++) {
          for (int cx = 0; cx < 3; cx++) {
            for (int cy = 0; cy < 3; cy++) {
              if ((ax + bx + cx) % 3 == 0 && (ay + by + cy) % 3 == 0) {
                if (ax == bx && bx == cx && ay == by && by == cy) {
                  ans += t[ax][ay] * (t[ax][ay] - 1) * (t[ax][ay] - 2);
                } else if (ax == bx && ay == by) {
                  ans += t[ax][ay] * (t[ax][ay] - 1) * t[cx][cy];
                } else if (ax == cx && ay == cy) {
                  ans += t[ax][ay] * (t[ax][ay] - 1) * t[bx][by];
                } else if (bx == cx && by == cy) {
                  ans += t[ax][ay] * t[bx][by] * (t[bx][by] - 1);
                } else {
                  ans += t[ax][ay] * t[bx][by] * t[cx][cy];
                }
              }
            }
          }
        }
      }
    }
  }
  fout << ans / 6;
  return 0;
}