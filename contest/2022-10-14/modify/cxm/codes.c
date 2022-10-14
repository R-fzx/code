#include<stdio.h>
#include<string.h>
#define oo 32767
int d[27][27];
int s[27][27];
int n,m,i,j,k,flag;
FILE *fp,*fo;
int cmp(int k,int t)
{
 int j;
 for(j=0;j<=t;j++)
   if(s[i][j]!=s[k][j])
     return(0);
 return(1);
}
int main()
{
 fp=fopen("codes.in","r");
 fo=fopen("codes.out","w");
 /*InputModule*/
 fscanf(fp,"%ld\n",&n);    
 for(i=1;i<=n;i++)
   {
    fscanf(fp,"%s",&s[i]);
    fscanf(fp,"\n");
   }
 /*PreTreatmentModule*/
 for(i=1;i<=n;i++)
  for(k=1;k<=n;k++)
    if(cmp(k,strlen(k)-1));             
         d[i][strlen(k)-1]=strlen(k);
    else d[i][strlen(k)-1]=oo;
 /*MainModule*/
 for(i=1;i<=n;i++)
   {
    for(j=0;j<strlen(a[i]);j++)
                     
   }
}
