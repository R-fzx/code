#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 3e2 + 10, M = 4e3 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int n, h[N], p[N];

int stx[N], sti[N], top;

signed main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    n = read();
    int jc = 1;
    for (int i = 1; i <= n; i++) h[i] = read(), p[i] = i, jc *= i;
    if (n <= 10) {
        double ans = 0;
        do {
            top = 0;
            stx[++top] = 0x3f3f3f3f, sti[top] = 0;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                while (top && stx[top] < h[p[i]]) --top;
                sum += (i - sti[top]);
                stx[++top] = h[p[i]], sti[top] = i;
            }
            ans = ans + (double)(sum) / jc;
        } while (next_permutation(p + 1, p + n + 1));
        printf("%.2lf\n", ans);
    } else {
        mt19937 rnd(time(NULL));
        double ans = 0; int cas;
        while (clock() <= 950) {
            cas++;
            shuffle(h + 1, h + n + 1, rnd);
            top = 0;
            stx[++top] = (1 << 10), sti[top] = 0;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                while (top && stx[top] < h[p[i]]) --top;
                sum += (i - sti[top]);
                stx[++top] = h[p[i]], sti[top] = i;
            }
            ans = ans + (double)(sum);
        }
        // println(cas);
        // printf("%.2lf\n", ans);
        ans = ans / cas;
        printf("%.2lf\n", ans);
        // println(ans);
    }
    // println(clock());
    return 0;
}