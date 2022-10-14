#include<stdio.h>
char ch[1000][200]={0};
long f[1001][1001]={0};
long len[1001]={0};
long a[100][200]={0};
char p[21][21][1001]={0};
long word(long *c1,long s1,long *c2,long s2,long vn)
 {
  long i,j,k,l,m;
  for(i=0;i<vn;i++)
   if(c1[s1+i]!=c2[s2+i])
    return(0);
  return(1);   
 } 
main()
 {
  FILE *fp,*fo;
  long i,j,k,l,m,n,ans=100000000,o,q;
  char w[10001]={0};
  fp=fopen("codes.in","r");
  fo=fopen("codes.out","w");
  fscanf(fp,"%ld",&n);
  for(i=1;i<=n;i++)
  {
   fscanf(fp,"%s",ch[i]);
   len[i]=strlen(ch[i]);
   for(l=1;l<=len[i];l++)
    a[i][l]=ch[i][l-1]-'0';
  }
  for(i=1;i<=n;i++)
   for(j=0;j<=500;j++)
   {
    f[i][j]=1000000000;
   
   }
  for(k=1;k<=n;k++)
   for(i=1;i<=n;i++)
    if(i!=k)
     {
      m=word(a[k],1,a[i],1,len[k]);
      if(m==1)
       {
        f[i][len[k]]=len[k];
        strcpy(p[i][len[k]],"");
        strcpy(p[i][len[k]]/*+strlen(p[i][len[k]])*/,ch[k]);
       }
     }
  for(l=1;l<=n;l++)
   for(i=1;i<=n;i++)
    for(j=0;j<=len[i];j++)
     for(k=1;k<=n;k++)
     // if(i!=k)
      {
       if(word(a[k],1,a[i],j+1,len[k]))
        {
        if(f[i][j+len[k]]!=f[i][j]+len[k])
          {
           if(f[i][j+len[k]]>f[i][j]+len[k])
           {
            f[i][j+len[k]]=f[i][j]+len[k];
            strcpy(p[i][j+len[k]],"");
            strcpy(p[i][j+len[k]],p[i][j]);
            strcpy(p[i][j+len[k]]+strlen(p[i][j+len[k]]),ch[k]);
           }
          }
         else
          {
           strcpy(w,"");
           strcpy(w,p[i][j]);
           strcpy(w+strlen(w),ch[k]);
           o=strcmp(w,p[i][j+len[k]]);
           if(o<=0)
            {
             strcpy(p[i][j+len[k]],"");
            strcpy(p[i][j+len[k]],p[i][j]);
            strcpy(p[i][j+len[k]]+strlen(p[i][j+len[k]]),ch[k]);
            }
          }  
        }
       if(word(a[k],1,a[i],j+1,len[i]-j))
        {
         if(f[k][len[i]-j]!=f[i][j]+len[i]-j)
          {
           if(f[i][j]+len[i]-j<f[k][len[i]-j])
            {
             f[k][len[i]-j]=f[i][j]+len[i]-j;
             strcpy(p[k][len[i]-j],"");
             strcpy(p[k][len[i]-j],p[i][j]);
             strcpy(p[k][len[i]-j]+strlen(p[k][len[i]-j]),ch[i]+j);
            }
          }
         else
          {
           strcpy(w,"");
           strcpy(w,p[i][j]);
           strcpy(w+strlen(w),ch[i]+j);
           o=strcmp(w,p[k][len[i]-j]);
           if(o<=0)
            {
             strcpy(p[k][len[i]-j],"");
             strcpy(p[k][len[i]-j],p[i][j]);
             strcpy(p[k][len[i]-j]+strlen(p[k][len[i]-j]),ch[i]+j);
            }
          } 
        }
      }                                      
  for(i=1;i<=n;i++)
   if(ans>f[i][len[i]])
    {m=i;
     ans=f[i][len[i]];                   
    }
   else
    if(ans==f[i][len[i]])
     {
      o=strcmp(p[m][len[m]],p[i][len[i]]);
      if(o>0)
       m=i;
     } 
                       
  fprintf(fo,"%ld\n",ans); 
 /* for(i=0;i<ans;i++)                                                                                                                       
  fprintf(fo,"%c",p[m][len[m]][i]);
 */
 fprintf(fo,"%s",p[m][len[m]]);
  fclose(fp);
  fclose(fo);
 }
 
 
 
