#include <stdio.h>
FILE *fp,*fo;
long n,m,hash[30]={0},t=0,dx[30]={0},f=0;
double c=0;
void find(long),print();
int main()
{
    long i,j;
    fp=fopen("wave.in","r");
    fo=fopen("wave.out","w");
    fscanf(fp,"%ld",&m);
    for (i=1;i<=m;i++)
      {fscanf(fp,"%ld%ld",&n,&c);
       for (j=1;j<=n;j++)
        {hash[j]=0;
         dx[j]=0;
        }
       t=0;
       find(1);
      }
    fclose(fp);
    fclose(fo);
    return 0;
}
void find(long s)
{
     long i;
     if (s==1)
       {for (i=1;i<=n && t<c;i++)
         {f=1;
          hash[i]=1;
          dx[s]=i;
          if (t<c)
           find(s+1);
          f=0;
          if (t<c)
           find(s+1);
          hash[i]=0;
          dx[s]=0;
         }
        return;
       }
     if (s>n)
       {t++;
        if (t==c)
         {print();
         }
        return;
       }
     if (f==0)
       {for (i=dx[s-1]+1;i<=n && t<c;i++)
          {f=1;
           if (!hash[i])
             {hash[i]=1;
              dx[s]=i;
              find(s+1);
              dx[s]=0;
              hash[i]=0;
             }
           f=0;
          }
       }
     if (f==1)
       {for (i=1;i<dx[s-1] && t<c;i++)
          {f=0;
           if (!hash[i])
             {hash[i]=1;
              dx[s]=i;
              find(s+1);
              dx[s]=0;
              hash[i]=0;
             }
           f=1;
          }
       }
}
void print()
{
     long i;
     for (i=1;i<n;i++)
       fprintf(fo,"%ld ",dx[i]);
     fprintf(fo,"%ld\n",dx[i]);
}
