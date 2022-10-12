#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "Castle.in"
#define ouf "Castle.out"

#define Model ((1LL<<31)-1)

#define maxN 1000 + 5

long Dis[ maxN ];
long Hash[ maxN ];
long Sta[ maxN ], Head, Tail;

long G[ maxN ][ maxN ];

long F[ maxN ];

long long Ans;

long N, M;

int main ()
{
	long i, j, k;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld", & N, & M );
	
	memset ( G, 0x3f, sizeof ( G ) );
		
	while ( M-- )
		{
			scanf ( "%ld%ld%ld", & i, & j, & k );
			
			if ( G[ i ][ j ] > k )
				{
					G[ i ][ j ] = G[ j ][ i ] = k;
				}
		}
	
	Hash[ 1 ] = 1;
	Sta[ 1 ] = 1;
	
	memset ( Dis, 0x3f, sizeof ( Dis ) );
	Dis[ 1 ] = 0;
	
	Head = 0;
	Tail = 1;
	
	while ( Head != Tail )
		{
			Head = Head % N + 1;
			i = Sta[ Head ];
			
			for ( j = 1; j <= N; j++ )
				{
					if ( Dis[ i ] + G[ i ][ j ] < Dis[ j ] )
						{
							Dis[ j ] = Dis[ i ] + G[ i ][ j ];
							
							if ( ! Hash[ j ] )
								{
									Tail = Tail % N + 1;
									
									Sta[ Tail ] = j;
									Hash[ j ] = 1;
								}
						}
				}
			
			Hash[ i ] = 0;
		}
	
	for ( i = 1; i <= N; i++ )
		{
			for ( j = 1; j <= N; j++ )
				{
					if ( G[ i ][ j ] + Dis[ j ] == Dis[ i ] && i != j )
						{
							F[ i ]++;
						}
				}
		}
	
	Ans = 1;
	
	for ( i = 2; i <= N; i++ )
		{
			Ans = ( Ans * ( long long ) F[ i ] ) % Model;
		}
	
	printf ( "%I64d\n", Ans );
	
	return ( 0 );
}
