#include <stdio.h>
#include <stdlib.h>

long long f[103][103][103]={0},g[103][103][103]={0};
long long in[500]={0};
long long abi[500003][3],current[500003];
long long i,j,k,x,y,z,n,a,b,c,sum,flag;
char hash[500003];

long long min(long long x,long long y)
{
     return x<y?x:y;
}

void sw(int x,int y)
{
     int t;
     
     t=current[x];
     current[x]=current[y];
     current[y]=t;
}

void insert(void)
{
    long long i,j,k;
    
    for (i=1; i<=a+b+c; i++)
    {
        if (hash[current[i]]!='Y')
        {
           in[0]++;
           in[in[0]]=current[i];
           hash[current[i]]='Y';
        }
    }
}

void quicksort(long long l,long long r,long long key)
{
     if (l>=r || l>a+b+c)
        return;
     
     //printf("%I64d %I64d %I64d\n",l,r,key);
     
     long long mid,val,val_,i,j;
     
     mid=(l+r)/2;
     val=abi[current[mid]][key];
     val_=abi[current[mid]][0]+abi[current[mid]][1]+abi[current[mid]][2];
     i=l-1,j=r+1;
     
     while (1==1)
     {
           do
           {
             i++;
           }
           while (abi[current[i]][key]>val
                 || (abi[current[i]][key]==val
                    && abi[current[i]][0]+abi[current[i]][1]+abi[current[i]][2]>val_));
           
           do
           {
             j--;
           }
           while (abi[current[j]][key]<val
                 || (abi[current[j]][key]==val
                    && abi[current[j]][0]+abi[current[j]][1]+abi[current[j]][2]<val_));
           
           if (i<j)
              sw(i,j);
           else
               break;
           
     }
     
     quicksort(l,j,key);
     quicksort(j+1,r,key);
     
     return;
}

int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if (a+b+c>n)
    {
       printf("I am a godlike cowcowcow\n");
       return 0;
    }
    
    for (i=1; i<=n; i++)
    {
        scanf("%I64d%I64d%I64d",&abi[i][0],&abi[i][1],&abi[i][2]);
        current[i]=i;
    }
    
    quicksort(1,n,0);
    insert();
    quicksort(1,n,1);
    insert();
    quicksort(1,n,2);
    insert();
    
    for (i=1; i<=in[0]; i++)
    {
        //printf("%I64d %I64d\n",i,in[i]);
        sum=abi[in[i]][0]+abi[in[i]][1]+abi[in[i]][2];
        for (x=min(a,i-1); x>=0; x--)
        {
            for (y=min(b,i-1-x); y>=0; y--)
            {
                for (z=min(c,i-1-x-y); z>=0; z--)
                {
                    if (f[x+1][y][z]<f[x][y][z]+abi[in[i]][0]
                       || (f[x+1][y][z]==f[x][y][z]+abi[in[i]][0]
                          && g[x+1][y][z]<g[x][y][z]+sum))
                    {
                          f[x+1][y][z]=f[x][y][z]+abi[in[i]][0];
                          g[x+1][y][z]=g[x][y][z]+sum;
                    }
                    
                    if (f[x][y+1][z]<f[x][y][z]+abi[in[i]][1]
                       || (f[x][y+1][z]==f[x][y][z]+abi[in[i]][1]
                          && g[x][y+1][z]<g[x][y][z]+sum))
                    {
                          f[x][y+1][z]=f[x][y][z]+abi[in[i]][1];
                          g[x][y+1][z]=g[x][y][z]+sum;
                    }
                    
                    if (f[x][y][z+1]<f[x][y][z]+abi[in[i]][2]
                       || (f[x][y][z+1]==f[x][y][z]+abi[in[i]][2]
                          && g[x][y][z+1]<g[x][y][z]+sum))
                    {
                          f[x][y][z+1]=f[x][y][z]+abi[in[i]][2];
                          g[x][y][z+1]=g[x][y][z]+sum;
                    }
                
                }
            }
        }
    }
    
    printf("%I64d\n%I64d\n",f[a][b][c],g[a][b][c]);
    
    //system("pause");
    return 0;
}
                    
