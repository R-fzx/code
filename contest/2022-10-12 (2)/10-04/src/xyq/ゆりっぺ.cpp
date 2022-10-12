#include<stdio.h>
#include<stdlib.h>

//qsort ∞¥a≈≈–Ú qsort2 ∞¥b≈≈–Ú qsort3 ∞¥c≈≈–Ú 

int c[500010][10],n,sum1,sum2,a,b,d,t[500010][10],max,max2;

void qsort(int l,int r)
{
     int i=l,j=r,p=c[(l+r)/2][1];
     while(i<j)
     {
               while(i<j && c[i][1]>p) i++;
               while(i<j && c[j][1]<p) j--;
               if(i<=j)
               {
                       int k=c[i][1];
                       c[i][1]=c[j][1];
                       c[j][1]=k;
                       k=c[i][2];
                       c[i][2]=c[j][2];
                       c[j][2]=k;
                       k=c[i][3];
                       c[i][3]=c[j][3];
                       c[j][3]=k;
                       i++;
                       j--;
               }
     }
     if(l<j) qsort(l,j);
     if(i<r) qsort(i,r);
     return;
}

void qsort2(int l,int r)
{
     int i=l,j=r,p=c[(l+r)/2][2];
     while(i<j)
     {
               while(i<j && c[i][2]>p) i++;
               while(i<j && c[j][2]<p) j--;
               if(i<=j)
               {
                       int k=c[i][1];
                       c[i][1]=c[j][1];
                       c[j][1]=k;
                       k=c[i][2];
                       c[i][2]=c[j][2];
                       c[j][2]=k;
                       k=c[i][3];
                       c[i][3]=c[j][3];
                       c[j][3]=k;
                       i++;
                       j--;
               }
     }
     if(l<j) qsort2(l,j);
     if(i<r) qsort2(i,r);
     return;
}

void qsort3(int l,int r)
{
     int i=l,j=r,p=c[(l+r)/2][3];
     while(i<j)
     {
               while(i<j && c[i][3]>p) i++;
               while(i<j && c[j][3]<p) j--;
               if(i<=j)
               {
                       int k=c[i][1];
                       c[i][1]=c[j][1];
                       c[j][1]=k;
                       k=c[i][2];
                       c[i][2]=c[j][2];
                       c[j][2]=k;
                       k=c[i][3];
                       c[i][3]=c[j][3];
                       c[j][3]=k;
                       i++;
                       j--;
               }
     }
     if(l<j) qsort3(l,j);
     if(i<r) qsort3(i,r);
     return;
}


void paixu1()
{
     qsort(1,n);
     for(int i=1;i<=a;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort2(a+1,n);
     for(int i=a+1;i<=b+a;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort3(b+a+1,n);
     for(int i=b+a+1;i<=b+a+d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}


void paixu2()
{
     qsort(1,n);
     for(int i=1;i<=a;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort3(a+1,n);
     for(int i=a+1;i<=a+d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort2(a+d+1,n);
     for(int i=a+d+1;i<=a+d+b;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}

void paixu3()
{
     qsort2(1,n);
     for(int i=1;i<=b;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort(b+1,n);
     for(int i=b+1;i<=a+b;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort3(a+b+1,n);
     for(int i=a+b+1;i<=a+b+d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}


void paixu4()
{
     qsort2(1,n);
     for(int i=1;i<=b;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort3(b+1,n);
     for(int i=b+1;i<=b+d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort(b+d+1,n);
     for(int i=b+d+1;i<=b+a+d;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}

void paixu5()
{
     qsort3(1,n);
     for(int i=1;i<=d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort2(d+1,n);
     for(int i=d+1;i<=b+d;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort(b+d+1,n);
     for(int i=b+d+1;i<=a+b+d;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}

void paixu6()
{
     qsort3(1,n);
     for(int i=1;i<=d;i++)
     {
             sum1+=c[i][3];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort(d+1,n);
     for(int i=d+1;i<=a+d;i++)
     {
             sum1+=c[i][1];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
     qsort2(a+d+1,n);
     for(int i=a+d+1;i<=b+a+d;i++)
     {
             sum1+=c[i][2];
             sum2+=c[i][1]+c[i][2]+c[i][3];
     }
}


int main()
{
    freopen("§Ê§Í§√§⁄.in","r",stdin);
    freopen("§Ê§Í§√§⁄.out","w",stdout);
    scanf("%d %d %d %d",&n,&a,&b,&d);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=3;j++)
     scanf("%d",&t[i][j]);
    if(a+b+d>n) 
    {
                printf("i am a godlike cowcowcow\n");
                return 0;
    }
    else
    {
                 for(int i=1;i<=n;i++)
                  for(int j=1;j<=3;j++)
                  c[i][j]=t[i][j];
                  sum1=0;
                  sum2=0;
                  paixu1();
                  if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
                 for(int i=1;i<=n;i++)
                  for(int j=1;j<=3;j++)
                  c[i][j]=t[i][j];
                  sum1=0;
                  sum2=0;
                  paixu2();
                  if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
                  for(int i=1;i<=n;i++)
                   for(int j=1;j<=3;j++)
                   c[i][j]=t[i][j];
                   sum1=0;
                  sum2=0;
                   paixu3();
                   if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
                    for(int i=1;i<=n;i++)
                   for(int j=1;j<=3;j++)
                   c[i][j]=t[i][j];
                   sum1=0;
                  sum2=0;
                   paixu4();
                   if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
                    for(int i=1;i<=n;i++)
                   for(int j=1;j<=3;j++)
                   c[i][j]=t[i][j];
                   sum1=0;
                  sum2=0;
                   paixu5();
                   if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
                    for(int i=1;i<=n;i++)
                   for(int j=1;j<=3;j++)
                   c[i][j]=t[i][j];
                   sum1=0;
                  sum2=0;
                   paixu6();
                   if(max<=sum1)
                  {
                               max=sum1;
                               if(max2<sum2) max2=sum2;
                  }
    }
    printf("%d\n%d\n",max,max2);
    return 0;
}
