#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *in,*out;
int n;
char a[21][21]={0};
int hash[2100000]={0},maxlen;
char ch[10000]={0};
void fun(int p)
{
     int i,j=1;
     for(i=0;i<p;i++)
     {
         j*=2;
         j+=ch[i]-'0';
     }
     hash[j]++;
     if(hash[j]==2)
     {
         fprintf(out,"%d\n%s\n",p,ch);
         exit(0);
     }
     for(i=0;i<n;i++)
     {
         strcpy(&ch[p],a[i]);
         int len=strlen(ch);
         if(len<maxlen)
             fun(len);
     }
}
int main()
{
     in=fopen("codes.in","r");
     out=fopen("codes.out","w");
     int i,j,k;
     fscanf(in,"%d",&n);
     for(i=0;i<n;i++)
         fscanf(in," %s",&a[i]);
     for(i=0;i<n;i++)
         maxlen+=strlen(a[i]);
     for(i=0;i<n;i++)
         for(j=0;j<i;j++)
             if(strcmp(a[j],a[i])>0)
             {
                 char temp[21];
                 strcpy(temp,a[i]);
                 strcpy(a[i],a[j]);
                 strcpy(a[j],temp);
             }
     for(maxlen=1;maxlen<1000;maxlen++)
     {
         memset(hash,0,sizeof(hash));
         fun(0);
     }
     return 0;
}
