#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int dp[MAXN];
 
void dfs(int u) {
  for (int v : ve[u]) {
    dfs(v);
    dp[u] += 1+dp[v];
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    ve[u].pb(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    cout << dp[i] << ' ';
  return 0;
}