#include <stdio.h>
#include <string.h>
#define oo 400
struct codes
{
       char str[25];
       int len;
}a[25]={"\0",0};
char hash[40971521]={0};
char r[20][200]={"\0"},c[200]="\0";
int l=0,minlen=oo,n;

int suan(char *s)
{
    int i,h,len;
    len=strlen(s);
    h=1;
    for(i=0;i<len;i++)
    {
        h<<=1;
        h|=(s[i]-'0');
    }
    return h;
}
int dfs(char *s)
{
     int j,k,lenth,h;
     lenth=strlen(s);
     
     if(strlen(c)<=minlen)
       for(j=0;j<n;j++)
       {
          if(a[j].len>lenth)
          {
             for(k=0;k<lenth;k++)
               if(a[j].str[k]!=s[k])
                  break;
             if(k==lenth)
             {
               strcat(s,a[j].str+k);
               h=suan(s+k);
               if(hash[h]!=1)
               {
                 hash[h]=1;
                 dfs(s+k);
                 hash[h]=0;
               }
               s[lenth]='\0';
             }
          }
          else if(a[j].len<lenth)
          {
             for(k=0;k<a[j].len;k++)
               if(a[j].str[k]!=s[k])
                  break;
             if(k==a[j].len)
             {
               h=suan(s+k);
               if(hash[h]!=1)
               {
                 hash[h]=1;
                 dfs(s+k);
                 hash[h]=0;
               }
               s[lenth]='\0';
             }
          }
          else if(!strcmp(a[j].str,s) && a[j].len!=strlen(c))
          {
              if(strlen(c)==minlen) 
                 strcpy(r[l++],c);
              else if(strlen(c)<minlen)
              {
                 l=1;
                 minlen=strlen(c);
                 strcpy(r[0],c);
              }
          }
       }
       *(s+lenth)='\0';
       return 0;
}
int main()
{
    FILE *fr,*fw;
    int i,j,min,h;
    struct codes t;
    fr=fopen("codes.in","r");
    fw=fopen("codes.out","w");
    fscanf(fr,"%d\n",&n);
    for(i=0;i<n;i++)
    {
      fscanf(fr,"%s\n",a[i].str);
      a[i].len=strlen(a[i].str);
    }
    for(i=0;i<n;i++)
    {
       strcpy(c,a[i].str);
       h=suan(c);
       if(hash[h]==0)
       {
         hash[h]=1;
         dfs(c);
         hash[h]=0;
       }
    }
    min=0;
    for(i=1;i<l;i++)
      if(strcmp(r[min],r[i])>0)
        min=i;
    fprintf(fw,"%d\n%s\n",strlen(r[min]),r[min]);
    fclose(fr);
    fclose(fw);
    return 0;
}
