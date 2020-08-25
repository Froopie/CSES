#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5000 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, arr[MAXN];
ll dp[2][MAXN][MAXN];
 
ll rec(bool p, int l, int r) {
  if (r < l) return 0;
  ll &ret = dp[p][l][r];
  if (ret != -1) return ret;
  if (p) return ret = min(rec(0, l+1, r), rec(0, l, r-1));
  else return ret = max(1LL*arr[l]+rec(1, l+1, r), 1LL*arr[r]+rec(1, l, r-1));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << rec(0, 0, n-1);
  return 0;
}