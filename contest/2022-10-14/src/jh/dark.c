/*
3���ڰ���ִ����
��Ŀ������
����羺������Ǽ����Եı�����ZYFСͬѧҲȥ�μӡ�
���˵��ǣ�����һ��������һ�����������޵г��������
��ĳ�ֶ�Ȥζ��ZYFСͬѧ��Ȼ�������Ű���˵Ļ��ᡣ
ZYF���ڵ�ͼ�ϸ������䲼���ڰ�ʥ�ã��׳����������Ĵ�͵Ϯ��
����һ��֮��о�����񫣬�����úڰ�ʥ�úϳɺڰ���ִ���٣����İ��˿ڴ�ս��
�ϳɺڰ���ִ���٣���Ҫ�������ڰ�ʥ���ص������ڵ�ͼ����N���ڰ�ʥ�ã�
���ڵ�ͼ�����꣨Xi,Yi������ͼ��û���ϰ���ڰ�ʥ�õ��ƶ��ٶ���ÿ��һ����λ��
�ʴ����ڿ�ʼ���ٹ�������Ϳ��Գ��ֺڰ���ִ���١�ע�������ڰ�ʥ�ÿ�ͬʱ�ƶ���

���룺�����ļ���N+1�С�
��һ����һ����N��
��2��N+1��ÿ��������������ʾ��I���ڰ�ʥ�õ����ꡣ

���������ļ�ֻ��һ��ʵ��������3λС������Ϊ�ڰ���ִ����������ֵ�ʱ�䡣

������
���룺
4
0 0
0 1
1 0
0 0
�����
0��000



���ݷ�Χ��
2��N��200000
0��Xi,Yi��1000000
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
