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
long  n,hash[25]={0};
long long f[25][25][2]={0};
long get(long k)
{long i,t=0;
 for(i=1;i<=n;i++)
   {if (hash[i]==0) t++;
    if (t==k) return(i);
   }
  
}
main()
{ FILE *fp,*fo;
  fp=fopen("wave.in","r");
  fo=fopen("wave.out","w");
  long i,j,m,k,p;
  long long c;
  fscanf(fp,"%ld",&m);
  f[1][1][0]=1; f[1][1][1]=1;
  for(i=2;i<=20;i++)
    for(j=1;j<=i;j++)
      for(k=0;k<2;k++)
        {if (k==0)
           for(p=j-1;p>0;p--)
             f[i][j][k]+=f[i-1][p][1];
         if (k==1)
           for(p=j;p<=i;p++)
             f[i][j][k]+=f[i-1][p][0];
        }
  for(p=1;p<=m;p++)
  {fscanf(fp,"%ld %I64d",&n,&c);
   memset(hash,0,sizeof(hash));
   long x=-1,flag=-1;
   for(i=n;i>0;i--)
     for(j=1;j<=i;j++)
       { 
         if (flag!=0 && (j>=x || x==-1))
         if (f[i][j][0]<c) c-=f[i][j][0];
         else
           {
            if (flag!=-1) fprintf(fo," ");
            flag=0;
            x=get(j);
            hash[x]=1;            
            fprintf(fo,"%ld",x);
            x=j;
            break;
           }    
         if (flag!=1 && (j<x || x==-1))
         if (f[i][j][1]<c) c-=f[i][j][1];
         else
           {
            if (flag!=-1) fprintf(fo," ");
            flag=1;
            x=get(j);
            hash[x]=1;            
            fprintf(fo,"%ld",x);
            x=j;
            break;
           }     
       }
  fprintf(fo,"\n");
  }  
  fclose(fo);
  fclose(fp);
}
