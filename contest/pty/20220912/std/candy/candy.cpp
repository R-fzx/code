#include<stdio.h>
long long ans[100000],sindx[100000];
double qu[100000];
void qs(long long,long long);//big to small
int main()
{
      long long i,t,bk,n,m,y,x,c;
      FILE *fi,*fo;
      fi=fopen("candy.in","r");
      fo=fopen("candy.out","w");
      fscanf(fi,"%I64d",&t);
      for(bk=0;bk<t;++bk)
      {
        fscanf(fi,"%I64d%I64d%I64d",&n,&m,&y);
        for(i=0,c=0;i<n;++i)
        {
          fscanf(fi,"%I64d",&x);
          qu[i]=(double)(m*x)/(double)y;
          ans[i]=m*x/y;
          c+=ans[i];
          qu[i]-=ans[i];
          sindx[i]=i;
        }
        qs(0,n-1);
        for(i=0;i<m-c;++i)
          ans[sindx[i]]++;
        fprintf(fo,"%I64d",ans[0]);
        for(i=1;i<n;++i)
          fprintf(fo," %I64d",ans[i]);
        fprintf(fo,"\n");
      }
      fclose(fi);
      fclose(fo);
      return 0;
}
void qs(long long a,long long b)
{
     long long i,j,vs;
     double vq;
     if(a<b)
     {
       i=a;
       j=b;
       vq=qu[a];
       vs=sindx[a];
       while(i<j)
       {
         while(i<j&&qu[j]<=vq) --j;
         if(i<j)
         {
           qu[i]=qu[j];
           sindx[i]=sindx[j];
           while(i<j&&qu[i]>=vq) ++i;
           if(i<j)
           {
             qu[j]=qu[i];
             sindx[j]=sindx[i];
           }
         }
       }
       qu[j]=vq;
       sindx[j]=vs;
       qs(a,j-1);
       qs(j+1,b);
     }
} 
