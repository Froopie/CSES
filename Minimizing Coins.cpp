#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll n, x, dp[MAXN], c[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  fill(dp,dp+x+1,(int)1e9);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  dp[0] = 0;
  for (int i = 1; i <= x; i++)
    for (int j = 0; j < n; j++)
      if (i-c[j] >= 0)
        dp[i] = min(dp[i],dp[i-c[j]]+1);
  if (dp[x] == 1e9) dp[x] = -1;
  cout << dp[x];
  return 0;
}