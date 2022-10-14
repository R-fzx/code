#include <stdio.h>
long m[1000000]={0};
main()
{
      FILE *fq,*fp;
      long n,i,k;
      double sum=0;
      fp=fopen("bus.in","r");
      fq=fopen("bus.out","w");
      fscanf(fp,"%ld",&n);
      for(i=1;i<=n;i++)
      fscanf(fp,"%ld",&m[i]);
      k=1;
      sum=m[k];
      for(i=2;i<=n;i++)
      {
       if(m[i]>m[k]) 
        sum+=m[k];
       else {sum+=m[i]; k=i;}       
      }
      fprintf(fq,"%.0lf",sum);
      fclose(fq);
      fclose(fp);
      }
