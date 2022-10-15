#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "road.in"
#define ouf "road.out"

#define maxN 200 + 7
#define maxE 50000 + 7

struct node
{
	long u, v;
	long long a, b;	
} E[ maxE ], Pick[ maxE ];

long Root[ maxN ];
long End[ 2 * maxN ], Next[ 2 * maxN ], Num[ 2 * maxN ];

long N, M, M1, Edge;

long Hash[ maxN ];

long long Ans = 1LL << 60, P, Q, MAX, MAXP;

void Qs ( long L, long R )
{
	long i, j;
	struct node tmp;
	
	if ( L >= R )
		{
			return;
		}
	
	i = L;
	j = R;
	tmp = E[ ( L + R ) / 2 ];
	E[ ( L + R ) / 2 ] = E[ L ];
	
	while ( i < j )
		{
			while ( i < j && tmp. a < E[ j ]. a )
				{
					j--;
				}
			
			if ( i < j )
				{
					E[ i++ ] = E[ j ];
				}
			
			while ( i < j && tmp. a > E[ i ]. a )
				{
					i++;
				}
			
			if ( i < j )
				{
					E[ j-- ] = E[ i ];
				}
		}
	
	E[ i ] = tmp;
	
	Qs ( L, i - 1 );
	Qs ( i + 1, R );
	
	return;
}

void Create ( long a, long b, long k )
{
	++Edge;
	
	End[ Edge ] = b;
	Next[ Edge ] = Root[ a ];
	Root[ a ] = Edge;
	Num[ Edge ] = k;
	
	return;
}

long Dfs ( long Now, long Dest )
{
	long j;
	
	Hash[ Now ] = 1;
	
	if ( Now == Dest )
		{
			return ( 1 );
		}
	
	j = Root[ Now ];
	while ( j )
		{
			if ( ! Hash[ End[ j ] ] )
				{
					if ( Dfs ( End[ j ], Dest ) )
						{
							if ( MAX < Pick[ Num[ j ] ]. b )
								{
									MAX = Pick[ Num[ j ] ]. b;
									MAXP = Num[ j ];
								}
							
							return ( 1 );
						}
				}
			
			j = Next[ j ];
		}
	
	Hash[ Now ] = 0;
	
	return ( 0 );
}

int main ()
{
	long long i, j, k;
	long long l, p;
	long long L = 0, R = 0, Mid;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld%I64d%I64d", & N, & M, & P, & Q );
	
	if ( M < N - 1 )
		{
			printf ( "-1\n" );
			
			return ( 0 );
		}
	
	for ( i = 1; i <= M; i++ )
		{
			scanf ( "%ld%ld%I64d%I64d", & E[ i ]. u, & E[ i ]. v, & E[ i ]. a, & E[ i ]. b );
		}
	
	Qs ( 1, M );
	
	for ( i = 1; i <= M; i++ )
		{
			memset ( Hash, 0, sizeof ( Hash ) );
			memset ( Root, 0, sizeof ( Root ) );
			memset ( Next, 0, sizeof ( Next ) );
			memset ( Num, 0, sizeof ( Num ) );
			
			Edge = 0;
			
			for ( j = 1; j <= M1; j++ )
				{
					Create ( Pick[ j ]. u, Pick[ j ]. v, j );
					Create ( Pick[ j ]. v, Pick[ j ]. u, j );
				}
			
			MAX = MAXP = 0;
			
			Hash[ E[ i ]. u ] = 1;
			
			if ( Dfs ( E[ i ]. u, E[ i ]. v ) )
				{
					if ( MAX > E[ i ]. b )
						{
							Pick[ MAXP ] = E[ i ];
						}
				}
				else
					{
						Pick[ ++M1 ] = E[ i ];
					}
			
			if ( M1 == N - 1 )
				{
					l = p = 0;
					
					for ( j = 1; j <= M1; j++ )
						{
							if ( l < Pick[ j ]. a )
								{
									l = Pick[ j ]. a;
								}
							
							if ( p < Pick[ j ]. b )
								{
									p = Pick[ j ]. b;
								}
						}
					
					if ( Ans > l * P + p * Q )
						{
							Ans = l * P + p * Q;
						}
				}
		}
	
	printf ( "%I64d\n", Ans );
	
	return ( 0 );
}
