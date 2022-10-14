#include<stdio.h>
#define MAXN 100000 + 5
long long cost[MAXN],m;
long long now,n,i,j,k;
FILE *fp,*fo;
int main()
{
 fp=fopen("bus.in","r");
 fo=fopen("bus.out","w");
 fscanf(fp,"%I64d",&n);
 for(i=1;i<=n;i++)fscanf(fp,"%I64d",&cost[i]);
 now=1;
 while(now<=n)
   {
    for(i=now+1;i<=n;i++)
      if(cost[i]<cost[now])
        break;
    m+=(i-now)*cost[now];
    now=i;
   }    
 fprintf(fo,"%I64d\n",m);
 fclose(fp);fclose(fo);
 return(0);
}
