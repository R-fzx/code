#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int q,n,y,r,s,i,j,k,l;
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout); 
    scanf("%d%d%d",&n,&y,&r);
    s=1;
    for (i=1;i<n;++i)
    {
        if  (i%100==0)
        {
            if (i%400==0) s+=2;
            else s+=1;                     
        }
        else
        {
            if (i%4==0) s+=2;
            else s+=1;            
        }        
    }

    q=0;
    if  (n%100==0)
    {
        if (n%400==0) q=1;
    }
    else
    {
        if (n%4==0) q=1;
    }

    for (i=1;i<y;++i)
    {
        if (i==2) s+=a[i]+q;
        else s+=a[i];        
    }
    s+=r-1;
    s=s%7;    
    switch (s)
    {
           case 1:
                printf("monday\n");
                break;
           case 2:
                printf("tuesday\n");
                break;
           case 3:
                printf("wednesday\n");
                break;
           case 4:
                printf("thursday\n");
                break;
           case 5:
                printf("friday\n");
                break;
           case 6:
                printf("saturday\n");
                break;
           case 0:
                printf("sunday\n");
    }
    fclose(stdin);
    fclose(stdout);    
    return 0;
}
