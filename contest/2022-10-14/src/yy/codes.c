/*
2����ֽ�����
��Ŀ������������ӱ�����
   ����n��01���봮S1,S2,��,Sn�����������Ѱ��һ�����봮T��ʹ�������ٿ��Ա��ֽ�Ϊ
   ���ֲ�ͬ��Si�����С�
���磺
����5��01���봮��S1=0110��S2=00��S3=111��S4=001100��S5=110����ôһ������Ҫ��ı�
�봮T�ǣ�001100110�������������ַֽⷽ����
 00+110+0110 (S2+S5+S1) �� 001100+110 (S4+S5)
��0110110�Ͳ�����Ҫ����ֻ��һ�ַֽⷽ�� 0110+110 (S1+S5)��
��ҪѰ�ҳ�����̵ķ���Ҫ��ı��봮T�����ж������Ҫ�����̱��봮T��������ֵ�˳
����С�ġ�

���룺
    �����ļ���һ�а���һ������n��n������20����ʾ01���봮��������������n��ÿ�и�
    ��һ�����Ȳ�����20��01���봮��

�����
    ����ļ��������У���һ��ΪҪ��ı��봮T�ĳ��ȣ��ڶ���������봮T�������еĲ�
    �����ݣ��������н⡣

������
���룺
5
0110
00
111
001100
110

�����
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
