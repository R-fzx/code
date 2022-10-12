#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "ユイ.in"
#define ouf "ユイ.out"

#define pi 3.1415926535897932384626433832795

double R, Thita;

double a;

int main ()
{
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%lf%lf", & R, & Thita );
	
	printf ( "%0.6lf\n", 4 * R * R * ( sin ( Thita / 2 ) ) / ( 3 * Thita * R ) );
	
	return ( 0 );
}
