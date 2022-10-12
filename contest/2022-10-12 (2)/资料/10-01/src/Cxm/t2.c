#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "t2.in"
#define ouf "t2.out"

long long A, B;
long long Ans;

long long P[ 100 ];

inline long long Pow ( long long A, long long B, long long N )
{
	long long i, Ans = 1;
	
	for ( i = 1; i <= B; i++ )
		{
			if ( Ans > N / A )
				{
					return ( 0 );
				}
			
			Ans *= A;
		}
	
	return ( 1 );
}

inline long long Bin ( long long N, long long P )
{
	long long L, R, Mid;
	
	L = 1;
	R = N;
	
	while ( L < R - 1 )
		{
			Mid = ( L + R ) / 2;
			
			if ( Pow ( Mid, P, N ) )
				{
					L = Mid;
				}
				else
					{
						R = Mid - 1;
					}
		}
	
	if ( L == R )
		{
			return ( L );
		}
		else
			{
				if ( Pow ( R, P, N ) )
					{
						return ( R );
					}
					else
						{
							return ( L );
						}
			}
}

inline long long Work ( long long N )
{
	long long i, j, Ans = 0;
	
	memset ( P, 0, sizeof ( P ) );
	
	for ( i = 1; i <= 62; i++ )
		{
			P[ i ] = Bin ( N, i );
		}
	
	for ( i = 60; i; i-- )
		{
			for ( j = i - 1; j; j-- )
				{
					if ( i % j == 0 )
						{
							P[ j ] -= P[ i ];
						}
				}
		}
	
	for ( i = 1; i <= 60; i++ )
		{
			Ans += P[ i ] * i;
		}
	
	return ( Ans );
}

int main ()
{	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	while ( 1 )
		{
			scanf ( "%I64d%I64d", & A, & B );
			
			if ( A + B == 0 )
				{
					return ( 0 );
				}
			
			printf ( "%I64d\n", Work ( B ) - Work ( A - 1 ) );
		}
	
	return ( 0 );
}
