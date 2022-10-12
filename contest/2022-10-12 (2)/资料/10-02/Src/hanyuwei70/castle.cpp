/*
ID:Angry Coffee
*/
#include<stdio.h>
FILE *fin,*fout;
const int INF=1000000000,MOD=2147483647;
int map[1001][1001],dist[1001],n,m,edge[499501][2],m2;
long long f[1001],ans;
bool v[1001];
void dijkstra()
{
	int i,j,k,min,minx;
	for (i=1;i<=n;++i) dist[i]=INF;
	dist[1]=0;
	for (i=1;i<=n;++i)
	{
		min=INF;minx=-1;
		for (j=1;j<=n;++j)
			if (!v[j] && dist[j]<min)
			{
				min=dist[j];
				minx=j;
			}
		v[minx]=true;
		for (j=1;j<=n;++j)
			if (!v[j] && dist[j]>dist[minx]+map[minx][j])
				dist[j]=dist[minx]+map[minx][j];
	}
}
void init()
{
	int i,j,x,y,z;
	fscanf(fin,"%d%d",&n,&m);
	for (i=1;i<=n;++i)
		for (j=1;j<=n;++j)
			map[i][j]=INF;
	for (i=1;i<=m;++i)
	{
		fscanf(fin,"%d%d%d",&x,&y,&z);
		if (x==y) continue;
		map[x][y]=(map[x][y]<z)?map[x][y]:z;
		map[y][x]=(map[y][x]<z)?map[y][x]:z;
	}
	for (i=1,m2=0;i<=n;++i)
		for (j=i+1;j<=n;++j)
			if (map[i][j]!=INF)
			{
				++m2;
				edge[m2][0]=i;
				edge[m2][1]=j;
			}
}
void work()
{
	int i;
	for (i=1;i<=m2;++i)
	{
		if (dist[edge[i][0]]+map[edge[i][0]][edge[i][1]]==dist[edge[i][1]]) ++f[edge[i][1]];
		if (dist[edge[i][1]]+map[edge[i][1]][edge[i][0]]==dist[edge[i][0]]) ++f[edge[i][0]];
	}
	f[1]=1;
	ans=f[1];
	for (i=2;i<=n;++i) 
		ans=(ans*(long long)f[i])%MOD;
}
int main()
{
	fin=fopen("Castle.in","r");
	fout=fopen("Castle.out","w");
	int i,j;
	init();
	dijkstra();
	work();
	fprintf(fout,"%I64d\n",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
