#pragma GCC optimize(3)
#pragma GCC target("avx")
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
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
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
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>

using namespace std;

const int N = 1 << 12;
const int K = 13;

int k, ans[N], b[N][K], len, vis[N];

inline void dfs(int x) {
  if (!x) {
    ++len;
    for (int i = k; i >= 1; --i) { 
      b[len][k - i + 1] = ans[i];
    }
    return ;
  }
  ans[x] = 0;
  dfs(x - 1);
  ans[x] = 1;
  dfs(x - 1);
}

int main() {
  cin >> k;
  cout << (1 << k) << ' ';
  dfs(k);
  for (int i = 1; i <= len; ++i) {
    for (int j = 1; j <= k; ++j) {
      cout << b[i][j];
    }
    cout << '\n';
  }
  // cout << 1;
  ans[1] = 1;
  vis[1] = 1;
  ans[len] = (1 << (k - 1)) + 1;
  vis[(1 << (k - 1)) + 1] = 1;
  ans[max(len - (k - 2) - 1, 0)] = len;
  vis[len] = 1;
  
  for (int i = 1; i < len - 1; ++i) {
    if (i + 1 == max(len - (k - 2) - 1, 0)) {
      continue;
    }
    // if (ans[i + 1]) {
    //   continue;
    // }
    for (int j = 1; j <= len; ++j) {
      if (vis[j]) {
        continue;
      }
      int flag = 0;
      for (int l = 1; l < k; ++l) {
        if (b[ans[i]][l + 1] != b[j][l]) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        vis[j] = 1;
        ans[i + 1] = j;
        break;
      }
    }
  }

  for (int i = 1; i <= len; ++i) {
    cout << ans[i] << '\n';
  }

  for (int i = 1; i <= k; ++i) {
    cout << b[ans[1]][i];
  }
  for (int i = 2; i <= len - (k - 2) - 1; ++i) {
    cout << b[ans[i]][k];
  }
  return 0;
}