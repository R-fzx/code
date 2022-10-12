#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "t1.in"
#define ouf "t1.out"

#define Model 10007
#define maxN 1000 + 5

long F[ maxN ];
long L[ maxN ], R[ maxN ];

long P[ maxN ] = 
	{
		0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
		73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 
		547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 
		811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 
		947, 953, 967, 971, 977, 983, 991, 997
	};

long Q[ maxN ];

long Size[ maxN ];

long N;

void CalcSize ( long Now ) 
{
	if ( ! Now )
		{
			return;
		}
	
	CalcSize ( L[ Now ] );
	CalcSize ( R[ Now ] );
	
	Size[ Now ] = Size[ L[ Now ] ] + Size[ R[ Now ] ] + 1;
	
	return;
}

long C ( long N, long M )
{
	long i, j, k, Ans, m;
	
	if ( M < N - M )
		{
			m = N - M;
		}
		else
			{
				m = M;
			}
	
	memset ( Q, 0, sizeof ( Q ) );
	
	for ( i = m + 1; i <= N; i++ )
		{
			k = i;
			
			for ( j = 1; P[ j ] <= k && k > 1; j++ )
				{
					while ( k % P[ j ] == 0 )
						{
							k /= P[ j ];
							Q[ j ]++;
						}
				}
		}
	
	for ( i = N - m; i; i-- )
		{
			k = i;
			
			for ( j = 1; P[ j ] <= k && k > 1; j++ )
				{
					while ( k % P[ j ] == 0 )
						{
							k /= P[ j ];
							Q[ j ]--;
						}
				}
		}
	
	Ans = 1;	
	for ( i = 1; P[ i ] != 0; i++ )
		{
			for ( j = 1; j <= Q[ i ]; j++ )
				{
					Ans = ( Ans * P[ i ] ) % Model;
				}
		}
	
	return ( Ans );
}

void Dfs ( long Now )
{
	long FL, FR;
		
	if ( L[ Now ] + R[ Now ] == 0 )
		{
			F[ Now ] = 1;
			
			return;
		}
	
	if ( L[ Now ] )
		{
			Dfs ( L[ Now ] );
			FL = F[ L[ Now ] ];
		}
		else
			{
				FL = 1;
			}
	
	if ( R[ Now ] )
		{
			Dfs ( R[ Now ] );
			FR = F[ R[ Now ] ];
		}
		else
			{
				FR = 1;
			}
	
	F[ Now ] = ( ( ( FL * FR ) % Model ) * C( Size[ L[ Now ] ] + Size[ R[ Now ] ], Size[ L[ Now ] ] ) ) % Model;
	
	if ( F[ Now ] == 0 )
		{
			F[ Now ] = 0;
		}
	
	return;
}

int main ()
{
	long test;
	long i, j, k, l;
	
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld", & test );
	
	while ( test-- )
		{
			scanf ( "%ld", & N );
			
			memset ( L, 0, sizeof ( L ) );
			memset ( R, 0, sizeof ( R ) );
			
			for ( i = 1; i <= N; i++ )
				{
					scanf ( "%ld", & l );
					
					if ( l == 0 )
						{
							continue;
						}
					
					scanf ( "%ld", & j );
					
					L[ i ] = j;
					l--;
					
					if ( l == 0 )
						{
							continue;
						}
					
					while ( l-- )
						{
							scanf ( "%ld", & k );
							
							R[ j ] = k;
							j = k;
						}
				}
		
			CalcSize ( 1 );
			
			Dfs ( 1 );
			
			printf ( "%ld\n", F[ 1 ] );
		}
	
	return ( 0 );
}
