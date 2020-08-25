#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
string a, b;
ll an, bn, dp[MAXN][MAXN];
 
ll rec(int i, int j) {
  if (i == an)
    return bn-j;
  if (j == bn)
    return an-i;
  ll &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = 1+min(rec(i+1,j),min(rec(i,j+1),rec(i+1,j+1)-(a[i]==b[j])));
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  an = a.size();
  bn = b.size();
  memset(dp,-1,sizeof dp);
  cout << rec(0,0);
  return 0;
}