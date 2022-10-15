#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define conint const int
#define condou const double
#define conll const ll
#define clear(a, b)	memset(a, b, sizeof a)
#define fu(i, a, b)	for (int i = a; i <= b; i++)
#define fd(i, a, b)	for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, m, lim, k, A, noB, cnt;
double ans;
bool h[9];

struct st {
	int B, L;
}a[9];

void work() {						// 计算当前k分配下的概率
	double now = 0.;
	fu(i, 0, lim) {					// 评议员的各种投票情况 
		int x = i;
		double rate = 1.;
		cnt = noB = 0;
		fu(t, 1, n) {				// 枚举人 
			if (h[t] = x & 1)
				rate *= a[t].L * 0.01,	cnt++;
			else
				rate *= (1 - a[t].L * 0.01),	noB += a[t].B;
			x >>= 1;
		}							// 出现所枚举的这种投票情况的概率 
		if (cnt > m)	
			now += rate;			// 大于半数胜选无压力 
		else
			now += (rate * A * 1.0 / (A + noB));	// 要进行杀戮 计算成功率用乘法 
	}
	ans = max(ans, now);			// 更新答案 
}

void divk(int id, int sum) {        // 枚举k的分配 
	if (id == n) {
		int add = min(k - sum, (100 - a[id].L) / 10);
		a[id].L += (add * 10);
		work();
		a[id].L -= (add * 10);
		return;
	}
	int add = min(k - sum, (100 - a[id].L) / 10);
	fu(i, 0, add) {
		a[id].L += (i * 10);
		divk(id + 1, sum + i);
		a[id].L -= (i * 10);
	}
}

void read() {
	scanf("%d%d%d", &n, &k, &A);
	fu(i, 1, n)
		scanf("%d%d", &a[i].B, &a[i].L);
	m = (n >> 1);					// half of them
	lim = (1 << n) - 1;				// total condition of voting
}

void put() {
	printf("%.6lf\n", ans);
}

int main() {
	freopen("assembly.in", "r", stdin);	freopen("assembly.out", "w", stdout);
	read();
	divk(1, 0);
	put(); 
	fclose(stdin);	fclose(stdout);	return 0;
}
