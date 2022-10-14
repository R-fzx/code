#include <stdio.h>
#include <string.h>
#define MAX 50
#define oo 1048576
short f[2*MAX][oo]={0};
char s[MAX][MAX]={'\0'};
long len[MAX]={0},hash[MAX]={0};
long get_hash(long k)
{
     long i,j,sum=0;
     for(i=strlen(s[k])-1,j=1;i>=0;i--,j*=2)
        sum+=j*(s[k][i]-'0');
     return(sum);    
}
long exam(long i,long j,long l,long k)
{
     long num,t,a[MAX]={0},b[MAX]={0};
     num=1<<l;
     for(t=0;t<l;t++)
     {
         if(i>num)
         {
             a[t]=1;
             i-=num;                
         }
         if(j>num)
         {
             b[t]=1;
             j-=num;         
         }
     }   
     for(i=l-1;i>=l-k;i--)
       if(a[i]!=b[i])
         return(0);
     return(1);
}
main()
{
     long i,j,n,flag,min,l,num,k;
     FILE *fp,*fo;
     fp=fopen("codes.in","r");
     fo=fopen("codes.out","w");
     fscanf(fp,"%ld\n",&n);
     for(i=1;i<=n;i++)
       fscanf(fp,"%s\n",s[i]);
     for(i=1,min=oo;i<=n;i++)
     {
         hash[i]=get_hash(i);
         len[i]=strlen(s[i]);
         f[len[i]][hash[i]]=1;
         if(len[i]<min)
            min=len[i];
     }
     for(i=min+1,flag=0;i<=2*MAX;i++)
     {
         for(j=1;j<(1<<i);j++)
         {  
             for(k=1;k<=n;k++)
               if(i>len[k]&&j>=hash[k]&&exam(j,hash[k],i,len[k]))
                 if(f[i-len[k]][(j>>len[k])]==1)
                   f[i][j]++;
             if(f[i][j]>=2)
             {  
                flag=1;
                l=i;
                num=j;
                break;
             }
         }
         if(flag==1)
           break;
     }
     fprintf(fo,"%ld\n",l);
     for(j=(1<<l);l>0;l--,j/=2)
     {
         if(num>=j)
         {
             fprintf(fo,"1");
             num-=j;        
         }        
         else
            fprintf(fo,"0");      
     }
     fclose(fp);
     fclose(fo);
}
