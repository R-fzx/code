#include<stdio.h>
double a[100001]={0};
main()
 {
  FILE *fp,*fo;
  long i,j,k,l,m,n;
  double ans=0;
  fp=fopen("bus.in","r");
  fo=fopen("bus.out","w");
  fscanf(fp,"%ld",&n);
  for(i=1;i<=n;i++)
   fscanf(fp,"%lf",&a[i]);
  j=1;
  a[n+1]=-100000000;
  while(j!=n+1)
  {
   for(i=j+1;;i++)
    {
     if(a[i]<a[j])
      break;
    } 
   ans+=(i-j)*1.0*a[j];
   j=i; 
  }
  fprintf(fo,"%.0lf\n",ans);
  fclose(fp);
  fclose(fo);
 }
