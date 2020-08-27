#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll po(int a) {
  if (a == 0) return 1;
  ll x = po(a/2);
  x *= x;
  x %= mod;
  return (a&1? (x*2)%mod : x);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  ll ans = n%mod;
  vector<ll> div;
  ll t = po(mod-2);
  for (ll i = 1; i*i <= n; i++) {
    div.pb(i);
    if (i*i != n) div.pb(n/i);
  }
  sort(all(div));
  for (int i = 0; i < (int)div.size()-1; i++) {
    ll p = n/div[i];
    ll d = n/div[i+1]+1;
    ans += (((p%mod+d%mod)*((((p%mod-d%mod+1+mod)%mod)*div[i])%mod))%mod)*t;
    ans %= mod;
  }
  cout << ans;
  return 0;
}
