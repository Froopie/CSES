#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll n, x, ans, a, pre;
map<ll,int> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    pre += a;
    ans += mp[pre-x];
    mp[pre]++;
  }
  cout << ans;
  return 0;
}