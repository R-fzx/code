#include<stdio.h>

int N;double Ans,Cost[100005];

int main()
{
	FILE *fs,*fp;
	fs=fopen("bus.in","r");
	fp=fopen("bus.out","w");
	fscanf(fs,"%d",&N);
	int var,stop;double temp;
	for(var=0;var<N;var++)
		fscanf(fs,"%lf",&Cost[var]);
	for(var=1,stop=0,temp=Cost[stop];var<N;var++)
		if(temp>Cost[var])
		{
			Ans+=(var-stop)*Cost[stop];
			stop=var;temp=Cost[stop];
		}
	Ans+=(var-stop)*Cost[stop];
	fprintf(fp,"%.0lf\n",Ans);
	fclose(fs);fclose(fp);
	return 0;
}
