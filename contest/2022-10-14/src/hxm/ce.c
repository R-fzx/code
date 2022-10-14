#include <stdio.h>
int suan(int x,int r[])
{
    int i,t;
    for(i=1;i<=x;i++)
      for(t=i;t>0;t/=10)
        r[t%10]++;
}
int main()
{
    FILE *fr,*fw;
    int s,e,sums[20]={0},sume[20]={0},i;
    fr=fopen("ce.in","r");
    fw=fopen("ce.out","w");
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
