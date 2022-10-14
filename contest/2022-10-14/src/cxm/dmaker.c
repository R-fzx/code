#include<stdio.h>
#include<time.h>
FILE *fo;
int main()
{
 srand(time(NULL));
 int n;
 fo=fopen("dark.in","w");
 n=rand()%100+2;
 fprintf(fo,"%ld\n",n);
 for(;n>0;n--)fprintf(fo,"%ld %ld\n",rand()%20,rand()%20);
 fclose(fo);
 return(0);    
}
