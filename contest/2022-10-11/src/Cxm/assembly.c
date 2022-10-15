#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "assembly.in"
#define ouf "assembly.out" 

long B[ 10 ], L[ 10 ];

double Ans, Sum;

long N, K, A;

void Vote ( long Now, long Anti, long Anti_Sum, double Pos )
{
	if ( Now > N )
		{
			if ( Anti * 2 < N )
				{
					Sum += Pos;
				}
				else
					{
						Sum += ( Pos * A ) / ( A + Anti_Sum );
					}
			
			return;
		}
	
	Vote ( Now + 1, Anti, Anti_Sum, Pos * L[ Now ] / 100 );
	Vote ( Now + 1, Anti + 1, Anti_Sum + B[ Now ], Pos * ( 100 - L[ Now ] ) / 100 );
}

void Gift ( long Now, long Rest )
{
	if ( Now > N )
		{
			Sum = 0;
			
			Vote ( 1, 0, 0, 1 );
			
			if ( Ans < Sum )
				{
					Ans = Sum;
				}
			
			return;
		}
	
	long i;
	
	for ( i = 0; i <= Rest && i * 10 + L[ Now ] <= 100; i++ )
		{
			L[ Now ] += i * 10;
			
			Gift ( Now + 1, Rest - i );
			
			L[ Now ] -= i * 10;
		}
	
	return;
}

int main ()
{
	long i;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld%ld", & N, & K, & A );
	
	for ( i = 1; i <= N; i++ )
		{
			scanf ( "%ld%ld", & B[ i ], & L[ i ] );
		}
	
	Gift ( 1, K );
	
	printf ( "%lf\n", Ans );
	
	return ( 0 );
}
