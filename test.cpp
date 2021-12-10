#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
char A[1000010];
int L, N;
struct Node {
  bool isnum;
  double num;
  char ch;
  Node(bool isnum = false, double num = 0, char ch = '\0') : isnum(isnum), num(num), ch(ch) {}
};
const double PI = 3.14159265358979323846, EN = 2.71828182845904523536, PH = 0.61803398874989484820;
stack<char> pri;
double ans[1000010];
queue<Node> ret;
int ope(char q) {
  if (q == '+') return 0;
  if (q == '-') return 0;
  if (q == '*') return 1;
  if (q == '/') return 1;
  if (q == '^') return 2;
  return -1;
}
pair<double, int> gn(int w) {
  double rett = 0, flag = 1, qwq = 1, poi = false;
  if (A[w] == '-') flag = -1, ++w;
  while ((A[w] >= '0' && A[w] <= '9') || (A[w] == '.' && !poi)) {
    if (A[w] == '.')
      poi = true, qwq /= 10;
    else {
      if (poi)
        rett = rett + qwq * (A[w] - '0'), qwq /= 10;
      else
        rett = rett * 10 + A[w] - '0';
    }
    ++w;
  }
  return make_pair(rett * flag, w - 1);
}
void PD(double O) {
  double R = 0.000000000001;
  if (isnan(O)) {
    printf("NAN\n");
    return;
  }
  if (isinf(O)) {
    printf("INF\n");
    return;
  }
  O += 5e-13;
  if (O < 0) {
    printf("-");
    O *= -1;
  }
  printf("%lld", (long long)O);
  O -= (long long)O;
  if (O < 0.000000000001) {
    printf("\n");
    return;
  }
  int u = 0;
  printf(".");
  while (O >= R && u != 12) O *= 10, printf("%d", (int)O), O -= (int)O, ++u, R *= 10;
  printf("\n");
}
void runSt() {
  for (int i = 0; i < L; i++) {
    if (A[i] >= '0' && A[i] <= '9') {
      pair<double, int> gnum = gn(i);
      ret.push(Node(true, gnum.first, '\0'));
      i = gnum.second;
    } else if (A[i] == 'P' && A[i + 1] == 'I')
      ++i, ret.push(Node(true, PI, '\0'));
    else if (A[i] == 'E')
      ++i, ret.push(Node(true, EN, '\0'));
    else if (A[i] == 'P' && A[i + 1] == 'H')
      ++i, ret.push(Node(true, PH, '\0'));
    else if (A[i] == '-' && (!i || !(A[i - 1] >= '0' && A[i - 1] <= '9')) && A[i - 1] != ')') {
      pair<double, int> gnum = gn(i);
      ret.push(Node(true, gnum.first, '\0'));
      i = gnum.second;
    } else if (A[i] == '+' && (!i || !(A[i - 1] >= '0' && A[i - 1] <= '9')) && A[i - 1] != ')') {
      pair<double, int> gnum = gn(i);
      ret.push(Node(true, gnum.first, '\0'));
      i = gnum.second;
    } else if (A[i] == '(')
      pri.push('(');
    else if (A[i] == ')') {
      while (ope(pri.top()) != -1) {
        ret.push(Node(false, 0, pri.top()));
        pri.pop();
      }
      if (pri.top() != '(') ret.push(Node(false, 0, pri.top()));
      pri.pop();
    } else if (A[i] == ',') {
      while (ope(pri.top()) != -1) {
        ret.push(Node(false, 0, pri.top()));
        pri.pop();
      }
    } else if (A[i] == 's') {
      if (A[i + 1] == 'q')
        i += 4, pri.push('J');
      else
        i += 3, pri.push('s');
    } else if (A[i] == 'c')
      i += 3, pri.push('c');
    else if (A[i] == 't')
      i += 3, pri.push('t');
    else if (A[i] == 'r')
      i += 4, pri.push('r');
    else if (A[i] == 'p')
      i += 3, pri.push('p');
    else if (A[i] == 'a') {
      if (A[i + 1] == 's')
        i += 4, pri.push('S');
      else if (A[i + 1] == 'c')
        i += 4, pri.push('C');
      else if (A[i + 1])
        i += 4, pri.push('T');
    } else {
      while (!pri.empty() && ope(pri.top()) >= ope(A[i])) {
        ret.push(Node(false, 0, pri.top()));
        pri.pop();
      }
      pri.push(A[i]);
    }
  }
  while (!pri.empty()) {
    ret.push(Node(false, 0, pri.top()));
    pri.pop();
  }
  N = 0;
  bool er = false;
  while (!ret.empty()) {
    Node R = ret.front();
    ret.pop();
    if (er) continue;
    if (R.isnum)
      ans[N++] = R.num;
    else {
      if (R.ch == '+') {
        if (N < 2) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] += ans[N - 1];
        --N;
      } else if (R.ch == '-') {
        if (N < 2) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] -= ans[N - 1];
        --N;
      } else if (R.ch == '*') {
        if (N < 2) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] *= ans[N - 1];
        --N;
      } else if (R.ch == '/') {
        if (N < 2 || ans[N - 1] == 0) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] /= ans[N - 1];
        --N;
      } else if (R.ch == 'r') {
        if (N < 2 || ans[N - 1] == 0) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] = pow(ans[N - 2], 1 / ans[N - 1]);
        --N;
      } else if (R.ch == 'p' || R.ch == '^') {
        if (N < 2) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 2] = pow(ans[N - 2], ans[N - 1]);
        --N;
      } else if (R.ch == 'J') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = sqrt(ans[N - 1]);
      } else if (R.ch == 's') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = sin(ans[N - 1]);
      } else if (R.ch == 'c') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = cos(ans[N - 1]);
      } else if (R.ch == 't') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = tan(ans[N - 1]);
      } else if (R.ch == 'S') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = asin(ans[N - 1]);
      } else if (R.ch == 'C') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = acos(ans[N - 1]);
      } else if (R.ch == 'T') {
        if (N < 1) {
          printf("ERROR!\n");
          er = true;
          return;
        }
        ans[N - 1] = atan(ans[N - 1]);
      }
    }
  }
  if (N == 0) printf("ERROR\n"), er = true;
  if (!er) PD(ans[0]);
}
bool pass = true;
int main() {
  if (pass) {
    printf("     Science Calculator     \n");
    printf("These functions is valiable:\n");
    printf(" sqrt(x) root(x,y) pow(x,y) \n");
    printf("    sin(a) cos(a) tan(a)    \n");
    printf("   asin(a) acos(a) atan(a)  \n");
    printf("        You can use         \n");
    printf("   PI as %.12lf   \n", PI);
    printf("   EN as %.12lf   \n", EN);
    printf("   PH as %.12lf   \n", PH);
    printf("----------------------------\n");
    pass = false;
  }
  printf("> ");
  L = 0;
  while (scanf("%c", &A[L]) != EOF && A[L] != '\n') {
    if (A[L] != ' ' && A[L] != '\t') ++L;
  }
  if (L == 0) return 0;
  runSt();
  main();
}
