#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "ゆりっぺ.in"
#define ouf "ゆりっぺ.out"

#define maxN 500000 + 5
#define maxP 100 + 5

struct node
{
	long long a, b, c;
	long pick;
} E[ maxN ];

long long F[ maxP ][ maxP ][ maxP ];
long long G[ maxP ][ maxP ][ maxP ];

long N, A, B, C;

void QuickA ( long L, long R )
{
	long i, j;
	struct node tmp;
	
	if ( L >= R )
		{
			return;
		}
	
	i = L;
	j = R;
	
	tmp = E[ ( i + j ) / 2 ];
	E[ ( i + j ) / 2 ] = E[ L ];
	
	while ( i < j )	
		{
			while ( i < j && tmp. a >= E[ j ]. a )
				{
					j--;
				}
			
			if ( i < j )
				{
					E[ i++ ] = E[ j ];
				}
			
			while ( i < j && tmp. a <= E[ i ]. a )
				{
					i++;
				}
			
			if ( i < j )
				{
					E[ j-- ] = E[ i ];
				}
		}
	
	E[ i ] = tmp;
	
	QuickA ( L, i - 1 );
	
	if ( i < A + B + C )
		{
			QuickA ( i + 1, R );
		}
	
	return;
}

void QuickB ( long L, long R )
{
	long i, j;
	struct node tmp;
	
	if ( L >= R )
		{
			return;
		}
	
	i = L;
	j = R;
	
	tmp = E[ ( i + j ) / 2 ];
	E[ ( i + j ) / 2 ] = E[ L ];
	
	while ( i < j )	
		{
			while ( i < j && tmp. b >= E[ j ]. b )
				{
					j--;
				}
			
			if ( i < j )
				{
					E[ i++ ] = E[ j ];
				}
			
			while ( i < j && tmp. b <= E[ i ]. b )
				{
					i++;
				}
			
			if ( i < j )
				{
					E[ j-- ] = E[ i ];
				}
		}
	
	E[ i ] = tmp;
	
	QuickB ( L, i - 1 );
	
	if ( i < A + B + C )
		{
			QuickB ( i + 1, R );
		}
	
	return;
}

void QuickC ( long L, long R )
{
	long i, j;
	struct node tmp;
	
	if ( L >= R )
		{
			return;
		}
	
	i = L;
	j = R;
	
	tmp = E[ ( i + j ) / 2 ];
	E[ ( i + j ) / 2 ] = E[ L ];
	
	while ( i < j )	
		{
			while ( i < j && tmp. c >= E[ j ]. c )
				{
					j--;
				}
			
			if ( i < j )
				{
					E[ i++ ] = E[ j ];
				}
			
			while ( i < j && tmp. c <= E[ i ]. c )
				{
					i++;
				}
			
			if ( i < j )
				{
					E[ j-- ] = E[ i ];
				}
		}
	
	E[ i ] = tmp;
	
	QuickC ( L, i - 1 );
	
	if ( i < A + B + C )
		{
			QuickC ( i + 1, R );
		}
	
	return;
}

int main ()
{
	long i, j, k, l;
	long long a, b, c;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld%ld%ld", & N, & A, & B, & C );
	
	if ( A + B + C > N )
		{
			printf ( "I am a godlike cowcowcow\n" );
			
			return ( 0 );
		}
	
	for ( i = 1; i <= N; i++ )
		{
			scanf ( "%I64d%I64d%I64d", & E[ i ]. a, & E[ i ]. b, & E[ i ]. c );
		}
	
	memset ( F, 0xf7, sizeof ( F ) );
	memset ( G, 0xf7, sizeof ( G ) );
	
	F[ 0 ][ 0 ][ 0 ] = G[ 0 ][ 0 ][ 0 ] = 0;
	
	QuickA ( 1, N );
	
	for ( i = 1; i <= A + B + C; i++ )
		{
			E[ i ]. pick = 1;
		}
	
	QuickB ( 1, N );
	
	for ( i = 1; i <= A + B + C; i++ )
		{
			E[ i ]. pick = 1;
		}
	
	QuickC ( 1, N );
	
	for ( i = 1; i <= A + B + C; i++ )
		{
			E[ i ]. pick = 1;
		}
	
	for ( i = 1; i <= N; i++ )
		{
			if ( E[ i ]. pick == 0 )
				{
					continue;
				}
			
			a = E[ i ]. a;
			b = E[ i ]. b;
			c = E[ i ]. c;
			
			for ( j = A; j >= 0; j-- )
				{
					for ( k = B; k >= 0; k-- )
						{
							for ( l = C; l >= 0; l-- )
								{
									if ( j > 0 )	//	Allocate it to A
										{
											if ( F[ j ][ k ][ l ] <  F[ j - 1 ][ k ][ l ] + a ||
												 F[ j ][ k ][ l ] == F[ j - 1 ][ k ][ l ] + a && 
												 G[ j ][ k ][ l ] <  G[ j - 1 ][ k ][ l ] + a + b + c )
												{
													F[ j ][ k ][ l ] = F[ j - 1 ][ k ][ l ] + a;
													G[ j ][ k ][ l ] = G[ j - 1 ][ k ][ l ] + a + b + c;
												}
										}
									
									if ( k > 0 )	//	Allocate it to B
										{
											if ( F[ j ][ k ][ l ] <  F[ j ][ k - 1 ][ l ] + b ||
												 F[ j ][ k ][ l ] == F[ j ][ k - 1 ][ l ] + b && 
												 G[ j ][ k ][ l ] <  G[ j ][ k - 1 ][ l ] + a + b + c )
												{
													F[ j ][ k ][ l ] = F[ j ][ k - 1 ][ l ] + b;
													G[ j ][ k ][ l ] = G[ j ][ k - 1 ][ l ] + a + b + c;
												}
										}
									
									if ( l > 0 )	//	Allocate it to C
										{
											if ( F[ j ][ k ][ l ] <  F[ j ][ k ][ l - 1 ] + c ||
												 F[ j ][ k ][ l ] == F[ j ][ k ][ l - 1 ] + c && 
												 G[ j ][ k ][ l ] <  G[ j ][ k ][ l - 1 ] + a + b + c )
												{
													F[ j ][ k ][ l ] = F[ j ][ k ][ l - 1 ] + c;
													G[ j ][ k ][ l ] = G[ j ][ k ][ l - 1 ] + a + b + c;
												}
										}
								}
						}
				}
		}
	
	printf ( "%I64d\n%I64d\n", F[ A ][ B ][ C ], G[ A ][ B ][ C ] );
	
	return ( 0 );
}
