#include <cstdio>
#include <cstring>

#define maxn 15
#define maxm 50
#define maxp 260
#define oo 1000000000

FILE *fp,*fo;
int n,m,q;
int map[maxn][maxn] = {0};
struct stu
{
	int l,f,x[3],y[3],c[3];
}t[maxm] = {0};
int f[maxn][maxp][maxp] = {0};
int pow[maxn] = {0},st[maxn] = {0};

bool hash[maxm] = {0};
int cho[maxn][maxn][maxm] = {0};

inline void swap( int &a, int &b ) { int t = a; a = b; b = t; }

inline void spin()
{
	int i,j,p;
	for( i = 1 ; i < 4 ; ++i )
		{
			t[q+1] = t[q];
			++q;
			for( j = 0 ; j < t[q].l ; ++j )
				{
					p = t[q].x[j];
					t[q].x[j] = t[q].y[j];
					t[q].y[j] = -p;
				}
		}
}

inline void init()
{
	int i,j,k,p,u,v;
	bool ok;

	fscanf(fp,"%d%d%d",&n,&m,&k);
	for( i = 1 ; i <= n ; ++i )
		for( j = 1 ; j <= m ; ++j )
			fscanf(fp,"%d",&map[i][j]);
	for( i = n+1 ; i <= n+2 ; ++i )
		for( j = 1 ; j <= m ; ++j )
			map[i][j] = 2;
	for( i = 1 ; i <= m ; ++i )
		pow[i] = (1 << (i-1));
	q = 0;
	for( i = 1 ; i <= k ; ++i )
		{
			++q;
			fscanf(fp,"%d%d",&p,&t[q].f);
			if( p == 1 )
				{
					t[q].l = 1;
					t[q].x[0] = 0, t[q].y[0] = 0;
					fscanf(fp,"%d",&t[q].c[0]);
				}
			if( p == 2 )
				{
					t[q].l = 2;
					t[q].x[0] = 0, t[q].y[0] = 0;
					t[q].x[1] = 0, t[q].y[1] = 1;
					fscanf(fp,"%d%d",&t[q].c[0],&t[q].c[1]);
					spin();
				}
			if( p == 3 )
				{
					t[q].l = 3;
					t[q].x[0] = 0, t[q].y[0] = 0;
					t[q].x[1] = 0, t[q].y[1] = 1;
					t[q].x[2] = 0, t[q].y[2] = 2;
					fscanf(fp,"%d%d%d",&t[q].c[0],&t[q].c[1],&t[q].c[2]);
					spin();
				}
			if( p == 4 )
				{
					t[q].l = 3;
					t[q].x[0] = 0, t[q].y[0] = 0;
					t[q].x[1] = 0, t[q].y[1] = 1;
					t[q].x[2] = 1, t[q].y[2] = 1;
					fscanf(fp,"%d%d%d",&t[q].c[0],&t[q].c[1],&t[q].c[2]);
					spin();
				}
		}

	for( i = 1 ; i <= q ; ++i )
		{
			for( j = 0 ; j < t[i].l ; ++j )
				for( k = j+1 ; k < t[i].l ; ++k )
					if( t[i].x[j] > t[i].x[k] || (t[i].x[j] == t[i].x[k] && t[i].y[j] > t[i].y[k] ) )
						{
							swap( t[i].x[j], t[i].x[k] );
							swap( t[i].y[j], t[i].y[k] );
							swap( t[i].c[j], t[i].c[k] );
						}		
			for( j = t[i].l-1 ; j >= 0 ; --j )
				t[i].x[j] -= t[i].x[0], t[i].y[j] -= t[i].y[0];
		}

	for( i = 1 ; i <= q ; ++i )
		{
			hash[i] = 1;
			for( j = 1 ; j <= q && hash[i] ; ++j )
				if( ( t[i].f > t[j].f || ( t[i].f == t[j].f && j > i ) ) && t[i].l == t[j].l )
					{
						for( k = 0 ; k < t[i].l ; ++k )
							if( t[i].x[k] != t[j].x[k] || t[i].y[k] != t[j].y[k] || t[i].c[k] != t[j].c[k] )
								break;
						hash[i] = ( k < t[i].l );
					}
		}

	for( i = 1 ; i <= n ; ++i )
		for( j = 1 ; j <= m ; ++j )
			for( cho[i][j][0] = 0, k = 1 ; k <= q ; ++k )
				{
					ok = hash[k];
					for( p = 0 ; p < t[k].l && ok ; ++p )
						{
							u = i + t[k].x[p];
							v = j + t[k].y[p];
							if( !( v >= 1 && v <= m ) )
								ok = 0;
							else if( map[u][v] != t[k].c[p] )
								ok = 0;
						}
					if( ok )
						cho[i][j][++cho[i][j][0]] = k;
				}
}

int s[3] = {0};

void dfs( int i, int p, int sum )
{
	int j,k,l;
	bool flag;

	if( i <= m )
		{
			if( s[0] & pow[i] )
				dfs(i+1,p,sum);
			else
				for( k = 1 ; k <= cho[p][i][0] ; ++k )
					{
						j = cho[p][i][k];
						flag = 1;
						for( l = 0 ; l < t[j].l && flag ; ++l )
							if( s[t[j].x[l]] & pow[i+t[j].y[l]] )
								flag = 0;
						if( flag )
							{
								for( l = 0 ; l < t[j].l ; ++l )
									s[t[j].x[l]] += pow[i+t[j].y[l]];
								dfs(i+1,p,sum+t[j].f);
								for( l = 0 ; l < t[j].l ; ++l )
									s[t[j].x[l]] -= pow[i+t[j].y[l]];
							}
					}
		}
	else if( f[p][s[1]][s[2]] == -1 || f[p][s[1]][s[2]] > sum )
		f[p][s[1]][s[2]] = sum;
}

inline void work()
{
	int i,j,k,p;
	p = (1 << m);

	memset( f, -1, sizeof(f) );
	for( i = 1 ; i <= n+2 ; ++i )
		for( st[i] = 0, j = m ; j >= 1 ; --j )
			st[i] = (st[i] << 1) + (map[i][j] == 2);
	f[0][st[1]][st[2]] = 0;

	for( i = 0 ; i < n ; ++i )
		for( j = st[i+1] ; j < p ; ++j )
			for( k = st[i+2] ; k < p ; ++k )
				if( f[i][j][k] != -1 )
					{
						s[0] = j, s[1] = k, s[2] = st[i+3];
						dfs(1,i+1,f[i][j][k]);
					}

	if( f[n][p-1][p-1] != -1 )
		fprintf(fo,"%d\n",f[n][p-1][p-1]);
	else fprintf(fo,"-1\n");
}

int main()
{
	int T,Test;

	fp = fopen("tile.in","r");
	fo = fopen("tile.out","w");

	fscanf(fp,"%d",&Test);
	for( T = 1 ; T <= Test ; ++T )
		{
			init();
			work();
		}

	fclose(fp);
	fclose(fo);
	return(0);
}
