#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf "Metamorphosis.in"
#define ouf "Metamorphosis.out"

#define zero 1e-8

long U, D, L, R;

double Ans;

inline int Inside ( long x, long y )
{
	return ( y >= U && y <= D && x <= R && x >= L );
}

inline double Calc ( double Len, long Level )
{
	return ( Len + 2 * Level / 3 );
}

void Dfs ( double xa, double ya, double xb, double yb, long Level )
{
	double Len;
	
	if ( Level == 5 )
		{
			if ( ! Inside ( xa, ya ) || ! Inside ( xb, yb ) )
				{
					return;
				}
			
			if ( fabs ( xa - xb ) <= zero )
				{
					if ( xa == L || xa == R )
						{
							Ans += 166;
						}
						else
							{
								Ans += 331;
							}
				}
				else
					{
						if ( ya == U || ya == D )
							{
								Ans += 166;
							}
							else
								{
									Ans += 331;
								}
					}
			
			return;
		}
	
	if ( fabs ( xa - xb ) <= zero )
		{			
			Len = yb - ya;
			
			Dfs ( xa, ya + 2 * Len / 3, xb, yb, Level + 1 );
			Dfs ( xa, ya + 2 * Len / 3, xa + Len / 3, ya + 2 * Len / 3, Level + 1 );
			Dfs ( xa, ya + 2 * Len / 3, xa - Len / 3, ya + 2 * Len / 3, Level + 1 );
			
			if ( xa <= R && xa >= L )
				{
					double u, d, k;
					
					u = yb - Len / 3;
					d = ya;
					
					if ( u > d )
						{
							k = u;
							u = d;
							d = k;
						}
					
					if ( u < U )
						{
							u = U;
						}
					
					if ( d > D )
						{
							d = D;
						}
					
					if ( d > u )
						{
							Ans += d - u;
						}
				}
		}
		else	
			{
				Len = xb - xa;
				
				Dfs ( xa + 2 * Len / 3, ya, xb, yb, Level + 1 );
				Dfs ( xa + 2 * Len / 3, ya, xa + 2 * Len / 3, ya + Len / 3, Level + 1 );
				Dfs ( xa + 2 * Len / 3, ya, xa + 2 * Len / 3, ya - Len / 3, Level + 1 );
				
				if ( ya <= D && ya >= U )
					{
						double l, r, k;
						
						r = xb - Len / 3;
						l = xa;
						
						if ( l > r )
							{
								k = l;
								l = r;
								r = k;
							}
						
						if ( l < L )
							{
								l = L;
							}
						
						if ( r > R )
							{
								r = R;
							}
						
						if ( r > l )
							{
								Ans += r - l;
							}
					}
			}
	
	return;
}


int main ()
{
	freopen ( inf, "r", stdin );
	freopen ( ouf, "w", stdout );
	
	scanf ( "%ld%ld%ld%ld", & L, & U, & R, & D );
	
	Dfs ( 0, 0, 0, 81, 1 );
	
	printf ( "%.1lf\n", Ans );
	
	return ( 0 );
}
