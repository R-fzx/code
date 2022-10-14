#include <stdio.h>
long a[30],n;

long check()
{
     long i;
     for (i=2;i<n;i++)
         if ((a[i-1]<a[i]&&a[i]<a[i+1])||(a[i-1]>a[i]&&a[i]>a[i+1])) return 1;
     return 0;
}

int main()
{
    FILE *fi,*fo;
    fi=fopen("wave.in","r");
    fo=fopen("wave.out","w");
    long m,tot,c,i,j,k,l,t,kk;
    fscanf(fi,"%ld",&m);
    for (tot=1;tot<=m;tot++)
        {
         fscanf(fi,"%ld%ld",&n,&c);
         for (i=1;i<=n;i++)
             a[i]=i;
         
         for (j=1;j<=c;j++)
         {
         i=n-1;
         while (a[i]>a[i+1]) i--;
         for (k=n;k>i;k--)
             if (a[k]>a[i]) break;
         t=a[k];a[k]=a[i];a[i]=t;
         for (l=0;l<(n-i+1)/2;l++)
             {t=a[l+i+1];a[l+i+1]=a[n-l];a[n-l]=t;}
         if (check()) j--;
         }
         for (kk=1;kk<n;kk++)
         fprintf(fo,"%ld ",a[kk]);
         fprintf(fo,"%ld\n",a[n]);
        }
    fclose(fi);
    fclose(fo);
    return 0;
         
}
