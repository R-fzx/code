#include<stdio.h>

int M,N,C,Count,List[1000001];char Pan,Hash[1000001];

void Fun(int num,int way,int site)
{
    int a,b;
	List[site]=num;
	if(site==N-1)
	{             
		if(way==0)
		{
			for(a=1;a<num;a++)
				if(Hash[a]==0)
				{
					List[N]=a;
					Count++;
					if(Count==C) Pan=1;
				}
		}
		else
		{
			for(a=num+1;a<=N;a++)
				if(Hash[a]==0)
				{
					List[N]=a;
					Count++;
					if(Count==C) Pan=1;
				}
		}
    }
	else if(way==0)
	{
		for(a=1;a<num;a++)
			if(Hash[a]==0)
			{
				Hash[a]=1;
				Fun(a,1,site+1);
				Hash[a]=0;
				if(Pan==1) break;
			}
	}
	else
	{
		for(a=num+1;a<=N;a++)
			if(Hash[a]==0)
			{
				Hash[a]=1;
				Fun(a,0,site+1);
				Hash[a]=0;
				if(Pan==1) break;
			}
	}
}

int main()
{
	FILE *fs,*fp;
	fs=fopen("wave.in","r");
	fp=fopen("wave.out","w");
	fscanf(fs,"%d",&M);
	int var,temp;
	for(var=0;var<M;var++)
	{
		fscanf(fs,"%d %d",&N,&C);
		memset(List,0,sizeof(List));
		memset(Hash,0,sizeof(Hash));
		Pan=0;Count=0;
		for(temp=1;temp<=N;temp++)
		{
			Hash[temp]=1;
			Fun(temp,0,1);
			if(Pan==0) Fun(temp,1,1);
			Hash[temp]=0;
			if(Pan==1) break;
		}
		for(temp=1;temp<N;temp++)
			fprintf(fp,"%d ",List[temp]);
		fprintf(fp,"%d\n",List[temp]);
	}
	fclose(fs);fclose(fp);
	return 0;
}
