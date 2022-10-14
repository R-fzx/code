#include <stdio.h>
int n,i,j,k,l,x[200001]={0},y[200001]={0};
long long ans=-1;
void qsort(int l,int r)
{int i,j,x1,y1;
 i=l;j=r;
 x1=x[(l+r)/2];
 do
 {while(x[i]<x1)i++;
  while(x[j]>x1)j--;
  if(i<=j)
  {y1=x[i];x[i]=x[j];x[j]=y1;
   y1=y[i];y[i]=y[j];y[j]=y1;
   i++;j--;
  }
 }while(i<=j);
 if(i<r)qsort(i,r);
 if(l<j)qsort(l,j);
}  
void qsort1(int l,int r)
{int i,j,x1,y1;
 i=l;j=r;
 x1=y[(l+r)/2];
 do
 {while(y[i]<x1)i++;
  while(y[j]>x1)j--;
  if(i<=j)
  {y1=x[i];x[i]=x[j];x[j]=y1;
   y1=y[i];y[i]=y[j];y[j]=y1;
   i++;j--;
  }
 }while(i<=j);
 if(i<r)qsort(i,r);
 if(l<j)qsort(l,j);
}  
main()
{FILE *fp,*fo;
 fp=fopen("dark.in","r");
 fo=fopen("dark1.out","w");
 fscanf(fp,"%d",&n);
 for(i=1;i<=n;i++)fscanf(fp,"%d%d",&x[i],&y[i]);
 if(n<5000)
 {for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     if(i!=j)
     {long long t;
      t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if(t<ans||ans==-1)ans=t;
     }
  fprintf(fo,"%.2lf",sqrt(ans));
 }
 else
 {qsort(1,n);
  for(i=1;i<n;i++)
  {long long t;
   t=(x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]);
   if(t<ans||ans==-1)ans=t;
  }
  qsort1(1,n);   
  for(i=1;i<n;i++)
  {long long t;
   t=(x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]);
   if(t<ans||ans==-1)ans=t;
  }
  fprintf(fo,"%.2lf",sqrt(ans));
 }
 fclose(fp);
 fclose(fo);
} 
