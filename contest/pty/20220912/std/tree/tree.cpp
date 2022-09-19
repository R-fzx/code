#include <cstdio>
#define maxn 15000 + 10

struct stu
{
	int u,v,w;
}e[maxn] = {0};
int fa[maxn] = {0},num[maxn] = {0};

void quick( int i, int j )
{
	if( i < j )
		{
			int x = i, y = j;
			stu temp = e[(i+j)/2];
			e[(i+j)/2] = e[i];
			e[i] = temp;

			while( x < y )
				{
					while( x < y && e[y].w > temp.w ) --y;
					if( x < y )
						e[x++] = e[y];
					while( x < y && e[x].w < temp.w ) ++x;
					if( x < y )
						e[y--] = e[x];
				}
			e[x] = temp;
			quick(i,x-1);
			quick(x+1,j);
		}
}

int getfa( int i ) { return( fa[i] != i ? fa[i] = getfa(fa[i]) : i ); }

int main()
{
	int T,Test;
	int n,i,f1,f2;
	long long ans;
	FILE *fp,*fo;

	fp = fopen("tree.in","r");
	fo = fopen("tree.out","w");

	fscanf(fp,"%d",&Test);
	for( T = 1 ; T <= Test ; ++T )
		{
			fscanf(fp,"%d",&n);
			for( i = 1 ; i < n ; ++i )
				fscanf(fp,"%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			quick(1,n-1);
			for( i = 1 ; i <= n ; ++i )
				fa[i] = i, num[i] = 1;
			ans = 0;
			for( i = 1 ; i < n ; ++i )
				{
					f1 = getfa(e[i].u);
					f2 = getfa(e[i].v);
					ans += (long long)num[f1] * num[f2] * (e[i].w+1) - 1;
					fa[f1] = f2;
					num[f2] += num[f1];

				}
			fprintf(fo,"%I64d\n",ans);
		}

	fclose(fp);
	fclose(fo);
	return(0);
}
