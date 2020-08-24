#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, a[MAXN], pre[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  pre[0] = 1e9;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<int> ve;
  for (int i = 1; i <= n; i++) {
    while (ve.size() && a[ve.back()] >= a[i])
      ve.pop_back();
    int ans = 0;
    if (ve.size()) ans = ve.back();
    cout << ans << ' ';
    ve.pb(i);
  }
  return 0;
}