#include <stdio.h>
FILE *fq,*fp;
int n,hash[100]={0},b[100]={0};
double f[50][50][3]={0},sum=0,c;
double tryo(int k,int l,int flag)
{
     int i,q=0;
     long o=0;
     if(k==n+1)
     {
     sum++;
     if(sum==c)          
     {
      for(i=1;i<=n;i++)
      {
      if(i<n)
      fprintf(fq,"%d ",b[i]);
      else
      fprintf(fq,"%d\n",b[i]);        
      }
     return -1;
     }
     else return 1;
     }
     if(f[k][l][flag]!=0)
      {
       if(sum+f[k][l][flag]<c) 
       {
       sum+=f[k][l][flag];
       return f[k][l][flag];                                
       }
      }
     if(flag==0)
      {
       for(i=1;i<=n;i++)
       if(hash[i]==0)
       {
        q++;
        hash[i]=1;
        b[k]=i;
        if(q<l)
        o=tryo(k+1,q,1);  
        else
        o=tryo(k+1,q,2);
        f[k][l][flag]+=o;
        hash[i]=0;   
        b[k]=0;         
        if(o==-1) return -1;
       }          
      }
     if(flag==1)
      {
      q=0;
       for(i=1;i<=n;i++)
       if(hash[i]==0)
       {
        q++;
        if(q<l)
        continue;
        else
        {
        hash[i]=1;
        b[k]=i;
        o=tryo(k+1,q,2);
        f[k][l][flag]+=o;
        hash[i]=0;   
        b[k]=0;       
        if(o==-1) return -1;    
        }
       }          
      }
     if(flag==2)
      {
      q=0;
       for(i=1;i<=n;i++)
       if(hash[i]==0)
       {
        q++;
        if(q<l)
        {
        b[k]=i;
        hash[i]=1;
        o=tryo(k+1,q,1);
        f[k][l][flag]+=o;
        hash[i]=0;    
        b[k]=0;
        if(o==-1) return -1;
        }
        else break;
       }          
      }
      return f[k][l][flag];
     }
main()
{
      int m,j,i1,i,i2;
      double l=0;
      fp=fopen("wave.in","r");
      fq=fopen("wave.out","w");
      fscanf(fp,"%d",&m);
      for(i=1;i<=m;i++)
      {
      fscanf(fp,"%d%lf",&n,&c);     
      sum=0;            
      for(j=1;j<=n;j++)
      {
      b[1]=j; hash[j]=1;
      l=tryo(2,j,0);
      b[1]=0; hash[j]=0;
      if(l==-1) break;
      }
      for(i1=1;i1<=n;i1++)
       for(i2=1;i2<=n;i2++)
        f[i1][i2][0]=f[i1][i2][1]=f[i1][i2][2]=0;
      }
      fclose(fq);
      fclose(fp);
      }
