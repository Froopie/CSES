#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll dp[MAXN][MAXN];
string a[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dp[0][0] = (a[0][0] == '.');
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*')
        continue;
      if (i) dp[i][j] += dp[i-1][j];
      if (j) dp[i][j] += dp[i][j-1];
      dp[i][j] %= mod;
    }
  cout << dp[n-1][n-1];
  return 0;
}