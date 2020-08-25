#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, m, a[MAXN];
ll dp[105][MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      if (i)
      dp[a[i]][i] = dp[a[i]-1][i-1]+dp[a[i]+1][i-1]+dp[a[i]][i-1];
      else dp[a[i]][i] = 1;
      dp[a[i]][i] %= mod;
    } else {
      for (int j = 1; j <= m; j++) {
        if (i)dp[j][i] = dp[j][i-1]+dp[j+1][i-1]+dp[j-1][i-1];
        else dp[j][i] = 1;
        dp[j][i] %= mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += dp[i][n-1];
    ans %= mod;
  }
  cout << ans;
  return 0;
}