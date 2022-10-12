#include <stdio.h>
#include <stdlib.h>
int main(){
    freopen ("Metamorphosis.in", "r", stdin);
    freopen ("Metamorphosis.out", "w", stdout);
    int x1, y1, x2, y2, d;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (y1<0) y1 = 0;
    if (y2<0) y2 = 0;
    d = abs(x2-x1);
    if (y2<=81-36) { printf("%.1lf\n", (double)y2);  return 0;} 
    else { printf("%.1lf\n", (double)y2+d);  return 0;} 
}
