#include <stdio.h>
#define MAX 25
long n,c,hash[MAX],a[MAX]={0},p,flag=0;
FILE *fp,*fo;
void find(long k)
{
     long i;
     if(k==n+1)
     {
         p++;
         if(p==c)
         {
             for(i=1;i<n;i++)
               fprintf(fo,"%ld ",a[i]);
             fprintf(fo,"%ld\n",a[n]);
             flag=1;    
         }                
     }
     else if(flag==0&&k<=n)
     for(i=1;i<=n;i++)
       if(hash[i]==0)
       {
           if(k==1)
           {
                a[k]=i;
                hash[i]=1;
                find(k+1);
                hash[i]=0;       
           }
           else if(k==2)
           {
                if(a[k-1]>a[k-2]&&a[k-1]>i) 
                {
                    a[k]=i;
                    hash[i]=1;
                    find(k+1);
                    hash[i]=0;
                }
                else if(a[k-1]<a[k-2]&&a[k-1]<i)
                {
                    a[k]=i;
                    hash[i]=1;
                    find(k+1);
                    hash[i]=0;     
                }     
           }
           else if(a[k-1]>a[k-2]&&i<a[k-1])
           {
                a[k]=i;
                hash[i]=1;
                find(k+1);
                hash[i]=0;                           
           }        
           else if(a[k-1]<a[k-2]&&i>a[k-1])
           {
                a[k]=i;
                hash[i]=1;
                find(k+1);
                hash[i]=0;                           
           }     
       }     
}
main()
{
     long m,i;
     fp=fopen("wave.in","r");
     fo=fopen("wave.out","w");
     fscanf(fp,"%ld",&m);
     for(;m>0;m--)
     {
          fscanf(fp,"%ld%ld",&n,&c);
          memset(hash,0,sizeof(hash));
          p=0;
          flag=0;
          find(1);
     } 
     fclose(fp);
     fclose(fo);    
}
