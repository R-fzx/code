#include<stdio.h>
#include<string>
#define IN "codes.in"
#define OUT "codes.out"
FILE *fo,*fp;

char s[29][29];
int n,sum;
bool init()
{
	if((fp=fopen(IN,"r"))==NULL)return 1;
	if((fo=fopen(OUT,"w"))==NULL)return 1;
}
void exit()
{
	fclose(fo);
	fclose(fp);
}
int main()
{
	if(init())return 1;
	fscanf(fp,"%d\n",&n);
	int i;
	//db
	for(i=0;i<n;i++){fscanf(fp,"%s\n",&s[i]);
	sum+=strlen(s[i]);
	}
	fprintf(fo,"%d\n",sum);
	for(i=0;i<n;i++)fprintf(fo,"%s",s[i]);
	fprintf(fo,"\n");
	//
	exit();
	return 0;
}
