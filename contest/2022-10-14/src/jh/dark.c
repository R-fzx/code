/*
3、黑暗的执政官
题目描述：
今年电竞社举行星际争霸的比赛，ZYF小同学也去参加。
幸运的是，他第一轮碰到了一个宇宙霹雳无敌超级大菜鸟。
有某种恶趣味的ZYF小同学自然不会放弃虐待人的机会。
ZYF先在地图上各个角落布满黑暗圣堂（俗称隐刀），四处偷袭。
打了一阵之后感觉不过瘾，决定用黑暗圣堂合成黑暗的执政官，玩四百人口大战。
合成黑暗的执政官，需要用两个黑暗圣堂重叠。现在地图上有N个黑暗圣堂，
处于地图上坐标（Xi,Yi）。地图上没有障碍物，黑暗圣堂的移动速度是每秒一个单位。
问从现在开始，再过多少秒就可以出现黑暗的执政官。注：两个黑暗圣堂可同时移动。

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
#define oo 200005
#define ooo 2000000000.0
FILE *fin,*fout;
long n;
double a[2][oo]={0.0},x[2][oo]={0.0};
long b[2][oo]={0},d[oo]={0};
int hush1[oo]={0},hush2[oo]={0};
double ans=ooo,sum=0.0;
void qs(long left,long right,int k)
{
 int l,r,z,tmp,fmp;
 if(left<right)
  {
   l=left;r=right;
   z=(l+r)/2;
   tmp=x[k][z];
   fmp=b[k][z];
   x[k][z]=x[k][l];
   b[k][z]=b[k][l];
   while(l<r)
    {
     while(l<r && x[k][r]>tmp) r--;
     if(l<r)
      {
       x[k][l]=x[k][r];
       b[k][l++]=b[k][r];
      }
     while(l<r && x[k][l]<tmp) l++;
     if(l<r)
      {
       x[k][r]=x[k][l];
       b[k][r--]=b[k][l];
      }
    }
   x[k][l]=tmp;
   b[k][l]=fmp;
   qs(left,l-1,k);
   qs(l+1,right,k);
  }
}
int main()
{
 long i,j,k1,k2,pan=0;
 fin=fopen("dark.in","r");
 fout=fopen("dark.out","w");
 fscanf(fin,"%ld",&n);
 for(i=1;i<=n;i++)
  {
   fscanf(fin,"%lf%lf",&a[0][i],&a[1][i]);
   x[0][i]=a[0][i];
   x[1][i]=a[1][i];
   b[0][i]=b[1][i]=i;
  }
 qs(1,n,0);
 qs(1,n,1);
 for(i=1;i<=n;i++)
  d[b[1][i]]=i;
 for(k1=1;k1<=n;k1++)
  {
   k2=d[b[0][k1]];
   pan=0;
   for(i=1;i<n;i++)
    {
     if(k1-i>=1)
      {
        if(hush2[b[0][k1-i]]==0)
         hush1[b[0][k1-i]]=1;
        else
          {
          sum=sqrt((a[0][b[0][k1]]-a[0][b[0][k1-i]])*(a[0][b[0][k1]]-a[0][b[0][k1-i]])+
                   (a[1][b[0][k1]]-a[1][b[0][k1-i]])*(a[1][b[0][k1]]-a[1][b[0][k1-i]]));
           if(sum<ans)
            ans=sum;
           pan=1;
          }
      }
     if(k1+i<=n)
      {
        if(hush2[b[0][k1+i]]==0)
         hush1[b[0][k1+i]]=1;
        else
          {
          sum=sqrt((a[0][b[0][k1]]-a[0][b[0][k1+i]])*(a[0][b[0][k1]]-a[0][b[0][k1+i]])+
                   (a[1][b[0][k1]]-a[1][b[0][k1+i]])*(a[1][b[0][k1]]-a[1][b[0][k1+i]]));
           if(sum<ans)
            ans=sum;
           pan=1;
          }
      }
     if(k2-i>=1)
      {
        if(hush1[b[1][k2-i]]==0)
          hush2[b[1][k2-i]]=1;
        else 
          {
          sum=sqrt((a[0][b[0][k1]]-a[0][b[1][k2-i]])*(a[0][b[0][k1]]-a[0][b[1][k2-i]])+
                   (a[1][b[0][k1]]-a[1][b[1][k2-i]])*(a[1][b[0][k1]]-a[1][b[1][k2-i]]));
          if(sum<ans)
            ans=sum;
           pan=1;
          }
      }
     if(k2+i<=n)
      {
        if(hush1[b[1][k2+i]]==0)
          hush2[b[1][k2+i]]=1;
        else
          {
          sum=sqrt((a[0][b[0][k1]]-a[0][b[1][k2+i]])*(a[0][b[0][k1]]-a[0][b[1][k2+i]])+
                   (a[1][b[0][k1]]-a[1][b[1][k2+i]])*(a[1][b[0][k1]]-a[1][b[1][k2+i]]));
          if(sum<ans)
            ans=sum;
           pan=1;
          }
      }
     if(pan==1)
      break;
    }
   for(;i>=1;i--)
    {
     if(k1-i>=1)
       hush1[b[0][k1-i]]=0;
     if(k1+i<=n)
       hush1[b[0][k1+i]]=0;
     if(k2-i>=1)
       hush2[b[1][k2-i]]=0;
     if(k2+i<=n)
       hush2[b[1][k2+i]]=0;
    }
  }
 fprintf(fout,"%.2lf",ans/2.0);
 fclose(fin);
 fclose(fout);
 return(0);
}
