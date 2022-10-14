#include<stdio.h>

long N,Site[200000][2];double Ans;

int main()
{
	FILE *fs,*fp;
	fs=fopen("dark.in","r");
	fp=fopen("dark.out","w");
	fscanf(fs,"%ld",&N);
	long a,b;double temp;
	for(a=0;a<N;a++)
		fscanf(fs,"%ld %ld",&Site[a][0],&Site[a][1]);
	Ans=3000000;
	for(a=0;a<N;a++)
		for(b=a+1;b<N;b++)
		{
			temp=abs(Site[a][0]-Site[b][0])+abs(Site[a][1]-Site[b][1]);
			Ans=Ans>temp?temp:Ans;
		}
	fprintf(fp,"%.2lf\n",Ans/2.0);
	fclose(fs);fclose(fp);
	return 0;
}
