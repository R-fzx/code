#include<stdio.h>
FILE *fs,*fp;
int num[21],hash[21],ci=1;
void find(int,int,int);
int main()
{
    fs=fopen("wave.in","r");
    fp=fopen("wave.out","w");
    int m,n,c,i,j;
    fscanf(fs,"%d",&m);
    for(i=1;i<=m;i++,ci=1)
    {
       fscanf(fs,"%d%d",&n,&c);
       find(1,n,c);
    }
    fclose(fs);
    fclose(fp);
    return 0;
}
void find(int step,int n,int c)
{
     int i,j,k;
     if(ci>c)
        return;
     if(step>n)
     {
        for(i=1;i<n-1;i++)
           if(num[i]>=num[i+1]&&num[i+1]>=num[i+2]||num[i]<=num[i+1]&&num[i+1]<=num[i+2])
              return;
        if(ci==c)
        {
           for(i=1;i<n;i++)
              fprintf(fp,"%d ",num[i]);
           fprintf(fp,"%d\n",num[i]);
        }
        ci++;
        return;
     }
     for(i=1;i<=n;i++)
     {
        if(!hash[i])
        {
           num[step]=i;
           hash[i]=1;
           find(step+1,n,c);
           hash[i]=0;
        }
     }
}
