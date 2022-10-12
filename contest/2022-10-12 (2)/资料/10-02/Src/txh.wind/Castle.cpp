#include<stdio.h>
#include<stdlib.h>
int side[1010][1010],queue[3010],dist[1010],f[1010];
bool mark[1010];
FILE *fin,*fout;
int main()
{
	int n,m,a,b,c,i,j,first=0,rear=1,now;
	long long ans=1;
	fin=fopen("Castle.in","r");
	fout=fopen("Castle.out","w");
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			side[i][j]=2100000000;
	for(i=0;i<m;++i)
	{
		fscanf(fin,"%d%d%d",&a,&b,&c);
		if(a==b)
			continue;
		if(side[a][b]>c)
		{
			side[a][b]=c;
			side[b][a]=c;
		}
	}
	for(i=2;i<=n;++i)
		dist[i]=2100000000;
	queue[0]=1;
	f[1]=1;
	while(first<rear)
	{
		now=queue[first++];
		mark[now]=0;
		for(i=2;i<=n;++i)
		{
			if(i==now)
				continue;
			if(side[now][i]>0)
			{
				if(dist[i]>dist[now]+side[now][i])
				{
					f[i]=1;
					dist[i]=dist[now]+side[now][i];
					if(!mark[i])						
					{
						if(dist[i]>dist[first])
							queue[rear++]=i;
						else
							queue[--first]=i;
						mark[i]=1;
					}
				}
				else if(dist[i]==dist[now]+side[now][i])
					++f[i];
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		ans*=f[i];
		ans%=2147483647;
	}
	fprintf(fout,"%I64d",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
