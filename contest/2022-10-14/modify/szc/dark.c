#include <stdio.h>
long long n,i,j,k,l,x[200001]={0},y[200001]={0},hash[200001][2]={0};
long long ans=-1;
void qsort(long long l,long long r)
{long long i,j,x1,y1;
 i=l;j=r;
 x1=x[(l+r)/2];
 do
 {while(x[i]<x1&&i<r)i++;
  while(x[j]>x1&&l<j)j--;
  if(i<=j)
  {y1=x[i];x[i]=x[j];x[j]=y1;
   y1=y[i];y[i]=y[j];y[j]=y1;
   i++;j--;
  }
 }while(i<=j);
 if(i<r)qsort(i,r);
 if(l<j)qsort(l,j);
}
void qsort1(long long l,long long r)
{long long i,j,x1,y1;
 i=l;j=r;
 x1=y[(l+r)/2];
 do
 {while(y[i]<x1&&i<r)i++;
  while(y[j]>x1&&l<j)j--;
  if(i<=j)
  {y1=x[i];x[i]=x[j];x[j]=y1;
   y1=y[i];y[i]=y[j];y[j]=y1;
   i++;j--;
  }
 }while(i<=j);
 if(i<r)qsort(i,r);
 if(l<j)qsort(l,j);
}
long long fz(long long l,long long r)
{long long i,j,k,jg,mid,tot=0;
 if(l==r)return(10000000000000);
 if(r-l==1)return((x[l]-x[r])*(x[l]-x[r])+(y[l]-y[r])*(y[l]-y[r]));
 if(r-l<=50)
 {jg=1000000000;
  for(i=l;i<r;i++)
    for(j=i+1;j<=r;j++)
    {long long t1=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
     if(jg>t1)jg=t1;
    } 
  return(jg);
 }
 mid=(l+r)>>1;
 jg=fz(l,mid);
 k=fz(mid+1,r);
 if(k<jg)jg=k;
 for(i=l;i<=r;i++)
   if(abs(x[i]-(x[mid]+x[mid+1])/2)<jg&&tot<20)
   {hash[++tot][0]=x[i];hash[tot][1]=y[i];}
 /*if(tot>1)qsort1(1,tot);*/
 for(i=1;i<tot;i++)
   for(j=i+1;j<=i+7;j++)
     {if(j>tot)break;
      long long t=(hash[i][0]-hash[j][0])*(hash[i][0]-hash[j][0])+(hash[i][1]-hash[j][1])*(hash[i][1]-hash[j][1]);
      if(t<jg)jg=t;
     } 
 return(jg);
}    
main()
{FILE *fp,*fo;
 fp=fopen("dark.in","r");
 fo=fopen("dark.out","w");
 fscanf(fp,"%I64d",&n);
 for(i=1;i<=n;i++)fscanf(fp,"%I64d%I64d",&x[i],&y[i]);
 if(n<8000)
 {for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     if(i!=j)
     {long long t;
      t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if(t<ans||ans==-1)ans=t;
     }
  fprintf(fo,"%.2lf",sqrt(ans)/2);
 }
 else
 {qsort(1,n);
  qsort1(1,n);
  ans=fz(1,n);
  fprintf(fo,"%.2lf",sqrt(ans)/2.0);
 }
 fclose(fp);
 fclose(fo);
}
