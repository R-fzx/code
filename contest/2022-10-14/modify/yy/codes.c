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
001100110

*/
#include <stdio.h>
#include <string.h>
char s[255]={'\0'},a[25][25]={'\0'},ans[255]={'\0'};
int flag=0,ls=0;
short hash[21][1200000]={0};
long c2[25]={0},ansl=10000,n;
int ok(int i,int j)
{char s1[50]={'\0'},s2[50]={'\0'};
 strcpy(s1,a[i]);
 strcat(s1,a[j]);
 strcpy(s2,a[j]);
 strcat(s2,a[i]);
 if (strcmp(s1,s2)>=0)
   return(1);
 return(0);
}
void dg(char c[],int k)
{ if (ls<ansl)
   {long i;    
    for(i=1;i<=n;i++)
      if (i!=flag || k)
      {if (strcmp(c,a[i])==0)
         {ansl=ls;
          ans[0]='\0';
          strcpy(ans,s);
         }
         else
         {long t=1,tot=0,ml,j,lc=strlen(c),li=strlen(a[i]);
          int ok=1;          
          ml=lc;
          if (ml>li) ml=li;
          for(j=0;j<ml;j++)
            if (c[j]!=a[i][j]) 
              {ok=0; break;}
          if (ok)
            {char c2[25]={'\0'};    
             if (lc<li)
               {for(j=0;j<li-lc;j++,t*=2)
                  {s[ls+j]=c2[j]=a[i][lc+j];
                   tot+=(c2[j]-48)*t;
                  }
                if (hash[li-lc][tot]==0)
                  {hash[li-lc][tot]=1;
                   ls+=li-lc;
                   dg(c2,1);
                   ls-=li-lc;
                   hash[li-lc][tot]=0;                   
                  }
               }
               else
               {for(j=0;j<lc-li;j++,t*=2)
                  {c2[j]=c[li+j];
                   tot+=(c2[j]-48)*t;
                  }
                if (hash[lc-li][tot]==0)
                  {hash[lc-li][tot]=1;
                   dg(c2,1);
                   hash[lc-li][tot]=0;                   
                  }
               }
            }
         }
      }
   }
}
int main()
{FILE *fp,*fo;
  long i,j;

  fp=fopen("codes.in","r");
  fo=fopen("codes.out","w");
    fscanf(fp,"%ld\n",&n);
    c2[0]=1;
    for(i=1;i<=n;i++)
      c2[i]=c2[i-1]*2;
    for(i=1;i<=n;i++)
      {fscanf(fp,"%s",a[i]);
      }
    for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        if (/*strlen(a[i])>strlen(a[j]) ||(strlen(a[i])==strlen(a[j]) &&*/ ok(i,j))
          {char va[25]={'\0'};
           strcpy(va,a[i]);
           strcpy(a[i],a[j]);
           strcpy(a[j],va);           
          }
    for(i=1;i<=n;i++)
      {s[0]='\0'; flag=i;
       strcpy(s,a[i]);
       ls=strlen(a[i]);
       dg(a[i],0);
      }
    fprintf(fo,"%ld\n",ansl);
    for(i=0;i<ansl;i++)
    fprintf(fo,"%c",ans[i]);
  fclose(fp);
  fclose(fo);
  return(0);
}
