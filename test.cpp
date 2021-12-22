//这个例子将说明，关闭与stdio的同步后，混用两种IO的后果
//建议单步运行来观察效果
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  //关闭IO后，cin/cout将使用独立缓冲区，而不是将输出同步至scanf/printf的缓冲区，从而减少IO耗时
  cout << "a";
  // cout下，使用'\n'换行时，内容会被缓冲而不会被立刻输出，应该使用endl来换行并立刻刷新缓冲区
  printf("b");
  // printf的'\n'会刷新printf的缓冲区，导致输出错位
  cout << "c";
  return 0;  //程序结束时，cout的缓冲区才会被输出
}