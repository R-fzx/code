/*
�ϳ�����
��Ŀ������
    ���������׼����һ�δ��������ݳ������кϳ����ٲ��˵ġ� 
   �ϳ���N���ˣ�����N���˵���߲��Ƚ����ԣ���һ�˵���N����������ε�����Ϊ��ʹ
   �����ϳ��ӵ���߲�࿴��ȥ����̫���ԣ��ɰ�����������������������˵���ߵ�����
   �ݼ���Ҳ����˵���е��ˣ���������ͷ���ˣ�Ҫ���������ϵ������˶��ߣ�Ҫ�����Ƕ�����
   ÿһ�����ж�������һ��1~N����������ʽ�����ڿɰ�������֪�������ֵ�������N����
   �ų��ĵ�C����������ô���ġ�

���룺
�����ļ���һ�а���һ������M����ʽ����������
֮����M�����ݣ�ÿ����������N��C��

�����
����ļ���M�У�
ÿ������ռһ�У���һ����N��������ʾN�����е�C��ĺϷ����С�

������
���������룺
����������
��������������
�������������� 
�����
����������
��������������
n<=20 m <=100
������Ϊ��ʱ�����е��������£�
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
