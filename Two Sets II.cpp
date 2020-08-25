#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 500 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, dp[MAXN][250*501+5];
 
int rec(int i, int w) {
  if (i == n) return (n*(n+1)/4 == w && n*(n+1)/2-n*(n+1)/4 == w);
  int &ret = dp[i][w];
  if (ret != -1) return ret;
  ret = (rec(i+1, w+i)+rec(i+1, w))%mod;
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  cout << rec(1, 0);
  return 0;
}