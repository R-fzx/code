//# include <bits/stdc++.h>
//
//using namespace std;
//
//int n, ans = 500;
//char s[30][30];
//bool in[30][30][30];
//vector<int> inik[30][30];
//int len[30];
//
////char s1[444];
////char s2[444];
//vector <int> ans1;
//vector <int> ans2;
//vector < vector <int> > anspr;
//
//void Dfs(int len1, int len2) {
//  if (len1 == len2) {
//    if (len1 && len1 < ans) {
//      anspr.clear();
//      anspr.push_back(ans1);
//      ans = len1;
//    } else if (len1 == ans) {
//      anspr.push_back(ans1);
//    }
//    ans1.push_back(0);
//    for (int i = 1; i <= n; i++) {
//      ans1[ans1.size() - 1] = i;
//      Dfs(len1 + len[i], len2);
//    }
//    ans1.pop_back();
//  }
//  
//  if (len2 < len1) {
//    int k = len[ans1]len1 - len2;
//    for (int i = 0; i < inik;)
//  }
//}
//
//int main() {
//  scanf("%d", &n);
//  for (int i = 1; i <= n; i++) {
//    scanf("%s", s[i] + 1);
//    len[i] = strlen(s[i] + 1);
//  }
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      for (int k = 1; k <= len[i]; k++) { // i[k] push j
//        in[i][j][k] = 1;
//        for (int l = 1; l <= min(len[j], len[i] - k + 1); l++) {
//          in[i][j][k] &= (s[i][k + l - 1] == s[j][l]);
//        }
//        if (in[i][j][k]) {
//          inik[i][k].push_back(j);
//        }
//      }
//    }
//  }
//  Dfs(0, 0);
//}
