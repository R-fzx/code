#include<stdio.h>
#include<math.h>
struct st
 {
  double x;
  double y;
 }a[200001]={0,0};
 void quick_2(long l,long r)
  {
   long i,j,m,n;
   struct st k;
   i=l;
   j=r;
   if(i<j)
    {
     m=(i+j)/2;
     k=a[i];
     a[i]=a[m];
     a[m]=k;
     k=a[i];
     while(i<j)
      {
       while(i<j&&((k.y<a[j].y)||(k.y==a[j].y&&k.x<a[j].x)))j--;
       if(i<j)
        {
        a[i]=a[j];
        i++;
        }
       while(i<j&&((k.y>a[i].y)||(k.y==a[i].y&&k.x>a[i].x)))i++;
       if(i<j)
        {
         a[j]=a[i];
         j--;
        } 
      }
     a[i]=k;
     quick_2(l,i-1);
     quick_2(i+1,r); 
    } 
  } 
 void quick_1(long l,long r)
  {
   long i,j,m,n;
   struct st k;
   i=l;
   j=r;
   if(i<j)
    {
     m=(i+j)/2;
     k=a[i];
     a[i]=a[m];
     a[m]=k;
     k=a[i];
     while(i<j)
      {
       while(i<j&&((k.x<a[j].x)||(k.x==a[j].x&&k.y<a[j].y)))j--;
       if(i<j)
        {
        a[i]=a[j];
        i++;
        }
       while(i<j&&((k.x>a[i].x)||(k.x==a[i].x&&k.y>a[i].y)))i++;
       if(i<j)
        {
         a[j]=a[i];
         j--;
        } 
      }
     a[i]=k;
     quick_1(l,i-1);
     quick_1(i+1,r); 
    } 
  }
double dis(long vi,long vj)
 {
  return(sqrt((a[vi].x-a[vj].x)*(a[vi].x-a[vj].x)+(a[vi].y-a[vj].y)*(a[vi].y-a[vj].y)));
 } 
main()
 {
  FILE *fp,*fo;
  struct st vi,vj;
  long i,j,l,m,n;
  double k,ans=1000000000,ls;
  fp=fopen("dark.in","r");
  fo=fopen("dark.out","w");
  fscanf(fp,"%ld",&n);
  for(i=1;i<=n;i++)
   fscanf(fp,"%lf%lf",&a[i].x,&a[i].y);
  if(n<=2000)
   {
     for(i=1;i<=n;i++)
   for(j=i+1;j<=n;j++)
    {
     ls=dis(i,j);
     if(ls<ans)
     {
      ans=ls;
      vi=a[i];
     vj=a[j];
     }
    }
   } 
  else
  { 
  quick_1(1,n);
  for(i=1;i<n;i++)
   if((k=dis(i,i+1))<ans)
    {vi=a[i];
    vj=a[i+1];
    ans=k;
   }
  quick_2(1,n);
  for(i=1;i<n;i++)
   if((k=dis(i,i+1))<ans)
   {vi=a[i];
    vj=a[i+1];
    ans=k;
   }
  }
  // fprintf(fo,"%.2lf   %.2lf\n%.2lf   %.2lf\n",vi.x,vi.y,vj.x,vj.y);
  fprintf(fo,"%.2lf\n",ans/2);     
  fclose(fp);
  fclose(fo);
 }
