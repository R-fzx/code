/*
合唱队形
题目描述：
    雅礼的社团准备开一次大型文艺演出，其中合唱是少不了的。 
   合唱有N个人，但这N个人的身高差距比较明显，第一人到第N个人身高依次递增。为了使
   整个合唱队的身高差距看上去不是太明显，可爱的猪决定，不能让连续三人的身高递增或
   递减，也就是说所有的人（不包括两头的人）要不比他边上的两个人都高，要不就是都矮。
   每一个序列都可以用一个1~N的排列来表式。现在可爱的猪想知道，按字典序排序，N个人
   排出的第C个序列是怎么样的。

输入：
输入文件第一行包含一个整数M，表式数据组数。
之后有M组数据，每行两个数，N，C。

输出：
输出文件有M行，
每组数据占一行，这一行有N个数，表示N个人中第C大的合法排列。

样例：
　　　输入：
　　　　２
　　　　２　１
　　　　３　３ 
输出：
　　１　２
　　２　３　１


n<=20 m <=100
（当Ｎ为４时，所有的序列如下）

*/
#include <stdio.h>
FILE *fp,*fo;
long c,hash[21]={0},b[21]={0},n,total=0;
int ok(long k1,long k2,long k3)
{ if (k1<k2 && k2<k3) return(1);
  if (k1>k2 && k2>k3) return(1);
  return(0);
}
void dg(long k,long q1,long q2)
{ long i;
  if (k<=n)
  for(i=1;i<=n;i++)
   {if (hash[i]==0)
     {if (k>2 && ok(q2,q1,i)) break;
      hash[i]=1; b[k]=i;
      dg(k+1,i,q1);
      hash[i]=0;
      if (total==c) break;      
      }
   }
   else 
     {total++;
      if (total==c)
      { long j;
        for(j=1;j<=n;j++) 
         {if (j!=1) fprintf(fo," ");
          fprintf(fo,"%ld",b[j]);
         }             
      }   
     }
}
main()
{ 
  fp=fopen("wave.in","r");
  fo=fopen("wave.out","w");
  long i,j,m;
  fscanf(fp,"%ld",&m);
  for(i=1;i<=m;i++)
  {fscanf(fp,"%ld %ld",&n,&c);
   total=0;
   dg(1,0,0);  
   fprintf(fo,"\n");
  }  
  fclose(fo);
  fclose(fp);
}
