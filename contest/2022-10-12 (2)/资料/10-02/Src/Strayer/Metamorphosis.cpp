#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std ;

const double EPS = 1e-8;
const int LMT = 500;

double calc(int deep, double len, double x1, double y1, double x2, double y2)
{
	if(deep > LMT)
		return 0;
	if(x1 > x2)
		swap(x1, x2);
	if(y1 > y2)
		swap(y1, y2);
	double delta = len / 3.0;
	if(y2 + EPS > len && y1 < EPS && x1 - EPS < -delta && x2 + EPS > delta)
		return len + (len * 2.0 / 3.0) * (LMT - deep);
	if(y1 + EPS > len || y2 < EPS || x2 < -delta + EPS || delta - EPS < x1)
		return 0;
	
	double res = 0;
	if(x1 - EPS < 0 && x2 + EPS > 0)
	{
		double t= min(y2, len - delta) - max(y1, 0.0);
		res += t > 0 ? t : 0;
	}
	return  calc(deep + 1, delta, x1, y1 - len + delta, x2, y2 - len + delta) + 
			calc(deep + 1, delta, -(y1 - len + delta), x1, -(y2 - len + delta), x2) + 
			calc(deep + 1, delta, (y1 - len + delta), -x1, (y2 - len + delta), -x2) + res;
}

void init()
{
	double x1, y1, x2, y2;
	freopen("Metamorphosis.in", "r", stdin);
	freopen("Metamorphosis.out", "w", stdout);
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	printf("%.1lf\n", calc(1, 81, x1, y1, x2, y2));
}

int main()
{
	init();
	return 0 ;
}
