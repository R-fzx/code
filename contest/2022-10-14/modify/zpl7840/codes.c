#include <stdio.h>
#include <string.h>

char str[25][25]={'\0'},s1[55]={'\0'},s2[55]={'\0'},s3[55]={'\0'};
char s4[2005]={'\0'},ans[2005]={'\0'},now[2005]={'\0'};
long n,min=2000000000;
char hash[25][2000005]={'\0'};

long hashvalue(char s[25])
{
 long i,l,hv=0;
 l=strlen(s);
 
 for(i=0;i<l;i++)
   hv=hv*2+s[i]-'0';
   
 return hv*100+l;
}

void dfs(long l,char s[25],long flag)
{
 long i,hv,ll;
 char s2[25]={'\0'};
 
 if(l>min)
  return;
 
 hv=hashvalue(s);
 

 
 strcpy(s2,s);
 
 for(i=1;i<=n;i++)
   {
    if(i==flag)
     continue;
    if(strcmp(s2,str[i])==0)
     {
      if(l<min)
       strcpy(ans,now);
      else if(strcmp(now,ans)<0)
       strcpy(ans,now);
      min=l;
      return;
     }
    if(strstr(s2,str[i])==s2&&!hash[hv%100][hv/100])
     {
      if(!flag)
       hash[hv%100][hv/100]=1;
      dfs(l,s2+strlen(str[i]),0);
      if(!flag)
       hash[hv%100][hv/100]=0;
     }
    if(strstr(str[i],s2)==str[i]&&!hash[hv%100][hv/100])
     {
      if(!flag)
       hash[hv%100][hv/100]=1;
      ll=strlen(now);
      strcat(now,str[i]+strlen(s2));
      dfs(l+strlen(str[i])-strlen(s2),str[i]+strlen(s2),0);
      now[ll]='\0';
      if(!flag)
       hash[hv%100][hv/100]=0;
     }
   }

}

int main()
{
 FILE *fp,*fo;
 
 long i,j;
 
 fp=fopen("codes.in","r");
 fo=fopen("codes.out","w");
 
 fscanf(fp,"%ld",&n);
 
 for(i=1;i<=n;i++)
   fscanf(fp,"%s",str[i]);
 
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
 
 for(i=1;i<=n;i++)
   {
    strcpy(s4,str[i]);
    strcat(now,str[i]);
    dfs(strlen(str[i]),s4,i);
    now[0]='\0';
   }
 
 fprintf(fo,"%ld\n",min);
 fprintf(fo,"%s",ans);
 
 fclose(fp);
 fclose(fo);
 return 0;
} 
