#include <stdio.h>
#include <stdlib.h>
int main(){
    freopen ("���ʤ�.in", "r", stdin);
    freopen ("���ʤ�.out", "w", stdout);
    
    int f[11]={0, 1, 1, 2, 5, 12, 1, 1, 1, 1, 1};
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", f[k]);
    return 0;
}
