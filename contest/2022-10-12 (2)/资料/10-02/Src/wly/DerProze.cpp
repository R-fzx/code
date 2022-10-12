#include <stdio.h>
#include <stdlib.h>
// 2011 12 31 saturday À„Œ≤≤ªÀ„Õ∑  y<=ny
int aa[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    freopen ("DerProze.in", "r", stdin);
    freopen ("DerProze.out", "w", stdout);
    int y, m, d, ny=2011, nm=12, nd=31, tot=0, i, mark=0;
    scanf("%d%d%d", &y, &m, &d);
    if (y>2011) mark = 1, ny=y, nm=m, nd=d, y=2011, m=12, d=31;
    for (i=y+1; i<=ny-1; i++){
        if ((i%4==0 && i%100!=0)
            || (i%400 == 0)  )
                      tot += 366;
        else tot += 365;
    }
    if (mark==1){
         if ((ny%4==0 && ny%100!=0)
            || (ny%400 == 0)) aa[2]++;
         for (i=1; i<nm; i++) tot += aa[i];
         tot += nd;
         tot = (tot+6) % 7;
    }
    else {
         if ((y%4==0 && y%100!=0)
            || (y%400 == 0)) aa[2]++;
         if (y<2011) tot += 365;
         for (i=m+1; i<=12; i++) tot += aa[i];
         tot += aa[m] - d;
         tot = 6 - tot % 7;
    }
    switch (tot){
           case(0): {printf("sunday\n"); break;}
           case(1): {printf("monday\n"); break;}
           case(2): {printf("tuesday\n"); break;}
           case(3): {printf("wednesday\n"); break;}
           case(4): {printf("thursday\n"); break;}
           case(5): {printf("friday\n"); break;}
           case(6): {printf("saturday\n"); break;}
    }
   // system("pause");
    return 0;
}
