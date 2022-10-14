#include<stdio.h>
int main()
{
    FILE *fs,*fp;
    fs=fopen("bus.in","r");
    fp=fopen("bus.out","w");
    int i,ai,n,min=2000000000;
    double ans=0;
    fscanf(fs,"%d",&n);
    for(i=1;i<=n;i++)
    {
       fscanf(fs,"%d",&ai);
       if(ai<min)
       {
          ans+=ai;
          min=ai;
       }
       else
          ans+=min;
    }
    fprintf(fp,"%.0f\n",ans);
    fclose(fs);
    fclose(fp);
    return 0;
}
