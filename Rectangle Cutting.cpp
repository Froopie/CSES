#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e2 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int a, b, dp[MAXN][MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      dp[i][j] = 1e9;
  for (int i = 1; i <= 500; i++)
    dp[i][i] = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k < 500; k++) {
        if (k < i) dp[i][j] = min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
        if (k < j) dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
      }
  cout << dp[a][b];
  return 0;
}