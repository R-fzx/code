#include <stdio.h>
#include <string.h>
FILE *fp,*fo;
char s[30][30]={"\0"};
long n,num[30]={0};
void qsort(long,long);
void con(char *,char *,char *);
int ok(char *,long,long);
int main()
{
    long i,j,k,l,m;
    char c[60]="\0";
    fp=fopen("codes.in","r");
    fo=fopen("codes.out","w");
    fscanf(fp,"%ld\n",&n);
    for (i=1;i<=n;i++)
      {fgets(s[i],22,fp);
       num[i]=i;
       l=strlen(s[i]);
       if (s[i][l-1]=='\n')
         s[i][l-1]=0;
      }
    qsort(1,n);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        for (k=1;k<=n;k++)
          for (m=1;m<=n;m++)
            {
            con(s[num[i]],s[num[j]],c);
            if (k!=i && m!=j && ok(c,k,m))
              fprintf(fo,"%ld\n%s\n",strlen(c),c);
            }
    fclose(fp);
    fclose(fo);
    return 0;
}
void qsort(long m,long n)
{
     long i,t,q=m;
     char a[60]="\0",b[60]="\0";
     if (m<n)
     {
     for (i=m;i<n;i++)
       {con(s[num[i]],s[num[n]],a);
        con(s[num[n]],s[num[i]],b);
       if (strcmp(a,b)<0)
        {t=num[i];
         num[i]=num[q];
         num[q]=t;
         q++;
        }
       }
     t=num[i];
     num[i]=num[q];
     num[q]=t;
     qsort(m,q-1);
     qsort(q+1,n);
     }
}
int ok(char *c,long m,long n)
{
    char a[60]="\0";
    con(s[num[m]],s[num[n]],a);
    if (!strcmp(c,a))
      return 1;
    return 0;
}
void con(char* a,char *b,char *s)
{
     long i,l=strlen(a);
     char c[60]="\0";
     for (i=0;i<l;i++)
       c[i]=a[i];
     strcat(c,b);
     l=strlen(c);
     for (i=0;i<l;i++)
       s[i]=c[i];
     s[i]=0;
     return;
}
