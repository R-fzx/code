#include <stdio.h>
#include <math.h>
      long p[200001]={0};
      long b[200001][80]={0};
      long ttt=0;
      long f1[200001]={0},f2[200001]={0};
main()
{
      FILE *fq,*fp;
      long j,i1,t[200001]={0},xx,yy,x,y,n,i,q=0;
      float min=1000000000.0,oo=0;
      fp=fopen("dark.in","r");
      fq=fopen("dark.out","w");
      fscanf(fp,"%ld",&n);
      if(n>5000)
      {
      for(i=1;i<=n;i++)
       {
       fscanf(fp,"%ld%ld",&x,&y);
       if(p[x]==0)
       {
       q++;
       p[x]=q;
       }
       x=p[x];
       t[x]++;
       if(t[x]>80) continue;
       for(j=t[x]-1;j>=1;j--)
       if(y>b[x][j]) {ttt=j; break;}
       for(j=t[x];j>ttt+1;j--)
        b[x][j]=b[x][j-1];
       b[x][j]=y;
       }
      for(i=1;i<=q;i++)
        for(i1=1;i1<t[i];i1++)
        if(b[i][i1+1]-b[i][i1]<min)
        min=b[i][i1+1]-b[i][i1];                       
      fprintf(fq,"%.2lf\n",min);
      }
      else
      {
       for(i=1;i<=n;i++)
       fscanf(fp,"%ld%ld",&f1[i],&f2[i]);    
       for(i=1;i<n;i++)
        for(i1=i+1;i1<=n;i1++)
        {
         xx=abs(f1[i]-f1[i1]);
         yy=abs(f2[i]-f2[i1]);
         oo=sqrt(xx*xx+yy*yy);
         if(oo<min) min=oo;           
        }
         fprintf(fq,"%.2lf",min);          
      }
      fclose(fq);
      fclose(fp);
      }
