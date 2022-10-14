#include<stdio.h>
#define in "codes.in"
#define out "codes.out"
FILE *fs,*fp;
int N;
int main()
{
    if((fs=fopen(in,"r"))==NULL) return 0;
    if((fp=fopen(out,"w"))==NULL) return 0;
     fscanf(fs,"%d",&N);
     int i;
    fclose(fs);
    fclose(fp);
    return 0;
}
