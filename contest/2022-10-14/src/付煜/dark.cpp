#include<stdio.h>
#define in "dark.in"
#define out "dark.out"
FILE *fs,*fp;
int N,X[200010]={0},Y[200010]={0};
int num1[200010]={0},W[200010]={0};
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
       X[i]=x;Y[i]=y;
       W[i]=i;
       num1[i]=x+y;
     }
     kp(1,N);
     for(i=2;i<=N;i++)
     if(X[W[i]]-X[W[i-1]]>=0&&Y[W[i]]-Y[W[i-1]]>=0||X[W[i]]-X[W[i-1]]<=0&&Y[W[i]]-Y[W[i-1]]<=0)
     if((double)(num1[i]-num1[i-1])/2<ans)
      ans=(double)(num1[i]-num1[i-1])/2;
     for(i=1;i<=N;i++)
     {
        W[i]=i;
        num1[i]=X[i]-Y[i];
     }
     kp(1,N);
     for(i=2;i<=N;i++)
     if(X[W[i]]-X[W[i-1]]<=0&&Y[W[i]]-Y[W[i-1]]>=0||X[W[i]]-X[W[i-1]]>=0&&Y[W[i]]-Y[W[i-1]]<=0)
     if((double)(num1[i]-num1[i-1])/2<ans)
      ans=(double)(num1[i]-num1[i-1])/2;
     fprintf(fp,"%.2lf\n",ans);
    fclose(fs);
    fclose(fp);
    return 0;
}
void kp(int q,int z)
{
     int x=q,y=z,t,pos=num1[q],p2=W[q];
     if(q>=z)
     return;
     else
     {
        while(x<y)
        {
           for(;x<y;y--)
           if(num1[y]<num1[x])
           {
             t=W[x];W[x]=W[y];W[y]=t;
             t=num1[y];num1[y]=num1[x];num1[x]=t;break;
           }
           for(;x<y;x++)
           if(num1[y]<num1[x])
           {
             t=W[x];W[x]=W[y];W[y]=t;
             t=num1[y];num1[y]=num1[x];num1[x]=t;break;
           }
        }
        if(x==y)
        {
           num1[x]=pos;
           W[x]=p2;
           kp(q,x);
           kp(x+1,z);
        }
     }
}
