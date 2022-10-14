#include"stdio.h"
#include"math.h"
long i,j,k,n;
long x[1000001],y[1000001];
double l,ans=100000000;
main()
{
  FILE *fp,*fq;
  fp=fopen("dark.in","r");
  fq=fopen("dark.out","w");
  fscanf(fp,"%ld",&n);
  for(i=1;i<=n;i++)
    {
      fscanf(fp,"%ld%ld",&x[i],&y[i]);
      for(j=1;j<i;j++)
        {
          l=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
          if(l<ans)ans=l;
        }
    }
  ans/=2;
  fprintf(fq,"%0.2lf",ans);
  fclose(fp);
  fclose(fq);
  return 0;
}
