/*
、黑暗的执政官
题目描述：
今年电竞社举行星际争霸的比赛，ZYF小同学也去参加。幸运的是，他第一轮碰到了一个宇宙
霹雳无敌超级大菜鸟。有某种恶趣味的ZYF小同学自然不会放弃虐待人的机会。
ZYF先在地图上各个角落布满黑暗圣堂（俗称隐刀），四处偷袭。打了一阵之后感觉不过瘾，
决定用黑暗圣堂合成黑暗的执政官，玩四百人口大战。
合成黑暗的执政官，需要用两个黑暗圣堂重叠。现在地图上有N个黑暗圣堂，处于地图上坐标
（Xi,Yi）。地图上没有障碍物，黑暗圣堂的移动速度是每秒一个单位。问从现在开始，再过
多少秒就可以出现黑暗的执政官。注：两个黑暗圣堂可同时移动。

输入：输入文件有N+1行。
第一行有一个数N。
第2到N+1行每行两个整数，表示第I个黑暗圣堂的坐标。

输出：输出文件只有一个实数（保留3位小数），为黑暗的执政官最早出现的时间。

样例：
输入：
4
0 0
0 1
1 0
0 0
输出：
           0．000



数据范围：
2《N《200000
0《Xi,Yi《1000000

*/
#include <stdio.h>
#include <math.h>
struct ww
{ long x,y;
}a[200001]={0},va;
long n;
void quick(long h,long e)
{ if (h<e)
  {
   long i=h,j=e;
   va=a[(h+e)/2]; a[(h+e)/2]=a[j]; a[j]=va;
   do
   {while(i<j && (a[i].x<va.x || (a[i].x==va.x && a[i].y<va.y))) i++;
    if (i<j)
      {a[j]=a[i]; j--;}
    while(i<j && (va.x<a[j].x || (va.x==a[j].x && va.y<a[j].y))) j--;
    if (i<j)
      {a[i]=a[j]; i++;}    
   }
   while(i<j);
   a[i]=va;
   quick(h,i-1);
   quick(i+1,e);
  }
}
int main()
{ FILE *fp,*fo;
  long i,j;
  double l,min=10000000;
  fp=fopen("dark.in","r");
  fo=fopen("dark.out","w");
    fscanf(fp,"%ld",&n);
    for(i=1;i<=n;i++)
      { fscanf(fp,"%ld %ld",&a[i].x,&a[i].y);
      }
    quick(1,n);
    for(i=2;i<=n;i++)
      if (a[i].x==a[i-1].x && a[i].y==a[i-1].y)
        {fprintf(fo,"0.00\n"); break;
        }
    if (i>n)
    {if (n<=5000)
       {for(i=1;i<n;i++)
          for(j=i+1;j<=n;j++)
            {l=sqrt(1.0*(a[i].x-a[j].x)*(a[i].x-a[j].x)+1.0*(a[i].y-a[j].y)*(a[i].y-a[j].y));
             if (l<min) min=l;
            }
       }
       else
       {for(i=1;i<=n-300;i++)
          for(j=i+1;j<=i+300;j++)
            {l=sqrt(1.0*(a[i].x-a[j].x)*(a[i].x-a[j].x)+1.0*(a[i].y-a[j].y)*(a[i].y-a[j].y));
             if (l<min) min=l;
            }
       }
    fprintf(fo,"%.2lf\n",min/2.0);
    }
  fclose(fp);
  fclose(fo);
    return(0);
}
