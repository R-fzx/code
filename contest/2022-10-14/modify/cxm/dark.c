#include<stdio.h>
#include<math.h>
#define sq(a) (a)*(a)
FILE *fp,*fo;
struct node
{
 double x,y;
}a[200005],temp;
long n,m,i,j;
double k;
void qs(long l,long r)
{
 long b,i,j;
 if(l>=r)return;
 i=l;j=r;temp=a[(i+j)/2];
 a[(i+j)/2]=a[l];
 while(i<j)
   {
    while(temp.x<a[j].x && j>i)j--;
    if(i<j)
      {
       a[i]=a[j];
       i++;
      }
    while(temp.x>a[i].x && j>i)i++;
    if(i<j)
      {
       a[j]=a[i];
       j--;
      }
   }
 a[i]=temp;
 qs(l,i-1);
 qs(i+1,r);
 return;
}
int main()
{
 fp=fopen("dark.in","r");
 fo=fopen("dark.out","w");
 fscanf(fp,"%ld",&n);
 for(i=1;i<=n;i++)fscanf(fp,"%lf%lf",&a[i].x,&a[i].y);
 qs(1,n);
 k=2147483647;
 for(i=1;i<=n-1;i++)
   {
    for(j=i+1;j<=n;j++)
    {
      if(sq(k)>sq(a[i].x-a[j].x)+sq(a[i].y-a[j].y))
        k=sqrt(sq(a[i].x-a[j].x)+sq(a[i].y-a[j].y));
      if(k==0)goto loop;
      if(a[j].x-a[i].x>k)break;
    }
   }
 loop:;
 fprintf(fo,"%.2lf",k/2.0);
 fclose(fp);fclose(fo);
 return(0);
}
