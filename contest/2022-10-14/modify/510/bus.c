#include <stdio.h>
#define in "bus.in"
#define out "bus.out"
#define MaxN 120000
FILE *fp,*fq;
long q[MaxN]={0},t[MaxN]={0};

int opens()
{
    if((fp=fopen(in,"r"))==NULL)
     return 0;
    if((fq=fopen(out,"w"))==NULL)
     return 0;
    return 1;
}

void close()
{
     fclose(fp);
     fclose(fq);
}

double solve(long n)
{
       double ans=0;
       long i,f=0,r=-1;
       
       for(i=n-1;i>=0;i--)
        {
        while(f<=r && t[q[r]]>=t[i]) r--;
        q[++r]=i;
        }
       while(f<=r)
        {
        ans+=(double)(n-q[f])*(double)t[q[f]];
        n=q[f++];
        }
       return ans;
}

int main()
{
    long n,i;
    
    if(opens()==0)
     return 0;
    fscanf(fp,"%ld",&n);
    for(i=0;i<n;i++)
     fscanf(fp,"%ld",t+i);
    fprintf(fq,"%.0lf",solve(n));
    close();
    return 0;
}
