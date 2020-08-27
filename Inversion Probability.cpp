#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 100 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, r[MAXN];
double dp[MAXN][MAXN][MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> r[i];
  double ans = 0;
  for (int i = 100; i >= 1; i--) {
    dp[i][0][n] = 1;
    for (int j = 0; j <= 100; j++)
      for (int k = n-1; k >= 0; k--) {
        double &ret = dp[i][j][k];
        if (j == 0) {
          ret = max((double)0,(r[k]-i+1)/(double)r[k]);
          ret *= dp[i][0][k+1];
        }
        else ret = max(0.,(r[k]-i+1)/(double)r[k])*dp[i][j][k+1]+min(i-1,r[k])/(double)r[k]*dp[i][j-1][k+1];
        if (r[k] >= i) ans += 1/(double)r[k]*j*dp[i][j][k+1];
      }
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}