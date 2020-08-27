#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int cc(ll a, int p) {
  if (p == 0) return 1;
  ll x = cc(a, p/2);
  x = (x*x)%mod;
  if (p&1) return (a*x)%mod;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll c[MAXN], po[MAXN];
  c[0] = 1;
  for (int i = 0; i < 1e6; i++)
    c[i+1] = (c[i]*(i+1))%mod;
  for (int i = 0; i < 1e6; i++)
    po[i] = cc(c[i], mod-2);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    ll n = (po[b]*po[a-b])%mod;
    cout << (c[a]*n)%mod << '\n';
  }
  return 0;
}