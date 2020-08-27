#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define Y first
#define X second
const int MAXN = 2e6 + 5, MAXM = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll fac[MAXN], tosub[MAXM];
pair<int,int> a[MAXM];
 
void cc() {
  fac[0] = 1;
  for (int i = 1; i <= 2e6; i++)
    fac[i] = (fac[i-1]*i)%mod;
}
 
ll po(ll a, ll p) {
  if (p == 0) return 1;
  ll x = po(a, p>>1);
  x = (x*x)%mod;
  if (p&1) x = (x*a)%mod;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cc();
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << (m==0);
    return 0;
  }
  for (int i = 0; i < m; i++)
    cin >> a[i].Y >> a[i].X, a[i].Y--, a[i].X--;
  sort(a, a+m);
  a[m] = {n-1,n-1};
  ll ans = (fac[2*n-2]*po(fac[n-1], 2*mod-4))%mod;
  for (int i = 0; i < m; i++) {
    ll &cur = tosub[i];
    ll toadd = fac[a[i].Y+a[i].X];
    toadd *= po(fac[a[i].Y], mod-2);
    toadd %= mod;
    toadd *= po(fac[a[i].X], mod-2);
    toadd %= mod;
    cur += toadd;
    cur %= mod;
    for (int j = i+1; j <= m; j++) {
      if (a[j].X < a[i].X) continue;
      ll t = fac[a[j].X-a[i].X+a[j].Y-a[i].Y];
      t *= cur; t %= mod;
      t *= po(fac[a[j].X-a[i].X], mod-2);
      t %= mod;
      t *= po(fac[a[j].Y-a[i].Y], mod-2);
      t %= mod;
      if (j == m)
      ans = ((ans-t)%mod+mod)%mod;
      tosub[j] -= t;
    }
  }
  cout << ans;
  return 0;
}