#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int occ[300];
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
  string s;
  cin >> s;
  fac[0] = 1;
  for (int i = 0; i < (int)s.size(); i++)
    fac[i+1] = (fac[i]*(i+1))%mod;
  modinv[(int)s.size()] = po(fac[(int)s.size()],mod-2);
  for (int i = (int)s.size()-1; i >= 0; i--)
    modinv[i] = ((i+1)*modinv[i+1])%mod;
  for (auto c : s)
    occ[c]++;
  ll ans = fac[(int)s.size()];
  for (int i = 'a'; i <= 'z'; i++)
    ans = (ans*modinv[occ[i]])%mod;
  cout << ans;
  return 0;
}