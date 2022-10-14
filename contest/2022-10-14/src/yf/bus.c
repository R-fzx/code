#include"stdio.h"
#define oo 100000000 
long long i,n,m,min,tot=0;
main()
{
  FILE *fp,*fq;
  fp=fopen("bus.in","r");
  fq=fopen("bus.out","w");
  fscanf(fp,"%I64d",&n);
  min=oo;
  for(i=1;i<=n;i++)
    {
      fscanf(fp,"%I64d",&m);
      if(m<min)min=m;
      tot+=min;
    }
  fprintf(fq,"%I64d",tot);
  fclose(fp);
  fclose(fq);
  return 0;
}
