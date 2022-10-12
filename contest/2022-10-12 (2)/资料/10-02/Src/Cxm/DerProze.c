#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "DerProze.in"
#define ouf "DerProze.out"

char Out[ 12 ][ 20 ] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

long Month[ 13 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

long Y, M, D;

long Total = 6;

int main ()
{
	long i, j, k;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld%ld", & Y, & M, & D );
	
	for ( i = 1; i < Y; i++ )
	
		{
			if ( ( i % 400 == 0 ) || ( i % 100 != 0 && i % 4 == 0 ) )
				{
					Total += 366;
				}
				else
					{
						Total += 365;
					}
		}
	
	if ( ( i % 400 == 0 ) || ( i % 100 != 0 && i % 4 == 0 ) )
		{
			Month[ 2 ]++;
		}
	
	for ( i = 1; i < M; i++ )
		{
			Total += Month[ i - 1 ];
		}
	
	Total += D;
	
	printf ( "%s\n", Out[ Total % 7 ] );
	
	return ( 0 );
}
