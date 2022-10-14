#include<stdio.h>
#include<math.h>
int x[200001],y[200001];
int main()
{
    FILE *fs,*fp;
    fs=fopen("dark.in","r");
    fp=fopen("dark.out","w");
    int i,j,n,t;
    double ans,d,min=1000000000;
    fscanf(fs,"%d",&n);
    for(i=1;i<=n;i++)
       fscanf(fs,"%d%d",&x[i],&y[i]);
    for(i=1,t=1;i<=n&&t<10000000;i++)
       for(j=i+1;j<=n&&t<10000000;j++)
       {
          d=(double)(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
          if(min>d)
             min=d;
          t++;
       }
    ans=sqrt(min);
    fprintf(fp,"%0.2f",ans);
    fclose(fs);
    fclose(fp);
    return 0;
}
