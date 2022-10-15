#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("assembly.in");
ofstream fout("assembly.out");

const int kMaxN = 10;

int b[kMaxN], l[kMaxN], n, m, a, k;
double ans, sum;

void S2(int i, int t, int sb, double p) {     // 考虑到i，通过了t个，没通过的总战力sb，概率p
  if (i == n + 1) {                           // 考虑完所有人
    sum += t * 2 > n ? p : p * a / (a + sb);  // 累加概率
    return;
  }
  int li = min(100, l[i]);                    // 计算当前通过率
  S2(i + 1, t + 1, sb, p * li / 100);         // 通过
  S2(i + 1, t, sb + b[i], p - p * li / 100);  // 不通过
}

void S1(int i, int k, int o) {  // 考虑到i，还剩k礼品，是否有人没满
  if (i == n + 1) {
    if (!k || !o) {  // 要么礼品送完，要么全满
      sum = 0;
      S2(1, 0, 0, 1);
      ans = max(ans, sum);
    }
    return;
  }
  if (k && l[i] < 100) {  // 还有礼品且没满
    l[i] += 10;
    S1(i, k - 1, o);  // 继续考虑当前人
    l[i] -= 10;
  }
  S1(i + 1, k, o || l[i] < 100);  // 考虑下一个人
  return;
}

int main() {
  fin >> n >> k >> a;
  for (int i = 1; i <= n; i++) {
    fin >> b[i] >> l[i];
  }
  S1(1, k, 0);
  fout << fixed << setprecision(6) << ans;
  return 0;
}