#include<stdio.h>

int main()
{
	FILE *fs,*fp;
	fs=fopen("codes.in","r");
	fp=fopen("codes.out","w");
	int N,var;char line[50];
	fscanf(fs,"%d",&N);
	fscanf(fs,"%s",&line);
	N+=strlen(line);
	fprintf(fp,"%d\n",N);
	for(var=N/4;var>0;var--)
		fprintf(fp,"0011");
	N%=4;
	if(N<3)
		for(var=0;var<N;var++)
			fprintf(fp,"0");
	else
	{
		fprintf(fp,"00");
		for(var=2;var<N;var++)
			fprintf(fp,"1");
	}
	fprintf(fp,"\n");
	fclose(fs);fclose(fp);
	return 0;
}
