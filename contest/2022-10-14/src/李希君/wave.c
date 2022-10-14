#include<stdio.h>
int hash[110],dui[110],m,n,c,pan;
long ans;
FILE *in,*out;
void f(int p)
{
     int i,j,k,last;
     if (pan==1)
     return;
     if (p==n)
     {
        if (dui[p-1]>dui[p-2])
        k=-1;
        else
        k=1;
        if (k==1)
        for (i=dui[p-1]+k;i<=n;i++)
        if (hash[i]==0)
        {ans++;last=i;break;}
        if (k==-1)
        for (i=dui[p-1]+k;i>=1;i--)
        if (hash[i]==0)
        {ans++;last=i;break;}
        if (ans==c)
        {
         for (i=1;i<n;i++)
         fprintf (out,"%d ",dui[i]);
          fprintf (out,"%d\n",last);
          pan=1;
        }
        return;
     }
     else
     {
      if (dui[p-1]>dui[p-2])
      k=-1;
      else
      k=1;
      if (k==1)
      {
        for (i=dui[p-1]+k;i<=n;i++)
         if (hash[i]==0)
         {
            dui[p]=i;
            hash[i]=1;
            f(p+1);
            dui[p]=0;
            hash[i]=0;
         }
      }
      else
      {
      for (i=dui[p-1]+k;i>=1;i--)
         if (hash[i]==0)
         {
            dui[p]=i;
            hash[i]=1;
            f(p+1);
            dui[p]=0;
            hash[i]=0;
         }
      }
        return;
      }
     
}
int main()
{
 
   in=fopen ("wave.in","r");
   out=fopen ("wave.out","w");
   int i,j,k;
   fscanf (in,"%d",&m);
   for (i=0;i<m;i++)
   {
      fscanf (in,"%d %d",&n,&c);
      memset(dui,0,sizeof(dui));
      memset(hash,0,sizeof(hash));
      ans=0;
      pan=0;
      if (n!=2)
      {
      for (j=1;j<=n&&ans!=c;j++)
       for (k=1;k<=n&&ans!=c;k++)
       if (j!=k)
       {
         hash[j]=1;
         hash[k]=1;
         dui[1]=j;
         dui[2]=k;
         f(3);
         hash[j]=0;
         hash[k]=0;
         dui[2]=0;
         dui[1]=0;
       }
      }
       else if (n==2)
       {
          if (c==1)
          fprintf (out,"1 2\n");
          else
          fprintf (out,"2 1\n");
       }
       else if (n==1)
       fprintf (out,"1\n");
   }
   fclose(in);
   fclose(out);
   return 0;
}
