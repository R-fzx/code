#include <stdio.h>

int main ()
{
	freopen( "list.out", "w", stdout );
	
	long i, j, k = 0;
	
	for ( i = 2; i <= 1000; i++ )
		{
			for ( j = 2; j * j <= i; j++ )
				{
					if ( i % j == 0 )
						{
							goto NOT;
						}
				}
			
			printf ( "%ld, ", i );
			k++;
			
			if ( k % 20 == 0 )
				{
					printf ( "\n" );
				}
			
			NOT:;
		}
	
	return ( 0 );
}
