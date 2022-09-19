#include <cstdio>
#include <cstring>

#define maxn 100 + 10
#define maxm 20000 + 10
#define mod 10000
#define min(a,b) ( (a) < (b) ? (a) : (b) )
#define max(a,b) ( (a) > (b) ? (a) : (b) )

int n,m,k;
int e[maxm] = {0},last[maxm] = {0},now[maxn] = {0};

int t = 0,dfn[maxn] = {0},low[maxn] = {0};
int s = 0,fa[maxn] = {0},size[maxn] = {0};
int stack[maxn] = {0},top = 0;
bool in[maxn] = {0},out[maxn] = {0};

int a[maxn] = {0};
struct bignum
{
	int a[20];
}f[maxn][maxn] = {0},c[maxn][maxn] = {0},one,d;

void tarjan( int i )
{
	int j;

	dfn[i] = ++t;
	low[i] = t;
	stack[++top] = i;

	for( j = now[i] ; j ; j = last[j] )
		{
			if( !dfn[e[j]] )
				{
					tarjan( e[j] );
					low[i] = min( low[i], low[e[j]] );
				}
			else if( !fa[e[j]] )
				low[i] = min( low[i], dfn[e[j]] );
		}

	if( dfn[i] == low[i] )
		{
			size[++s] = 0;
			do  {
					fa[stack[top]] = s;
					++size[s];
				}
			while( stack[top--] != i );
		}
}

inline void clear( bignum &a )
{
	int i;
	for( i = 1 ; i <= a.a[0] ; ++i )
		a.a[i] = 0;
	a.a[0] = 1;
}

inline void maintain( bignum &a )
{
	int i;
	for( i = 1 ; i <= a.a[0] ; ++i )
		{
			a.a[i+1] += a.a[i] / mod;
			a.a[i] %= mod;
			if( a.a[a.a[0]+1] )
				++a.a[0];
		}
	while( !a.a[a.a[0]] ) --a.a[0];
}

inline void operator += ( bignum &a, bignum &b )
{
	int i;
	for( i = 1 ; i <= b.a[0] ; ++i )
		a.a[i] += b.a[i];
	a.a[0] = max( a.a[0], b.a[0] );
	maintain(a);
}

inline bignum operator *= ( bignum &a, bignum &b )
{
	int i,j;
	clear(d);
	for( i = 1 ; i <= a.a[0] ; ++i )
		for( j = 1 ; j <= b.a[0] ; ++j )
			d.a[i+j-1] += a.a[i] * b.a[j];
	d.a[0] = a.a[0] + b.a[0] - 1;
	maintain(d);
	a = d;
}

int main()
{
	int T,Test;
	int i,j,l,u,v,p,q;

	FILE *fp,*fo;
	fp = fopen("poffice.in","r");
	fo = fopen("poffice.out","w");

	bignum ans = {0},temp;

	one.a[0] = one.a[1] = 1;
	for( i = 0 ; i <= 100 ; ++i )
		c[i][0] = one;
	for( i = 1 ; i <= 100 ; ++i )
		for( j = 1 ; j <= i ; ++j )
			{
				c[i][j] += c[i-1][j];
				c[i][j] += c[i-1][j-1];
			}

	fscanf(fp,"%d",&Test);
	for( T = 1 ; T <= Test ; ++T )
		{
			fscanf(fp,"%d%d%d",&n,&m,&k);
			for( i = 1 ; i <= m ; ++i )
				{
					fscanf(fp,"%d%d",&u,&v);
					e[i] = v;
					last[i] = now[u];
					now[u] = i;
				}
			for( i = 1 ; i <= n ; ++i )
				if( !dfn[i] )
					tarjan(i);	
			for( i = 1 ; i <= n ; ++i )
				for( j = now[i] ; j ; j = last[j] )
					if( fa[i] != fa[e[j]] )
						out[fa[i]] = 1, in[fa[e[j]]] = 1;
			p = 0, q = n;
			for( i = 1 ; i <= s ; ++i )
				if( !out[i] || !in[i] )
					{
						a[++p] = size[i];
						q -= size[i];
					}	
			f[0][0] = one;
			for( i = 1 ; i <= p ; ++i )
				for( j = i ; j <= n ; ++j )
					for( l = 1 ; l <= a[i] && l <= j ; ++l )
						{
							temp = c[a[i]][l];
							temp *= f[i-1][j-l];
							f[i][j] += temp;
						}
			clear(ans);
			for( i = p ; i <= k ; ++i )
				{
					temp = f[p][i];
					temp *= c[q][k-i];
					ans += temp;
				}
			fprintf(fo,"%d",ans.a[ans.a[0]]);
			for( i = ans.a[0]-1 ; i >= 1 ; --i )
				fprintf(fo,"%04d",ans.a[i]);
			fprintf(fo,"\n");

			memset( now, 0, sizeof(now) );
			t = s = 0;
			memset( dfn, 0, sizeof(dfn) );
			memset( fa, 0, sizeof(fa) ); 
			memset( in, 0, sizeof(in) );
			memset( out, 0, sizeof(out) );
			memset( f, 0, sizeof(f) );
		}

	fclose(fp);
	fclose(fo);
	return(0);
}
