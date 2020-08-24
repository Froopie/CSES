#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ll cur = 0, ans = -1e9;
  for (int i = 0; i < n; i++) {
    ll k;
    cin >> k;
    cur += k;
    ans = max(ans,cur);
    cur = max(0LL,cur);
  }
  cout << ans;
  return 0;
}