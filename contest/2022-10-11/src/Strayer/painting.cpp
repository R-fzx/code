#include <cstdio>
#include <cstdlib>

using namespace std;

const int MOD = 1000000007;

__int64 N, M, K;

int main()
{
	freopen("painting.in", "r", stdin);
	freopen("painting.out", "w", stdout);
	scanf("%I64d%I64d%I64d", &N, &M, &K);
	__int64 ans = 1;
	for(int i(1); i<= M + K - 1; ++ i)
	{
		ans *= N;
		ans %= MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}
