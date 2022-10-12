#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG
double cc=clock();
int main()
{
    freopen("かなで.in","r",stdin);
    freopen("かなで.out","w",stdout);
    srand((unsigned)time(NULL));
    int n,m,k;
    char s[51][51];
    scanf("%d%d%d%*c",&n,&m,&k);
    for (int i=1; i<=n; i++)
        scanf("%s%*c",s+1);
    printf("%d\n",(rand()%8001+k%8001+n*m%8001)%8001);
    return 0;
}
