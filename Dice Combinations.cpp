#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll n, dp[(int)1e6+10];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=dp[6]=1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 6; j++) {
      dp[i+j] += dp[i];
      dp[i+j] %= mod;
    }
  cout << dp[n];
  return 0;
}