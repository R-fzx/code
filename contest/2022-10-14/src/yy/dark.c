/*
���ڰ���ִ����
��Ŀ������
����羺������Ǽ����Եı�����ZYFСͬѧҲȥ�μӡ����˵��ǣ�����һ��������һ������
�����޵г����������ĳ�ֶ�Ȥζ��ZYFСͬѧ��Ȼ�������Ű���˵Ļ��ᡣ
ZYF���ڵ�ͼ�ϸ������䲼���ڰ�ʥ�ã��׳����������Ĵ�͵Ϯ������һ��֮��о�����񫣬
�����úڰ�ʥ�úϳɺڰ���ִ���٣����İ��˿ڴ�ս��
�ϳɺڰ���ִ���٣���Ҫ�������ڰ�ʥ���ص������ڵ�ͼ����N���ڰ�ʥ�ã����ڵ�ͼ������
��Xi,Yi������ͼ��û���ϰ���ڰ�ʥ�õ��ƶ��ٶ���ÿ��һ����λ���ʴ����ڿ�ʼ���ٹ�
������Ϳ��Գ��ֺڰ���ִ���١�ע�������ڰ�ʥ�ÿ�ͬʱ�ƶ���

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
