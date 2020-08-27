#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll fac[MAXN];
ll modinv[MAXN];
 
ll po(ll a, ll p) {
  if (!p) return 1;
  ll x = po(a,(p>>1));
  x = (x*x)%mod;
  if ((p&1)) x = (x*a)%mod;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fac[0] = 1;
  for (int i = 0; i < MAXN-1; i++)
    fac[i+1] = (fac[i]*(i+1))%mod;
  modinv[MAXN-1] = po(fac[MAXN-1],mod-2);
  for (int i = MAXN-2; i >= 0; i--)
    modinv[i] = ((i+1)*modinv[i+1])%mod;
  int n, m;
  cin >> n >> m;
  ll ans = ((fac[n+m-1]*modinv[n-1])%mod*modinv[m])%mod;
  cout << ans;
  return 0;
}
