#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{FILE *fo;
 fo=fopen("dark.in","w");
 int n,x,y,i;
 srand((unsigned)time(NULL));
 n=rand()%1000+1;
 fprintf(fo,"%d\n",n);
 for(i=1;i<=n;i++)fprintf(fo,"%d %d\n",rand()%10000,rand()%10000);
 fclose(fo);
} 
 
