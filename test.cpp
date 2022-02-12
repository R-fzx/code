#define macroexpand(x) #x
#define expand(x) macroexpand(x)
#define expand_andprint(x) printf("%s\n",macroexpand(x))
#include <cstdio>

#define add(x, y) x + y
#define sub(p, q) p - q

int main() {
  expand_andprint(add(sub(3, 4),2));
  return 0;
}
