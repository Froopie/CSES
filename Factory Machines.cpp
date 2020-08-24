#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll k[MAXN];
int n, t;
 
bool check(ll c) {
  ll tt = t;
  for (int i = 0; i < n && tt > 0; i++)
    tt -= c/k[i];
  return tt <= 0;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> k[i];
  ll l = 1, r = 1e18, ans = 1e18;
  while (l <= r) {
    ll mid = (l+r)>>1;
    if (check(mid)) {
      ans = mid;
      r = mid-1;
    } else l = mid+1;
  }
  cout << ans;
  return 0;
}