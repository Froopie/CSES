#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, dp[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int c = i;
    dp[i] = 1e9;
    while (c) {
      if (c%10 == 0) {
        c /= 10;
        continue;
      }
      dp[i] = min(dp[i],1+dp[i-c%10]);
      c /= 10;
    }
  }
  cout << dp[n];
  return 0;
}
