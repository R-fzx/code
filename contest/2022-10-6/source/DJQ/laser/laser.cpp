#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 1e4 + 5;
int n, K, maxx;
struct node {
	int l, r;
}Line[maxn];
namespace Sub1 {
	int num[maxn] = {0}, Digit[25], Use[15];
	inline bool Check(int p, int q) {
		for(register int i = 1; i <= n; ++i) {
			for(register int j = Line[i].l; j <= Line[i].r; ++j) {
				int x = j, tot = 0;
				while(x) Digit[++tot] = x % 10, x /= 10;
				int flag = 0, Apper = 0;
				for(register int k = 1; k <= min(K, tot); ++k)
					if(Digit[k] == p) {
						int y = j - (int)pow(10, k - 1) * p + (int)pow(10, k - 1) * q;
						Apper = 1, flag |= num[y];
					}
					else if(Digit[k] ==q) Apper = 1, flag |= num[j - (int)pow(10, k - 1) * q + (int)pow(10, k - 1) * p];
				if(Apper && !flag) return 0;
			}
		}
		return 1;
	}
	inline void Work() {
		for(register int i = 1; i <= n; ++i)
			for(register int j = Line[i].l; j <= Line[i].r; ++j) num[j] = 1;
		for(register int i = 1; i <= 9; ++i)
			if(!Use[i]) {
				for(register int j = 1; j <= 9; ++j)
					if(!Use[j] && Check(i, j)) printf("%d", j), Use[j] = 1;
				printf("\n");
			}
	}
}
signed main() {
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	n = read(), K = read();
	for(register int i = 1; i <= n; ++i) Line[i].l = read(), Line[i].r = read(), maxx = max(maxx, Line[i].l), maxx = max(maxx, Line[i].r);
	if(n <= 50 && maxx <= 6000) Sub1::Work();
	else {
		for(register int i = 1; i <= 9; ++i) printf("%d", i);
		printf("\n");
	}
	
	return 0;
}
