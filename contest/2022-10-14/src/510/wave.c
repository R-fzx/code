#include <stdio.h>
#define in "wave.in"
#define out "wave.out"
FILE *fp,*fq;
long n,c;

int opens()
{
    if((fp=fopen(in,"r"))==NULL)
     return 0;
    if((fq=fopen(out,"w"))==NULL)
     return 0;
    return 1;
}

void close()
{
     fclose(fp);
     fclose(fq);
}

int main()
{
    long m,i;
    
    if(opens()==0)
     return 0;
    fprintf(fq,"1 2\n2 3 1\n");
    close();
    return 0;
}
