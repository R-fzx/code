#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, k;
bool a[3000];
typedef unsigned int ui;
bool vis[3000], finish;

inline void DFS (int x)
{
	if (x == n + 1)
	{
		a[n] = 1;
		for (int i = 1; i <= n; i ++)
			printf ("%d", a[i]);
		finish = true;
		return ;
	}
	
	if (finish) return ;
	ui tmp (0);
	a[x] = 0;
	for (int i = 0; i < k; i ++)
		tmp |= (a[x - i] << i);
	if (!vis[tmp])
	{
		vis[tmp] = true;
		DFS (x + 1);
		vis[tmp] = false;
	}
	
	if (finish) return ;
	tmp = 0;
	a[x] = 1;
	for (int i = 0; i < k; i ++)
		tmp |= (a[x - i] << i);
	if (!vis[tmp])
	{
		vis[tmp] = true;
		DFS (x + 1);
		vis[tmp] = false;
	}
}
	
	

int main ()
{
	freopen ("taiko.in", "r", stdin);
	freopen ("taiko.out", "w", stdout);
	finish = false;
	scanf ("%d", &k);
	n = (int)pow (2.0, k);
	printf ("%d ", n);
	for (int i = 1; i <= k; i ++)
		a[i] = 0;
	vis[0] = true;
	DFS (k + 1);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
