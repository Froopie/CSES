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
  for (int i = 0; i < n; i++)
    cin >> c[i];
  dp[0] = 1;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < x; i++)
      if (c[j]+i <= x) {
        dp[c[j]+i] += dp[i];
        dp[c[j]+i] %= mod;
      }
  cout << dp[x];
  return 0;
}