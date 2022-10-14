#include<stdio.h>
#define in "bus.in"
#define out "bus.out"
FILE *fs,*fp;
int main()
{
    if((fs=fopen(in,"r"))==NULL) return 0;
    if((fp=fopen(out,"w"))==NULL) return 0;
     int N;
     fscanf(fs,"%d",&N);
     int i,j;
     double ans=0;
     for(i=1;i<=N;i++)
     {
      fscanf(fs,"%d",&j);
      ans+=j;
     }
     fprintf(fp,"%.0lf\n",ans);
    fclose(fs);
    fclose(fp);
    return 0;
}
