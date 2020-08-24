#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  bool vis[MAXN] = {};
  for (int i = 0; i < n-1; i++) {
    int k;
    cin >> k;
    vis[k] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ans = i;
  cout << ans;
  return 0;
}