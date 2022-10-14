#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
int main()
{
 FILE *fo,*fi;
 long n,len=0,i;
 char s[60];
 fi=fopen("codes.in","r");
 fo=fopen("codes.out","w");
 fscanf(fi,"%ld",&n);
 for (i=1;i<=n;i++)
     {
     fscanf(fi,"%s",s);
     len+=strlen(s);
     }
 fprintf(fo,"%ld\n",len/2);
 for (i=1;i<=len/2;i++)
 {
     fprintf(fo,"%ld",rand()%2);
 }
 fprintf(fo,"\n");
 fclose(fo);
 fclose(fi);
 return 0;
}
