#include <stdio.h>
main()
{FILE *fp,*fo;
 int n,a[100001]={0},i,j,k,l,s=0;
 fp=fopen("bus.in","r");
 fo=fopen("bus.out","w");
 fscanf(fp,"%d",&n);
 for(i=1;i<=n;i++)
   fscanf(fp,"%d",&a[i]);
 i=1;
 a[n+1]=-100000000;
 while(i<n+1)
 {j=i+1;
  while(a[j]>a[i])j++;
  s+=(j-i)*a[i];
  i=j;
 } 
 fprintf(fo,"%d\n",s);
 fclose(fp);
 fclose(fo);
} 
