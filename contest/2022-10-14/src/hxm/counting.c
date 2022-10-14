#include <stdio.h>
int suan(int x,int r[])
{
    int i,j,q,sum=0,t=1,k;
    int f[21]={0},z[21]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
    for( i=1,q=x ; q>0 ; q/=10,t*=10,i++ )
    {
      k=q%10;
      if(q<10) j=1;
      else j=0;
      for(;j<k;j++)
        r[j]+=t;
      r[k]+=f[i-1];
      f[i]=f[i-1]+t*k;
      for(j=0;j<10;j++)
        r[j]+=z[i-1]*k;
    }
}
int main()
{
    FILE *fr,*fw;
    int sums[20]={0},sume[20]={0},s,e,i;
    fr=fopen("counting.in","r");
    fw=fopen("counting.out","w");
    while(1)
    {
        fscanf(fr,"%d%d",&s,&e);
        if(s==0 && e==0)
           break;
        suan(s-1,sums);
        suan(e,sume);
        for(i=0;i<10;i++)
        {
           fprintf(fw,"%d ",sume[i]-sums[i]);
           sume[i]=sums[i]=0;
        }
        fprintf(fw,"\n");
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
