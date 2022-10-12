#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "t3.in"
#define ouf "t3.out"

#define lowbit(x) ((x)&-(x))

long long F[ 2 ][ 1 << 21 ];

long G[ 21 ];

long N;

long long Ans = 0;

int main ()
{
	long i, j, k, l, p;
	long Now, Pre;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld", & N );
	
	for ( i = 1; i <= N; i++ )
		{
			for ( j = 1; j <= N; j++ )
				{
					scanf ( "%ld", & k );
					
					k = 1 - k;
					
					G[ i ] = ( G[ i ] << 1 ) + k;
				}
		}
	
	Now = 0;
	Pre = 1;
	
	F[ 0 ][ ( 1 << N ) - 1 ] = 1;
	
	for ( i = 1; i <= N; i++ )
		{ 
			Now = 1 - Now;
			Pre = 1 - Pre;
			
			memset ( F[ Now ], 0, sizeof ( F[ Now ] ) );
			
			for ( k = 0; k < ( 1 << N ); k++ )
				{
					if ( F[ Pre ][ k ] == 0 )
						{
							continue;
						}
					
					l = k;
					while ( l )
						{
							p = lowbit ( l );
							
							if ( p & G[ i ] )
								{
									F[ Now ][ k ^ p ] += F[ Pre ][ k ];
								}
							
							l = l ^ p;
						}
				}
		}
	
	for ( k = 0; k < ( 1 << N ); k++ )
		{
			Ans += F[ Now ][ k ];
		}
	
	printf ( "%I64d\n", Ans );
	
	return ( 0 );
}
