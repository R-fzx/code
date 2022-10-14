#include<stdio.h>
long n,m;
long ans=0;
int hash[100]={0};
long a[1001]={0};
  FILE *fp,*fo;
long finds(long vi,long vp)
 {
  long i,j,k,l;
  if(vi==n+1)
   {
    ans++;
    if(ans==m)
     {
      for(i=1;i<=n;i++)
      {
       fprintf(fo,"%ld",a[i]);
       if(i!=n)
        fprintf(fo," ");
      }
      fprintf(fo,"\n");
      return(1);
     }
    return(0); 
   }
  else
   {k=0;
    for(i=1;i<=n;i++)
     if(hash[i]==0)
      if((vp==2&&i<a[vi-1])||(vp==-2&&i>a[vi-1]))
      {
       a[vi]=i;
       hash[i]=1;
       if(vp==2)
        k=finds(vi+1,-2);
       else
        k=finds(vi+1,2);
       a[vi]=0;
       hash[i]=0;  
       if(k==1)
        return(1);
      }
     return(0); 
   } 
 }
main()
 {
  long i,j,k,l,t;

  fp=fopen("wave.in","r");
  fo=fopen("wave.out","w");
  fscanf(fp,"%ld",&t);
  for(l=1;l<=t;l++)
  {
   fscanf(fp,"%ld%ld",&n,&m);
   ans=k=0;
   if(n==1)
    fprintf(fo,"1\n");
   else
    {
     for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
       if(i!=j)
       {k=0;
        a[1]=i;
        a[2]=j;
        hash[i]=hash[j]=1;
        if(i<j)
         {
          k=finds(3,2);
         }
        else
         k=finds(3,-2); 
         
        a[1]=a[2]=hash[i]=hash[j]=0;
        if(k==1)
         goto loop;
       }
      loop:; 
    } 
  }
  fclose(fp);
  fclose(fo);
 }
