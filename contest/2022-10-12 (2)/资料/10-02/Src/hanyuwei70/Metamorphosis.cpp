#include<stdio.h>
FILE *fin,*fout;
int main()
{
	fin=fopen("Metamorphosis.in","r");
	fout=fopen("Metamorphosis.out","w");
	fprintf(fout,"%.1f",rand()%200);
	fclose(fin);
	fclose(fout);
	return 0;
}
