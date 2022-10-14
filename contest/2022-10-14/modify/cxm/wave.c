#include<stdio.h>
int hash[21],a[21];
long n,m,i,j,k,c;
FILE *fp,*fo;
void go(int i)
{
 int j;
 if(i>n)
   {
    k++;
    if(k==c)return;
    return;     
   }
 if(i==2)
 { 
  for(j=1;j<=n;j++)
    if(!hash[j])
      {
       hash[j]=1;
       a[i]=j;
       go(i+1);
       hash[j]=0;
       if(c==k)return;
       a[i]=0;
      }
 }else
 {
  if(a[i-1]>a[i-2])
    for(j=1;j<=a[i-1];j++)
      if(!hash[j])
      {
       hash[j]=1;
       a[i]=j;
       go(i+1);
       hash[j]=0;
       if(c==k)return;
       a[i]=0;
      }
  if(a[i-1]<a[i-2])
    for(j=a[i-1]+1;j<=n;j++)
      if(!hash[j])
      {
       hash[j]=1;
       a[i]=j;
       go(i+1);
       hash[j]=0;
       if(c==k)return;
       a[i]=0;             
      }     
 }
 return;
}
int main()
{
 fp=fopen("wave.in","r");
 fo=fopen("wave.out","w");
 fscanf(fp,"%ld",&m);
 for(;m>0;m--)
 {
  fscanf(fp,"%ld%ld",&n,&c);
  k=0;
  for(a[1]=1;a[1]<=n;a[1]++)
  {
   hash[a[1]]=1;
   go(2);
   hash[a[1]]=0;
   if(c==k)break;
  }
  fprintf(fo,"%ld",a[1]);
  for(i=2;i<=n;i++)fprintf(fo," %ld",a[i]);
  fprintf(fo,"\n");
  for(i=1;i<=n;i++)a[i]=0;
 }
 fclose(fp);fclose(fo);
}
