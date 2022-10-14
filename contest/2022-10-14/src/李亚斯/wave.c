#include <stdio.h>
FILE *p,*q;
void opened();
void closed();
int halo(int);
int l[152]={0},hash[152]={0},c,n;
int main()
{
    int m;
    int i,j;
    opened();
    fscanf(p,"%d",&m);
    for(i=1;i<=m;i++)
    {
        fscanf(p,"%d%d",&n,&c);
        halo(1);
        fprintf(q,"%d",l[1]);
        for(j=2;j<=n;j++)
            fprintf(q," %d",l[j]);
        fprintf(q,"\n");
    }
    closed();
    return(0);
}
void opened()
{
    p=fopen("wave.in","r");
    q=fopen("wave.out","w");
}
void closed()
{
    fclose(p);
    fclose(q);
}
int halo(int k)
{
    int i;
    if(k<=n)
    {
        for(i=1;i<=n;i++)
            if(hash[i]==0 && (k<=2 || (l[k-1]>l[k-2] && l[k-1]>i) || (l[k-1]<l[k-2] && l[k-1]<i)))
            {
                hash[i]=1;
                l[k]=i;
                halo(k+1);
                hash[i]=0;
                if(c==0)
                    return(0);
            }
    }
    else
        c--;
}
