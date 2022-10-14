#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *in,*out;
int a[100],pan[100]={0},n,count=0,m,go;
void fun(int step)
{
    if(go==0)return;
    int i;
    if(step==n)
    {
        count++;
        if(count==m)
        {
            for(i=0;i<step;i++)
                fprintf(out,"%d ",a[i]);
            fprintf(out,"\n");
            go=0;
        }
    }
    for(i=1;i<=n&&go;i++)
        if(pan[i]==0)
        {
            int f=1;
            if(step>=2)
            {
                if(a[step-1]>a[step-2]&&i>a[step-1])
                    f=0;
                if(a[step-1]<a[step-2]&&i<a[step-1])
                    f=0;
            }
            if(f&&go){
            a[step]=i;
            pan[i]=1;
            fun(step+1);
            pan[i]=0;
            a[step]=0;
            }
        }
}
int main()
{
     in=fopen("wave.in","r");
     out=fopen("wave.out","w");
     int i,j,k,tot;
     fscanf(in,"%d",&tot);
     for(i=0;i<tot;i++)
     {
         memset(pan,0,sizeof(pan));
         count=0;
         fscanf(in,"%d%d",&n,&m);
         go=1;
         fun(0);
     }
     return 0;
}
