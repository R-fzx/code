#include<stdio.h>

int N;double Cost[100005];

double Fun(int stop,double cost)
{
	int a;double b;
	for(a=stop+1,b=Cost[stop];a<N;a++)
		if(b>Cost[a])
			break;
	if(a==N)
		return (N-stop)*Cost[stop]+cost;
	else
		return Fun(a,(a-stop)*Cost[stop]+cost);
}

int main()
{
	FILE *fs,*fp;
	fs=fopen("bus.in","r");
	fp=fopen("bus.out","w");
	fscanf(fs,"%d",&N);
	int var;
	for(var=0;var<N;var++)
		fscanf(fs,"%lf",&Cost[var]);
	fprintf(fp,"%.0lf\n",Fun(0,0));
	fclose(fs);fclose(fp);
	return 0;
}
