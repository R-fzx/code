#include<stdio.h>

long N,Site[200000][2];double Ans;

void Qsort(long st,long en)
{
	long a,b,c,d;
	a=(st+en)/2;
	b=Site[a][0];c=Site[a][1];
	Site[a][0]=Site[st][0];
	Site[a][1]=Site[st][1];
	Site[st][0]=b;
	Site[st][1]=c;
	a=st,b=en,c=Site[a][0];d=Site[a][1];
	while(a<b)
	{
		while(a<b)
		{
			if(Site[b][0]<c)
				{Site[a][0]=Site[b][0];Site[a][1]=Site[b][1];break;}
			b--;
		}
		while(a<b)
		{
			if(Site[a][0]>c)
				{Site[b][0]=Site[a][0];Site[b][1]=Site[a][1];break;}
			a++;
		}
	}
	Site[a][0]=c;Site[a][1]=d;
	if(st<a-1) Qsort(st,a-1);
	if(a+1<en) Qsort(a+1,en);
}

int main()
{
	FILE *fs,*fp;
	fs=fopen("dark.in","r");
	fp=fopen("dark.out","w");
	fscanf(fs,"%ld",&N);
	long a,b;double temp;
	for(a=0;a<N;a++)
		fscanf(fs,"%ld %ld",&Site[a][0],&Site[a][1]);
	Qsort(0,N-1);
	Ans=3000000;
	for(a=0;a<N;a++)
		for(b=a+1;b<a+11&&b<N;b++)
		{
			temp=(double)(Site[a][0]-Site[b][0])*(Site[a][0]-Site[b][0]);
			temp+=(double)(Site[a][1]-Site[b][1])*(Site[a][1]-Site[b][1]);
			temp=sqrt(temp);
			Ans=Ans>temp?temp:Ans;
		}
	fprintf(fp,"%.2lf\n",Ans/2.0);
	fclose(fs);fclose(fp);
	return 0;
}
