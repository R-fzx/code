#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a), i##_end_ = (b); i <= i##_end_; ++i)
#define drep(i, a, b) for(int i = (a), i##_end_ = (b); i >= i##_end_; --i)
#define clar(a, b) memset((a), (b), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef long long LL;
typedef long double LD;
const int BUF_SIZE = (int)1e6 + 10;
struct fastIO {
    char buf[BUF_SIZE], buf1[BUF_SIZE];
    int cur, cur1; FILE *in, *out;
    fastIO() { cur = BUF_SIZE, in = stdin, out = stdout; cur1 = 0; }
    inline char getchar() { if(cur == BUF_SIZE) fread(buf, BUF_SIZE, 1, in), cur = 0; return *(buf + (cur++)); }
    inline void putchar(char ch) { *(buf1 + (cur1++)) = ch; if (cur1 == BUF_SIZE) fwrite(buf1, BUF_SIZE, 1, out), cur1 = 0; }
    inline int flush() { if (cur1 > 0) fwrite(buf1, cur1, 1, out); return cur1 = 0; }
}IO;
#define getchar IO.getchar
#define putchar IO.putchar
LL read() {
	char ch = getchar();
	LL x = 0, flag = 1;
	for (;!isdigit(ch); ch = getchar()) if (ch == '-') flag *= -1;
	for (;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	return x * flag;
}
void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int Maxn = 100009;
LL n, a[Maxn];

void init() {
	n = read();
	rep (i, 1, n) a[i] = read();
}

int dp[79][Maxn];
LL tmp[Maxn], mx, ori[Maxn];
int cnt[Maxn][4];


void radixSort(int pos) {
	int cru = 0;
	rep (i, 1, n) 
		if ((a[ori[i]] >> (pos - 1)) & 1) tmp[++cru] = ori[i];
	rep (i, 1, n) 
		if (!((a[ori[i]] >> (pos - 1)) & 1)) tmp[++cru] = ori[i];
	assert(cru == n);
	rep (i, 1, n) ori[i] = tmp[i];
}

//0 : jw & 1
//1 : njw & 1
//2 : jw & 0
//3 : njw & 0
void solve() {
	rep (i, 1, n) mx = max(mx, a[i]);
	rep (i, 1, n) a[i] = mx - a[i], ori[i] = i;
	clar(dp, 0x3f); dp[0][0] = 0;

	rep (i, 0, 62) {
		if (i) radixSort(i);
		int sum0 = 0, sum1 = 0;
		rep (j, 1, n) sum1 += ((a[ori[j]] >> i) & 1), sum0 += !((a[ori[j]] >> i) & 1); 
		rep (j, 1, n) {
			cnt[j][0] = cnt[j - 1][0]; cnt[j][2] = cnt[j - 1][2]; 
			cnt[j][0] += ((a[ori[j]] >> i) & 1); 
			cnt[j][2] += !((a[ori[j]] >> i) & 1); 
		}
		drep (j, n, 1) {
			cnt[j][1] = cnt[j + 1][1]; cnt[j][3] = cnt[j + 1][3]; 
			cnt[j][1] += ((a[ori[j]] >> i) & 1); 
			cnt[j][3] += !((a[ori[j]] >> i) & 1); 
		}

		rep (j, 0, n) {
			if (dp[i][j] == 0x3f3f3f3f) continue;
			//t == 0
			dp[i + 1][cnt[j][0]] = min(dp[i + 1][cnt[j][0]], dp[i][j] + cnt[j][2] + cnt[j + 1][1]);
			//t == 1
			dp[i + 1][j + cnt[j + 1][1]] = min(dp[i + 1][j + cnt[j + 1][1]], dp[i][j] + cnt[j][0] + cnt[j + 1][3]);
		}
	}
	cout << dp[63][0] << endl;
}

int main() {

	init();
	solve();

#ifdef Qrsikno
	debug("\nRunning time: %.3lf(s)\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
	return IO.flush();
}
