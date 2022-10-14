#include <stdio.h>
main()
{FILE *fp,*fo;
 long long n,a[100001]={0},i,j,k,l,s=0;
 fp=fopen("bus.in","r");
 fo=fopen("bus.out","w");
 fscanf(fp,"%I64d",&n);
 for(i=1;i<=n;i++)
   fscanf(fp,"%I64d",&a[i]);
 i=1;
 a[n+1]=-100000000;
 while(i<n+1)
 {j=i+1;
  while(a[j]>a[i])j++;
  s+=(j-i)*a[i];
  i=j;
 } 
 fprintf(fo,"%I64d\n",s);
 fclose(fp);
 fclose(fo);
} 
