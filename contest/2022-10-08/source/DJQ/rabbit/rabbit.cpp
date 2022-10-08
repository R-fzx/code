#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x; 
}
const int maxn = 1005;
int n;
int main() {
	freopen("rabbit.in", "r", stdin);
	freopen("rabbit.out", "w", stdout);
 	n = read();
 	printf("%d\n", n * (n - 1) >> 1);
 	for(register int i = 1; i <= n; ++i)
 		for(register int j = 1; j < n - 1; ++j)
 			printf("%d %d %d\n", i, ((i + j) % n == 0 ? n : (i + j) % n), ((i + (j << 1)) % n == 0 ? n : (i + (j << 1)) % n));
	return 0;
}
