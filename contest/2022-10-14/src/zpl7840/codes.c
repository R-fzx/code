#include <stdio.h>
#include <string.h>

char str[25][25]={'\0'},s1[55]={'\0'},s2[55]={'\0'},s3[55]={'\0'};
char s4[2005]={'\0'};
long n,min=2000000000,len;

long check()
{
 long j,i,f[2005]={0};
 
 f[len+1]=1;
 
 for(i=len;i>=1;i--)
   for(j=1;j<=n;j++)
     {
      strcpy(s1,s4+i-1);
      s1[strlen(str[j])]='\0';
      if(strcmp(s1,str[j])==0)
       f[i]+=f[i+strlen(str[j])];
     }
 if(f[1]>=2)
  return 1;
 else
  return 0;
}

long dfs(long l)
{
 long i,q;
 
 if(l+min<=len)
  {
   for(i=1;i<=n;i++)
     {
      q=strlen(str[i]);
      if(l+q<=len)
       {
        strcat(s4,str[i]);
        if(dfs(l+q))
         return 1;
        s4[l]='\0';
       }
     }
  }
 else if(l==len)
  {
   if(check())
    return 1;
  }
 
 return 0;
}

int main()
{
 FILE *fp,*fo;
 
 long i,j;
 
 fp=fopen("codes.in","r");
 fo=fopen("codes.out","w");
 
 fscanf(fp,"%ld",&n);
 
 for(i=1;i<=n;i++)
   {
    fscanf(fp,"%s",str[i]);
    if(strlen(str[i])<min)
     min=strlen(str[i]);
   }
 
 for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
     {
      strcpy(s1,str[i]);
      strcat(s1,str[j]);
      strcpy(s2,str[j]);
      strcat(s2,str[i]);
      if(strcmp(s2,s1)<0)
       {
        strcpy(s3,str[i]);
        strcpy(str[i],str[j]);
        strcpy(str[j],s3);
       }
     }
 
 for(i=min;;i++)
   {
    len=i;
    if(dfs(0))
     {
      fprintf(fo,"%ld\n",i);
      fprintf(fo,"%s",s4);
      fprintf(fo,"\n");
      goto loop;
     }
   }
 
 loop:
 fclose(fp);
 fclose(fo);
 return 0;
} 
