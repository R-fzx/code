#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, T;
int r[201000], c[201000], r_ans, c_ans, r_s, c_s, b[201000];

inline int trans (int a[], int ave)
{
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n + n; i ++)
		a[i] -= ave;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 1; j <= n + n; j ++)
			b[j] = a[j];
		int res = 0;
		for (int j = 1; j <= n; j ++)
			b[i + j + 1] += b[i + j], res += abs (b[i + j]);
		ans = min (ans, res);
	}
	return ans;
}

int main ()
{
	freopen ("tanabata.in", "r", stdin);
	freopen ("tanabata.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &T);
	for (int i = 1, x, y; i <= T; i ++)
	{
		scanf ("%d%d", &x, &y);
		r[x] ++;r[x + n] = r[x];r_s ++;
		c[y] ++;c[y + m] = c[y];c_s ++;
	}
	if (r_s % n == 0)
		r_ans = trans (r, r_s / n);
	else
		r_ans = 0x3f3f3f3f;
	if (c_s % m == 0)
		c_ans = trans (c, c_s / n);
	else
		c_ans = 0x3f3f3f3f;
	if (r_ans != 0x3f3f3f3f && c_ans != 0x3f3f3f3f)
		printf ("both %d", r_ans + c_ans);
	else if (r_ans != 0x3f3f3f3f)
		printf ("row %d", r_ans);
	else if (c_ans != 0x3f3f3f3f)
		printf ("column %d", c_ans);
	else
		printf ("impossible");
	fclose (stdin);
	fclose (stdout);
	return 0;
}

	
	
		
	
		
