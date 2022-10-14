/*
1、	换硬币
题目描述：
小玲参加了雅礼的读书社，而最近，读书社正在举行"读万卷书，行万里路"的活动，
热心于社团活动的小玲自然不会错过。
然而，"行万里路"对于小玲还是比较困难的，所以他决定坐公交车。
小玲的目的地需要坐N次车，坐每一次公交车需要一元钱硬币，但小玲没有零钱。
在每一次乘车处都有一个地方换零钱，但这地方的人都很黑，每个地方分别要Ai元才可以换一元硬币。
小玲的钱包可以看作容量无限的。小玲想知道，他需要花多少钱才可以到处目的地。

输入：输入文件有两行，第一行有一个数N，第二行有N个整数，第i个数为Ai。

输出：输出文件只有一个数，为小玲需要花的钱。

样例：
输入：
2
2 1
输出：
3

   
数据范围：1《N《100000
          0《Ai《1000000
*/
#include <stdio.h>
FILE *fin,*fout;
long n;
double a[1000000]={0};
double ans=0.0;
int main()
{ 
 long i,j;
 fin=fopen("bus.in","r");
 fout=fopen("bus.out","w");
 fscanf(fin,"%ld",&n);
 for(i=1;i<=n;i++)
  fscanf(fin,"%lf",&a[i]);
 for(i=1;i<=n;)
  {
   for(j=i+1;j<=n;j++)
    if(a[j]<a[i])
     break;
   ans+=a[i]*((double)(j-i));
   i=j;
  }
 fprintf(fout,"%.0lf\n",ans);
 fclose(fin);
 fclose(fout);
 return(0);
}
