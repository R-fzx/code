#include<stdio.h>
#define in "dark.in"
#define out "dark.out"
FILE *fs,*fp;
int N;
int num[200010]={0};
double ans=2e12;
void kp(int,int);
int main()
{
    if((fs=fopen(in,"r"))==NULL) return 0;
    if((fp=fopen(out,"w"))==NULL) return 0;
     fscanf(fs,"%d",&N);
     int i,x,y;
     for(i=1;i<=N;i++)
     {
       fscanf(fs,"%d%d",&x,&y);
       num[i]=x+y;
     }
     kp(1,N);
     for(i=2;i<=N;i++)
     if((double)(num[i]-num[i-1])/2<ans)
      ans=(double)(num[i]-num[i-1])/2;
     fprintf(fp,"%.2lf\n",ans);
    fclose(fs);
    fclose(fp);
    return 0;
}
void kp(int q,int z)
{
     int x=q,y=z,t,pos=num[q];
     if(q>=z)
     return;
     else
     {
        while(x<y)
        {
           for(;x<y;y--)
           if(num[y]<num[x])
           {
             t=num[y];num[y]=num[x];num[x]=t;break;
           }
           for(;x<y;x++)
           if(num[y]<num[x])
           {
             t=num[y];num[y]=num[x];num[x]=t;break;
           }
        }
        if(x==y)
        {
           num[x]=pos;
           kp(q,x);
           kp(x+1,z);
        }
     }
}
