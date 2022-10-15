#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "painting.in"
#define ouf "painting.out"

#define Model 1000000007

long long Anti[ 2000 + 7 ];

long long F[ 2000 + 7 ];
long long iN[ 2000 + 7 ];
long long iNM[ 2000 + 7 ];
long long C[ 2001 ][ 2001 ];
long long Jc[ 1000001 ];
long long Anti_Jc[ 1000001 ];

long long N, M, K;

long long Ans = 0;

long long Quick ( long long Base, long long T )
{
	long long k = 1;
	
	for ( ; T; T >>= 1 )
		{
			if ( T & 1 )
				{
					k = ( k * Base ) % Model;
				}
			
			Base = ( Base * Base ) % Model;
		}
	
	return ( k );
}

int main ()
{
	long long i, j, tmp;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%I64d%I64d%I64d", & N, & M, & K );
	
	if ( M == 1 )
		{
			printf ( "%I64d\n", Quick ( K, N ) );
			
			return ( 0 );
		}
	
	for ( i = 1; i <= N; i++ )
		{
			Anti[ i ] = Quick ( i, Model - 2 );
			iN[ i ] = Quick ( i, N );
			iNM[ i ] = Quick ( i, N * ( M - 2 ) );
		}
	
	C[ 0 ][ 0 ] = 1;
	
	for ( i = 1; i <= N; i++ )
		{
			C[ i ][ 0 ] = 1;
			
			for ( j = 1; j <= i; j++ )
				{
					C[ i ][ j ] = ( ( C[ i - 1 ][ j - 1 ] * i ) % Model ) * Anti[ j ] % Model;
				}
		}
	
	for ( i = 1; i <= N; i++ )
		{
			F[ i ] = iN[ i ];
			
			for ( j = 1; j < i; j++ )
				{
					F[ i ] = F[ i ] - ( F[ j ] * C[ i ][ j ] ) % Model;
					
					while ( F[ i ] < 0 )
						{
							F[ i ] += Model;
						}
				}
		}
	
	Jc[ 0 ] = 1;
	for ( i = 1; i <= K; i++ )
		{
			Jc[ i ] = ( i * Jc[ i - 1 ] ) % Model;
		}
	
	Anti_Jc[ 0 ] = 1;
	for ( i = 1; i <= K; i++ )
		{
			if ( i <= N || i <= K && i >= K - 2 * N )
				{
					Anti_Jc[ i ] = Quick ( Jc[ i ], Model - 2 );
				}
		}
	
	for ( i = 0; i <= N && i <= K; i++ )
		{
			for ( j = 0; j <= N - i && i + 2 * j <= K; j++ )
				{
					tmp = Anti_Jc[ K - 2 * j - i ];
					
					tmp = ( tmp * Anti_Jc[ j ] ) % Model;
					tmp = ( tmp * Anti_Jc[ j ] ) % Model;
					tmp = ( tmp * Anti_Jc[ i ] ) % Model;
					
					tmp = ( tmp * Jc[ K ] ) % Model;
					
					tmp = ( tmp * iNM[ i ] ) % Model;
					
					tmp = ( ( ( tmp * F[ i + j ] ) % Model ) * F[ i + j ] ) % Model;
					
					Ans = ( Ans + tmp ) % Model;
				}
		}
	
	printf ( "%I64d\n", Ans );
	
	return ( 0 );
}
