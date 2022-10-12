#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "t3.in"
#define ouf "t3.out"

#define Model 10000
#define Size 1000

long F[ 205 ][ Size ];

long N;

void Plus ( long A[], long B[], long C[] )
{
	long i, l;
	
	if ( A[ 0 ] > B[ 0 ] )
		{
			C[ 0 ] = A[ 0 ];
		}
		else
			{
				C[ 0 ] = B[ 0 ];
			}
	
	for ( i = 1; i <= A[ 0 ]; i++ )
		{
			C[ i ] = A[ i ];
		}
	
	for ( i = 1; i <= B[ 0 ]; i++ )
		{
			C[ i ] += B[ i ];
		}
	
	l = 0;
	for ( i = 1; i <= C[ 0 ]; i++ )
		{
			C[ i ] += l;
			l = C[ i ] / Model;
			C[ i ] %= Model; 
		}
	
	while ( l )
		{
			C[ ++C[ 0 ] ] = l % Model;
			l /= Model;
		}
	
	return;
}

void Mult ( long A[], long B, long C[] )
{
	long i, l;
	long s[ Size ] = { 0 };
	
	s[ 0 ] = A[ 0 ];
	
	l = 0;
	for ( i = 1; i <= A[ 0 ]; i++ )
		{
			s[ i ] = A[ i ] * B + l;
			l = s[ i ] / Model;
			s[ i ] %= Model;
		}
	
	while ( l )
		{
			s[ ++s[ 0 ] ] = l % Model;
			l /= Model;
		}
	
	for ( i = 0; i <= s[ 0 ]; i++ )
		{
			C[ i ] = s[ i ];
		}
	
	return;
}

int main ()
{
	long i;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld", & N );
	
	F[ 2 ][ 0 ] = F[ 2 ][ 1 ] = 1;
	
	for ( i = 2; i < N; i++ )
		{
			Plus ( F[ i ], F[ i - 1 ], F[ i + 1 ] );
			Mult ( F[ i + 1 ], i, F[ i + 1 ] );
		}
		
	printf ( "%ld", F[ N ][ F[ N ][ 0 ] ] );
	
	for ( i = F[ N ][ 0 ] - 1; i > 0; i-- )
		{
			printf ( "%.4ld", F[ N ][ i ] );
		}
	
	printf ( "\n" );
	
	return ( 0 );
}
