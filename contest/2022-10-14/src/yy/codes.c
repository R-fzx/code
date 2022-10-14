/*
2、最长分解序列
题目描述：（不想加背景）
   给定n个01编码串S1,S2,…,Sn，你的任务是寻找一个编码串T，使得它至少可以被分解为
   两种不同的Si的排列。
例如：
给定5个01编码串：S1=0110，S2=00，S3=111，S4=001100，S5=110。那么一个符合要求的编
码串T是：001100110，它有以下两种分解方法：
 00+110+0110 (S2+S5+S1) 或 001100+110 (S4+S5)
而0110110就不符合要求，它只有一种分解方法 0110+110 (S1+S5)。
你要寻找长度最短的符合要求的编码串T。若有多个符合要求的最短编码串T，则输出字典顺
序最小的。

输入：
    输入文件第一行包含一个整数n，n不超过20，表示01编码串总数。接下来的n行每行给
    出一个长度不超过20的01编码串。

输出：
    输出文件共有两行，第一行为要求的编码串T的长度，第二行输出编码串T。对所有的测
    试数据，问题总有解。

样例：
输入：
5
0110
00
111
001100
110

输出：
9
2+4+32+64
001100110

*/
#include <stdio.h>
#include <string.h>
struct ww
{ char s[25];
  long t;
}a[25]={{'\0'},{0}},va;
long f[2100000]={0};
int ok(int i,int j)
{char s1[50]={'\0'},s2[50]={'\0'};
 strcpy(s1,a[i].s);
 strcat(s1,a[j].s);
 strcpy(s2,a[j].s);
 strcat(s2,a[i].s);
 if (strcmp(s1,s2)>=0)
   return(0);
 return(1);
}
int main()
{FILE *fp,*fo;
  long i,j,n,c2[25]={0},b[25]={0},lb=0;
  char s[25]={'\0'};
  fp=fopen("codes.in","r");
  fo=fopen("codes.out","w");
    fscanf(fp,"%ld\n",&n);
    c2[0]=1;
    for(i=1;i<=21;i++)
      c2[i]=c2[i-1]*2;
    for(i=1;i<=n;i++)
      {fscanf(fp,"%s",a[i].s);
       long t=1;
       for(j=strlen(a[i].s)-1;j>=0;j--)
         {a[i].t+=t*(a[i].s[j]-48);
          t*=2;
         }
       f[a[i].t]=1;  
      }
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        if (strlen(a[i].s)>strlen(a[j].s) ||(strlen(a[i].s)==strlen(a[j].s) && ok(i,j)))
          {va=a[i];a[i]=a[j];a[j]=va;
          }
    for(i=0;i<2097152;i++)
     {
      for(j=1;j<=n;j++)
        if (i>a[j].t && (i-a[j].t)%c2[strlen(a[j].s)]==0)
        {long k;
         k=i-a[j].t;
         k/=c2[strlen(a[j].s)];
         if (f[k]!=0)
           f[i]+=f[k];
        }
      if (f[i]>1)
        {for(j=1;j<=n;j++)
           if (a[j].t==0)
             {fprintf(fo,"%s",a[j].s);
             }
         j=i;
         while(j>0)
           {b[++lb]=j%2;
            j/=2;
           }
         for(j=lb;j>0;j--)
           fprintf(fo,"%d",b[j]); 
         fprintf(fo,"\n");          
         break;
        }
     }
  fclose(fp);
  fclose(fo);
  return(0);
}
