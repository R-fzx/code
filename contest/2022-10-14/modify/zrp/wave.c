#include<stdio.h>
long long f[500][500][2]={0};
long hash[501]={0};
long long n;
long long get_zrp(long long vi)
 {
  long long i,j,k,l;
  j=0;
  for(i=1;i<=n;i++)
   {
    if(hash[i]==0)
     j++;
    if(j==vi)
     return(i);
   }
 }
main()
 {
  FILE *fp,*fo;
  long long o,p,u,i,j,k,l,m,c,f1,f2;
  fp=fopen("wave.in","r");
  fo=fopen("wave.out","w");
  fscanf(fp,"%I64d",&u);
  f[1][1][0]=1;f[1][1][1]=1;
  for(i=2;i<=20;i++)
   for(j=1;j<=i;j++)
    {
      for(k=1;k<=j-1;k++)
       f[i][j][1]=f[i][j][1]+f[i-1][k][0];
      for(k=j;k<=i;k++)
       f[i][j][0]=f[i][j][0]+f[i-1][k][1];
    }
  for(o=1;o<=u;o++)
   {
    fscanf(fp,"%I64d%I64d",&n,&m);
    memset(hash,0,sizeof(hash));
    f1=f2=-1;
    for(i=n;i>=1;i--)
     {
      for(j=1;j<=i;j++)
       {
        if(f1!=1&&(f2==-1||j>=f2))
         {
          if(f[i][j][1]<m)
           m-=f[i][j][1];
          else
           {
            f2=get_zrp(j);
            hash[f2]=1;
            if(f1!=-1)
             fprintf(fo," ");
            fprintf(fo,"%I64d",f2);
            f1=1;              
            f2=j;
            break;
           } 
         }
      
        if(f1!=0&&(f2==-1||j<f2))
         {
          if(f[i][j][0]<m)
           m-=f[i][j][0];
          else
           {
            f2=get_zrp(j);
            hash[f2]=1;
            if(f1!=-1)
             fprintf(fo," ");
            fprintf(fo,"%I64d",f2);
            f1=0;
            f2=j;  
            break;
           } 
         }
          
       }
     }
     fprintf(fo,"\n");
   }
  fclose(fp);
  fclose(fo);
 }
