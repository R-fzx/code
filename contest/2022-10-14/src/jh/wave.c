/*
4、合唱队形
题目描述：
    雅礼的社团准备开一次大型文艺演出，其中合唱是少不了的。 
   合唱有N个人，但这N个人的身高差距比较明显，第一人到第N个人身高依次递增。
   为了使整个合唱队的身高差距看上去不是太明显，可爱的猪决定，不能让连续三人的身高递增或递减，
   也就是说所有的人（不包括两头的人）要不比他边上的两个人都高，要不就是都矮。
   每一个序列都可以用一个1~N的排列来表式。现在可爱的猪想知道，按字典序排序，
   N个人排出的第C个序列是怎么样的。

输入：
输入文件第一行包含一个整数M，表式数据组数。
之后有M组数据，每行两个数，N，C。

输出：
输出文件有M(<=100)行，
每组数据占一行，这一行有N(<=20)个数，表示N个人中第C大的合法排列。

样例：
　　　输入：
　　　　２
　　　　２　１
　　　　３　３ 
输出：
　　１　２
　　２　３　１
　

（当Ｎ为４时，所有的序列如下）
*/
#include <stdio.h>
FILE *fin,*fout;
int m,n;
long sum=0,c;
int hush[21]={0},lu[21]={0};
void ot(int k,int dfa,int fa)
{
 int i;
 if(k<n && sum<c)
  {
   for(i=1;i<=n;i++)
    if(hush[i]==0 && sum<c && ((dfa>fa && fa<i) || (dfa<fa && fa>i)))
     {
      hush[i]=1;
      lu[k]=i;
      ot(k+1,fa,i);
      hush[i]=0;
     }
   }
 else
  {
   sum++;
   if(sum==c)
    {
     for(i=0;i<n;i++)
      {
       if(i==0)
        fprintf(fout,"%d",lu[i]);
       else
        fprintf(fout," %d",lu[i]);
      }
     fprintf(fout,"\n");
    }
  }
}
void work()
{
 int i,j;
 fscanf(fin,"%d%ld",&n,&c);
 sum=0;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   if(i!=j)
   {
    hush[i]=hush[j]=1;
    lu[0]=i;lu[1]=j;
    ot(2,i,j);
    hush[i]=0;
    hush[j]=0;
   }
}
main()
{
 int i;
 fin=fopen("wave.in","r");
 fout=fopen("wave.out","w");
 fscanf(fin,"%d",&m); 
 for(i=1;i<=m;i++)
  work();
 fclose(fin);
 fclose(fout);
 return(0);

}
